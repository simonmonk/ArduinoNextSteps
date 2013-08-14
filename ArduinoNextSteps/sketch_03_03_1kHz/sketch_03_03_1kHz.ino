// sketch_03_03_1kHz

#include <TimerOne.h>

int outputPin = 12;
volatile int output = LOW;

void setup() 
{
  pinMode(12, OUTPUT);    
  Timer1.initialize(500); 
  Timer1.attachInterrupt(toggleOutput); 
}
 
void loop()
{
}

void toggleOutput()
{
  digitalWrite(outputPin, output);
  output = ! output;
}
