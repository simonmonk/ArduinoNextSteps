// sketch_08_01_OneWire_List

#include <OneWire.h>

OneWire bus(10);

void setup()
{
  Serial.begin(9600);
  byte address[8]; // 64 bits
  while (bus.search(address))
  {
    for(int i = 0; i < 7; i++) 
    {
      Serial.print(address[i], HEX);
      Serial.print(" ");
    }
    // checksum OK or Fail
    if (OneWire::crc8(address, 7) == address[7])
    {
      Serial.println(" CRC OK");
    }
    else
    {
      Serial.println(" CRC FAIL");
    }
  }
}

void loop()
{
}
