// sketch_13_03_null_filter_uno

#include <TimerOne.h>

const int analogInPin = A0;
const int analogOutPin = 9;

void setup()                 
{
  Timer1.attachInterrupt(sample);
  Timer1.pwm(analogOutPin, 0, 100);
}

void loop()                   
{
}

void sample()
{
  int raw = analogRead(analogInPin);
  Timer1.setPwmDuty(analogOutPin, raw);
}
