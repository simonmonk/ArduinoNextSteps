// sketch_08_03_OneWire_DS18B20_2

#include <OneWire.h>
#include <DallasTemperature.h>

const int busPin = 10;

OneWire bus(busPin);
DallasTemperature sensors(&bus);
DeviceAddress sensor1;
DeviceAddress sensor2;

void setup()
{
  Serial.begin(9600);
  sensors.begin();
  if (!sensors.getAddress(sensor1, 0)) 
  {
    Serial.println("DS18B20 NUMBER 1 NOT FOUND!");
  }
  if (!sensors.getAddress(sensor2, 1)) 
  {
    Serial.println("DS18B20 NUMBER 2 NOT FOUND!");
  }
}

void loop()
{
  sensors.requestTemperatures();
  float tempC1 = sensors.getTempC(sensor1);
  float tempC2 = sensors.getTempC(sensor2);
  Serial.print(tempC1);
  Serial.print(" ");
  Serial.println(tempC2);
  delay(1000);
}
