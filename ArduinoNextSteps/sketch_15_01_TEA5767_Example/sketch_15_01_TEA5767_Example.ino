// TEA5767 Example

#include <Wire.h>
#include <TEA5767Radio.h>

TEA5767Radio radio = TEA5767Radio();

void setup()
{ 
  radio.setFrequency(93.0); // pick your own frequency
}

void loop()
{
}
