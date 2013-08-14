// sketch_11_01_keyboard

// Leonardo, Micro or Due required.

char phrase[] = "secretpassword";

void setup()
{
  Keyboard.begin();
  delay(5000);
  Keyboard.println(phrase);
}

void loop()
{
}
