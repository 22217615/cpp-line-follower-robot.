#include <QTRSensors.h>  // Library for reading QTR reflectance/line sensors

// ===================== MOTOR PINS =====================
// These pins connect to the TB6612FNG motor driver.
// Each motor needs 2 direction pins (forward/backward) + 1 PWM speed pin.
#define right_motor_forward 5   // TB6612 --  BIN1 B01
#define right_motor_backward 6  // TB6612 -- BIN2 B02
#define left_motor_forward 4    // TB6612 --- AIN1 A01
#define left_motor_backward 13  // TB6612 --- AIN2 A02

// Speed control pins (PWM) 
#define left_motor_speed 3   // TB6612 --- PWMA
#define right_motor_speed 9  // TB6612 --- PWMB

// ========== SENSORS =====================
QTRSensors qtr;                 // QTR sensor array object
#define sensorNumber 6           // 6  IR sensors used for line detection
uint16_t sensorValues[sensorNumber]; // declare an array of 6 /
                                    // unit16_t means : the values of element is positive and its maximun is 65535 
int sensorADC[sensorNumber];         
int sensorDigital[sensorNumber];     // Digital (0/1) version of each sensor's reading
int threshold = 1000;                // ADC threshold used to decide black vs white
int sumOnSensor;                     // Count of how many sensors currently detect the line

// ===================== PID VARIABLES =====================
// Only P (proportional) and D (derivative) terms are used here (no integral term)
float Kp = 0.075;   // Proportional gain — reacts to current error
float Kd = 0.6;     // Derivative gain — reacts to how fast the error is changing

// ===================== BASE WHEEL SPEEDS =====================
int baseLeft = 82;
int baseRight = 80; // Right is slightly slower than left to compensate for
 // mechanical imbalance between the two wheels

int lastError = 1;      // Error value from the previous loop iteration 
int lastDirection = 1;  // remeber the last direction , used in read line and turning file
int lastSide = 0;       // last saw the line

// -------- CROSSING / GAP HANDLING ----
unsigned long lineLostTime = 0;          // Timestamp of when the line was first lost
const unsigned long straightTimeout = 150; //   keep 150ms driving straight when losing a line or gap
                                            
const unsigned long crossTimeout = 45;     // 45 ms straight through a crossing or semi-circle
unsigned long crossDetectedTime = 0;       // Timestamp of when a crossing was first detected
bool onCrossing = false;                   // Flag: are we currently handling a crossing?

char direction = 'S';        // 's' straight : when the line disappears always go straight
const int delay_before_turn = 35; // 35ms pause before executing a 90° turn

void setup() {
  Serial.begin(9600);   

  qtr.setTypeRC();       // Sensors are the RC (digital charge/discharge) type QTR sensors
  qtr.setSensorPins((const uint8_t[]){7, 8, 10, 11, 12, 2}, sensorNumber); // Assign sensor pins

  // Set motor direction pins as outputs
  pinMode(left_motor_forward, OUTPUT);
  pinMode(left_motor_backward, OUTPUT);
  pinMode(right_motor_forward, OUTPUT);
  pinMode(right_motor_backward, OUTPUT);

  // Set motor speed (PWM) pins as outputs
  pinMode(left_motor_speed, OUTPUT);
  pinMode(right_motor_speed, OUTPUT);
}

void loop() {

  read_black_line(); // Preads sensors and fills sensorADC/sensorDigital + sumOnSensor
       
  // Get the line position (0-5000 range typically, for 6 sensors) using QTRSensors library
  unsigned int position = qtr.readLineBlack(sensorValues);
  byte bitSensor = 0;
  for (int i = 0; i < sensorNumber; i++) {
    bitSensor |= (sensorDigital[i] << (sensorNumber - 1 - i));
  }


  // 2500 is the "centered" position for a 6-sensor array (range 0-5000).
  int error = position - 2500;

  // ================= CROSSING =================
  // If ALL sensors detect black, we're likely on a T intersection.
  if (sumOnSensor == sensorNumber) {

    if (!onCrossing) {
      onCrossing = true;
      crossDetectedTime = millis(); // Mark when the crossing started
    }

    // Drive straight through the crossing for a fixed short time
    if (millis() - crossDetectedTime < crossTimeout) {
      motor(baseLeft, baseRight);
      return; // Skip the rest of the loop while crossing
    }

  } else {
    onCrossing = false; // Not on a crossing anymore (or never was)
  }

  // =MEMORIZE TURN DIRECTION =

  switch (bitSensor) {

    // RIGHT patterns: line detected mostly on the right-side sensors
    case 0b110000:
    case 0b111000:
    case 0b111100:
      direction = 'R';
      break;

    // LEFT patterns: line detected mostly on the left-side sensors
    case 0b000011:
    case 0b000111:
    case 0b001111:
      direction = 'L';
      break;
  }

  //  GAP + 90° TURN 
 
  if (bitSensor == 0) {  // If NO sensor detects the line at all (bitSensor == 0), the line is "lost"

    if (lineLostTime == 0)
      lineLostTime = millis(); // Mark the moment the line was first lost

    // short gap: keep driving straight for a bit, hoping the line reappears
    if (millis() - lineLostTime < straightTimeout) {
      motor(baseLeft, baseRight);
      return;
    }

    delay(delay_before_turn); 

    
    if (direction == 'L') //excute the turn left
      turnLeft(45, 45); //same speed 
    else if (direction == 'R') //excute the rurn right 
      turnRight(45, 45);

    return;
  }
  else {
    lineLostTime = 0; // Line is visible again, reset the "lost" timer
  }

  //  NORMAL PD 
  .
  int correction = (Kp * error) + (Kd * (error - lastError)); //centralized the robot on line

  lastError = error; // Save current error for next loop's derivative calculation

  // Apply correction: speed up one wheel, slow down the other to steer back to center
  int leftMotor = baseLeft - correction;
  int rightMotor = baseRight + correction;

  motor(leftMotor, rightMotor); // Send final speeds to the motor control function

  delay(5); // Small loop delay for stability/sensor settling
}



                                                                                     


