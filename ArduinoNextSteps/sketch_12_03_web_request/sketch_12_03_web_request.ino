
// sketch_12_03_web_request

#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 };

EthernetClient client;

void setup() 
{
  Serial.begin(9600);
  while (!Serial){}; // for Leonardo compatability

  if (! Ethernet.begin(mac)) 
  {
    Serial.println("Could not connect to network");
  }
  delay(1000);
  hitWebPage();
}

void loop() 
{
}

void hitWebPage()
{
  if (client.connect("api.openweathermap.org", 80))
  {
    client.println("GET /data/2.5/weather?q=Manchester,uk HTTP/1.0");
    client.println();
    while (client.connected())
    {
      if (client.available())
      {
        client.findUntil("description\":\"", "\0");
        String description = client.readStringUntil('\"');
        Serial.println(description);
      }
    }
    client.stop();
  }
}
