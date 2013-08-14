// sketch_10_03_Adruino_Receiver

#include "SoftwareSerial.h"

const int ledPin = 13;
int reading = 0;
SoftwareSerial receiver(8, 9); // RX, TX

void setup() 
{
  pinMode(ledPin, OUTPUT);
  receiver.begin(9600);
}

void loop()
{
  if (receiver.available() > 1)
  {
    byte h = receiver.read();
    byte l = receiver.read();
    reading = (h << 8) + l;
  }
  flash(reading);
}

void flash(int rate)
{
  // 0  slow 1023 very fast
  int period = (50 + (1023 - rate) / 4);
  digitalWrite(ledPin, HIGH);
  delay(period);
  digitalWrite(ledPin, LOW);
  delay(period);
}
