// sketch_05_05_narcoleptic_input
#include <Narcoleptic.h>

const int ledPin = 13;
const int inputPin = 2;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT_PULLUP);
}

void loop() 
{
  if (digitalRead(inputPin) == LOW)
  {
    doSomething();
  }
  Narcoleptic.delay(100);
}

void doSomething()
{
  for (int i = 0; i < 20; i++)
  {
    digitalWrite(ledPin, HIGH);
    Narcoleptic.delay(200);
    digitalWrite(ledPin, LOW);
    Narcoleptic.delay(200);
  }
}
