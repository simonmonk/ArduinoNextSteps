// sketch_04_07_const

const byte outPin = 10;
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


