// sketch_-4_03_sin

void setup() 
{
  
}

float angle = 0.0;
float angleStep = PI / 32.0;

void loop() 
{
  int x = (int)(sin(angle) * 127) + 127;
  analogWrite(DAC0, x);
  angle += angleStep;
  if (angle > 2 * PI)
  {
    angle = 0.0;
  }
}
