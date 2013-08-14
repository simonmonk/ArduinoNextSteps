// sketch_13_01_averaging

const int samplePin = A1;

const int bufferSize = 10;
int buffer[bufferSize];
int index;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int reading = analogRead(samplePin);
  addReading(reading);
  Serial.println(average());
  delay(1000);
}

void addReading(int reading)
{
  buffer[index] = reading;
  index++;
  if (index >= bufferSize) index = 0;
}

int average()
{
  long sum = 0;
  for (int i = 0; i < bufferSize; i++)
  {
    sum += buffer[i];
  }
  return (int)(sum / bufferSize);
}
