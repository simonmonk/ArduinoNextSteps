// sketch_13_04_null_filter_due

const long samplePeriod = 10L; // micro seconds

const int analogInPin = A0;
const int analogOutPin = DAC0;

void setup()                 
{
  // http://www.djerickson.com/arduino/
  REG_ADC_MR = (REG_ADC_MR & 0xFFF0FFFF) | 0x00020000;
  analogWriteResolution(8);
  analogReadResolution(8);
}

void loop()                   
{
  static long lastSampleTime = 0;
  long timeNow = micros();
  if (timeNow > lastSampleTime + samplePeriod)
  {
    int raw = analogRead(analogInPin);
    analogWrite(analogOutPin, raw);
    lastSampleTime = timeNow;
  }
}

