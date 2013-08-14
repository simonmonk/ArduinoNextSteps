// sketch_05_04_narcoleptic_blink
#include <Narcoleptic.h>

void setup() 
{
  pinMode(13, OUTPUT);
}

void loop() 
{
  digitalWrite(13, HIGH);
  Narcoleptic.delay(1000);
  digitalWrite(13, LOW);
  Narcoleptic.delay(10000);
}
