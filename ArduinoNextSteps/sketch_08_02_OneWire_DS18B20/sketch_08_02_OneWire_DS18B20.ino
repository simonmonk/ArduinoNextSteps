// sketch_08_02_OneWire_DS18B20

#include <OneWire.h>
#include <DallasTemperature.h>

const int busPin = 10;

OneWire bus(busPin);
DallasTemperature sensors(&bus);
DeviceAddress sensor;

void setup()
{
  Serial.begin(9600);
  sensors.begin();
  if (!sensors.getAddress(sensor, 0)) 
  {
    Serial.println("NO DS18B20 FOUND!");
  }
}

void loop()
{
  sensors.requestTemperatures();
  float tempC = sensors.getTempC(sensor);
  Serial.println(tempC);
  delay(1000);
}
