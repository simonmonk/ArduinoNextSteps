// sketch_10_01_PC_to_Arduino

const int readingPin = A0;

boolean sendReadings = true;

void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch == 'g')
    {
      sendReadings = true;
    }
    else if (ch == 's')
    {
      sendReadings = false;
    }
  }
  if (sendReadings)
  {
    int reading = analogRead(readingPin);
    Serial.println(reading);
    delay(1000);
  }
}

