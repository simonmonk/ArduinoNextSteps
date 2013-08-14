// sketch_14_03_flashing_3

#include <Timer.h>


const int ledPin = 13;
const int switchPin = 5;
const int period = 1000;

boolean flashing = false;
int ledState = LOW;
Timer t;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP); 
  t.every(period, flashIfRequired);
}

void loop()
{
  if (digitalRead(switchPin) == LOW)
  {
    flashing = ! flashing;
    if (! flashing)
    {
      digitalWrite(ledPin, LOW);
    }
  }
  t.update();
}

void flashIfRequired()
{
  if (flashing)
  {
    ledState = ! ledState;
    digitalWrite(ledPin, ledState);
  }   
}
