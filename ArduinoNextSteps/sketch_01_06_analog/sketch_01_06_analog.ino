// sketch 01_06_analog
int analogPin = A0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int rawReading = analogRead(analogPin);
  float volts = rawReading / 204.6;
  Serial.println(volts);
  delay(1000);
}

