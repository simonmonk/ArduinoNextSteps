// sketch_-4_05_sin_print

float angle = 0.0;
float angleStep = PI / 32.0;

void setup() 
{
  Serial.begin(9600);
  Serial.print("byte sin64[] = {");
  while (angle < 2 * PI)
  {
    int x = (int)(sin(angle) * 127) + 127;
    Serial.print(x);
    angle += angleStep;
    if (angle < 2 * PI)
    {
      Serial.print(", ");
    }
  }
  Serial.println("};");
}

void loop() 
{
}
