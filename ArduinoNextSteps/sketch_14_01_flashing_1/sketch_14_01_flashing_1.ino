// sketch_14_01_flashing_1

const int ledPin = 13;
const int switchPin = 5;
const int period = 1000;

boolean flashing = false;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP); 
}

void loop()
{
  if (digitalRead(switchPin) == LOW)
  {
    flashing = ! flashing;
  }
  if (flashing)
  {
    digitalWrite(ledPin, HIGH);
    delay(period);
    digitalWrite(ledPin, LOW);
    delay(period);
  }    
}
