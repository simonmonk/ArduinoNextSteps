// sketch_06_07_avr_eeprom_string

#include <avr/eeprom.h>

void setup()
{
  char message[] = "I am written in EEPROM";
  eeprom_write_block(message, (void *)100, strlen(message) + 1);
}

void loop()
{
}
