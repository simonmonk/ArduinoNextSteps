// sketch_06_07_avr_eeprom_int

#include <avr/eeprom.h>

void setup()
{
  int i = eeprom_read_word((uint16_t*)10);
  i++;
  eeprom_write_word((uint16_t*)10, i);
  Serial.begin(9600);
  Serial.println(i);
}

void loop()
{
}
