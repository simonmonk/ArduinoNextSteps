// sketch_04_05_square

int outPin = 10;
int state = 0;

void setup()
{
  pinMode(outPin, OUTPUT);
}

void loop()
{
  digitalWrite(outPin, state);
  state = ! state;
}


