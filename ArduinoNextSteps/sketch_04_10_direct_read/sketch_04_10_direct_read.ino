// sketch_04_010_direct_read

byte state = 0;

void setup()
{
  DDRB = B00000000; // all inputs
  Serial.begin(9600);
}

void loop()
{
  Serial.println(PINB, 2);
  delay(1000);
}


