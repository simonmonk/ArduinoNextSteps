// sketch 01_07_pwm
int pwmPin = 6;

void setup()
{
  pinMode(pwmPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    int dutyCycle = Serial.parseInt(); 
    analogWrite(pwmPin, dutyCycle);
  }
}

