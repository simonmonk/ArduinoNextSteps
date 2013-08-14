// sketch_07_01_I2C_TEA5767

#include <Wire.h>

void setup()
{
  Wire.begin();
  setFrequency(93.0); // MHz
}

void loop()
{
}

void setFrequency(float frequency)
{
  unsigned int frequencyB = 4 * (frequency * 1000000 + 225000) / 32768; 
  byte frequencyH = frequencyB >> 8;
  byte frequencyL = frequencyB & 0XFF;

  Wire.beginTransmission(0x60); 
  Wire.write(frequencyH);
  Wire.write(frequencyL);
  Wire.write(0xB0);
  Wire.write(0x10);
  Wire.write(0x00);
  Wire.endTransmission();
  delay(100);  
}
 
