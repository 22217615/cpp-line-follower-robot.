
void turnRight(int L, int R) //right turn 
{
  while (true)
  {
    motor(L, -R); 

    read_black_line();
   // Stop turning once either of the two middle sensors sees the line again
    if (sensorDigital[2] == 1 || sensorDigital[3] == 1)
    {
      direction ='S'; // Reset remembered direction back to "straight" now that we've re-aligned
      break;
    }
  }
}

void turnLeft(int L, int R) // left turn 
{
  while (true)
  {
    motor(-L, R);

    read_black_line();
     // Same stopping condition as turnRight(): line reacquired on center sensors

    if (sensorDigital[2] == 1 || sensorDigital[3] == 1)
    {
      direction = 'S';
      break;
    }
  }
} 