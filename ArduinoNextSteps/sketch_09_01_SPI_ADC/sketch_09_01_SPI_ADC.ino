// sketch_09_01_SPI_ADC

#include <SPI.h>

const int chipSelectPin = 10;

void setup() 
{
  Serial.begin(9600);
  SPI.begin();
  pinMode(chipSelectPin, OUTPUT);
  digitalWrite(chipSelectPin, HIGH);
}

void loop()
{
  int reading = readADC(0);
  Serial.println(reading);
  delay(1000);
}

int readADC(byte channel)
{
  unsigned int configWord = 0b11000 | channel;
  byte configByteA = (configWord >> 1);
  byte configByteB = ((configWord & 1) << 7);
  digitalWrite(chipSelectPin, LOW);
  SPI.transfer(configByteA);
  byte readingH = SPI.transfer(configByteB);
  byte readingL = SPI.transfer(0);
  digitalWrite(chipSelectPin, HIGH);

  printByte(readingH);
  printByte(readingL);

  int reading = ((readingH & 0b00011111) << 5) + ((readingL & 0b11111000) >> 3);
  
  return reading;
}

void printByte(byte b)
{
  for (int i = 7; i >= 0; i--)
  {
     Serial.print(bitRead(b, i));
  }
  Serial.print(" ");
}

