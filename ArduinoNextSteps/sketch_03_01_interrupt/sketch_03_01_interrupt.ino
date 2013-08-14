// sketch 03_01_interrupts

int ledPin = 13;

void setup()
{
  pinMode(ledPin, OUTPUT);
  attachInterrupt(0, stuffHapenned, FALLING);
}

void loop()
{
}

void stuffHapenned()
{
  digitalWrite(ledPin, HIGH);
}
