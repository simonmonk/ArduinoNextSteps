// sketch 01_01_blink_10
int ledPin = 13;
int delayPeriod = 200;
void setup()
{
  pinMode(ledPin, OUTPUT);
}
void loop()
{
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(ledPin, HIGH);
    delay(delayPeriod);
    digitalWrite(ledPin, LOW);
    delay(delayPeriod);
  }
}

