// sketch 03_02_interrupt_flash

int ledPin = 13;
volatile boolean flashFast = false;

void setup()
{
  pinMode(ledPin, OUTPUT);
  attachInterrupt(0, stuffHapenned, FALLING);
}

void loop()
{
  int period = 1000;
  if (flashFast) period = 100;
  digitalWrite(ledPin, HIGH);
  delay(period);
  digitalWrite(ledPin, LOW);
  delay(period);
}

void stuffHapenned()
{
  flashFast = ! flashFast;
}
