// sketch_04_09_square_ports

byte state = 0;

void setup()
{
  DDRB = B00000100;
  while (true)
  {
    PORTB = B00000100;
    PORTB = B00000000;
  }
}

void loop()
{
}


