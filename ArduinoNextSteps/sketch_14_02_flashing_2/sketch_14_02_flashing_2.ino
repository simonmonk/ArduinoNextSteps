// sketch_14_02_flashing_2

const int ledPin = 13;
const int switchPin = 5;
const int period = 1000;

boolean flashing = false;
long lastChangeTime = 0;
int ledState = LOW;

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
    // and turn the LED off
    if (! flashing)
    {
      digitalWrite(ledPin, LOW);
    }
  }
  long now = millis();
  if (flashing && now > lastChangeTime + period)
  {
    ledState = ! ledState;
    digitalWrite(ledPin, ledState);
    lastChangeTime = now;
  }    
}
