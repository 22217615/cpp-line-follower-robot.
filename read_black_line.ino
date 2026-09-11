void read_black_line() {
    qtr.read(sensorValues);
  sumOnSensor = 0;
  
  for (int i = 0; i < sensorNumber; i++) {
    sensorADC[i] = sensorValues[i];// let converse the values
    // set the values to 0 and 1 ; O for the white and 1 the black
    if (sensorADC[i] > threshold)
      sensorDigital[i] = 1;  // differentiate a black and white line  
    else
      sensorDigital[i] = 0;
    sumOnSensor += sensorDigital[i];
  }

  if (sumOnSensor > 0) {  //this line says if the line is detect 
    if (sensorDigital[sensorNumber-1] == 1) lastSide = -1; //if a black line is decteced or existe in the sensors  the last side of the sensor is -1
    else if (sensorDigital[0] == 1) lastSide = 1;   // else lastside=1 ; this will be used for turning
  }
}
