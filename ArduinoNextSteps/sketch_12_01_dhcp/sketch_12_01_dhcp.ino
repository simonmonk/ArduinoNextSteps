// sketch_12_01_dhcp

#include <SPI.h>
#include <Ethernet.h>


byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 };

void setup() 
{
  Serial.begin(9600);
  while (!Serial){};

  if (Ethernet.begin(mac)) 
  {
    Serial.println(Ethernet.localIP());
  }
  else
  {
    Serial.println("Could not connect to network");
  }
}

void loop() 
{
}


