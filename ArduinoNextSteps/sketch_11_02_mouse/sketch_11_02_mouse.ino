// sketch_11_02_mouse

// Leonardo, Micro or Due required.

void setup()
{
  Mouse.begin();
}

void loop()
{
  int x = random(61) - 30;
  int y = random(61) - 30;
  Mouse.move(x, y);
  delay(50);
}
