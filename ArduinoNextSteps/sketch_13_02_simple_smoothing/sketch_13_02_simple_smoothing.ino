// sketch_13_02_simple_smoothing
const int samplePin = A1;
const float alpha = 0.9;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  static float smoothedValue = 0.0;
  float newReading = (float)analogRead(samplePin);
  smoothedValue = (alpha * smoothedValue) + ((1 - alpha) * newReading);
  Serial.print(newReading); Serial.print(",");
  Serial.println(smoothedValue);
  delay(1000);
}

