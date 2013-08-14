// sketch_03_04_pwm

#include <TimerOne.h>


void setup() 
{
  pinMode(9, OUTPUT);   
  pinMode(10, OUTPUT);   
  Timer1.initialize(1000);
  Timer1.pwm(9, 512); 
  Timer1.pwm(10, 255); 
}
 
void loop()
{
}


