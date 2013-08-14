// sketch_05_07_light_sensing

const int inputPin = A0;
const int powerPin = 12;

void setup() 
{
  pinMode(powerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  Serial.println(takeReading());
  delay(500);
}

int takeReading()
{
  digitalWrite(powerPin, HIGH);
  delay(10); // photoresistors are slow to respond
  int reading = analogRead(inputPin);
  digitalWrite(powerPin, LOW);
  return reading;
}
