// sketch_05_01_prescale

#include <Prescaler.h>

void setup() 
{
  pinMode(13, OUTPUT);
  setClockPrescaler(CLOCK_PRESCALER_256);
}

void loop() 
{
  digitalWrite(13, HIGH);
  trueDelay(1000);
  digitalWrite(13, LOW);
  trueDelay(5000);
}
