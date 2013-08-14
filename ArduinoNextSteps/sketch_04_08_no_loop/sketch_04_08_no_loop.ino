// sketch_04_08_no_loop

const byte outPin = 10;
byte state = 0;

void setup()
{
  pinMode(outPin, OUTPUT);
  while (true)
  {
    digitalWrite(outPin, state);
    state = ! state;
  }
}

void loop()
{
}


