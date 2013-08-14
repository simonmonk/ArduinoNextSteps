// sketch_04_06_bytes

byte outPin = 10;
byte state = 0;

void setup()
{
  pinMode(outPin, OUTPUT);
}

void loop()
{
  digitalWrite(outPin, state);
  state = ! state;
}


