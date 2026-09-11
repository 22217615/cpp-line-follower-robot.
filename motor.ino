void motor(int LPWM, int RPWM) {
// ----- LEFT MOTOR DIRECTION -----
  if (LPWM >= 0) {   
    digitalWrite(left_motor_forward, LOW); 
    digitalWrite(left_motor_backward, HIGH); 
  } else {
    // Backward: reverse the pin states
    digitalWrite(left_motor_forward, HIGH);
    digitalWrite(left_motor_backward, LOW);
  }
// ----- RIGHT MOTOR DIRECTION -----
  if (RPWM >= 0) {
    digitalWrite(right_motor_forward, LOW);
    digitalWrite(right_motor_backward, HIGH);
  } else {
    digitalWrite(right_motor_forward, HIGH);
    digitalWrite(right_motor_backward, LOW);
  }
  LPWM = constrain(LPWM, -255, 255); // just to say that the value of the motor will be within the range of (-255 and 255)
  RPWM = constrain(RPWM, -255, 255);
  analogWrite(left_motor_speed, abs(LPWM));  // Send the actual speed (magnitude only, direction already handled above)
  analogWrite(right_motor_speed, abs(RPWM));
}  
//note :  Positive value = forward, negative value = backward (magnitude = speed).