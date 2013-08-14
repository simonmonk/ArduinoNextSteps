// sketch_06_07_avr_eeprom_string_read

#include <avr/eeprom.h>

void setup()
{
  char message[50]; // big enough
  eeprom_read_block(&message, (void *)100, 50);
  Serial.begin(9600);
  Serial.println(message);
  Serial.println(strlen(message));
}

void loop()
{
}
