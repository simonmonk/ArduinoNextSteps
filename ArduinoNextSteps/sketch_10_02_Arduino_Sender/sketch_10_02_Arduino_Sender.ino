// sketch_10_02_Adruino_Sender

#include "SoftwareSerial.h"

const int readingPin = A1;
const int plusPin = A2;
const int gndPin = A0;

SoftwareSerial sender(8, 9); // RX, TX

void setup() 
{
  pinMode(gndPin, OUTPUT);
  pinMode(plusPin, OUTPUT);
  digitalWrite(plusPin, HIGH);
  sender.begin(9600);
}

void loop()
{
  int reading = analogRead(readingPin);
  byte h = highByte(reading);
  byte l = lowByte(reading);
  sender.write(h);
  sender.write(l);
  delay(1000);
}
