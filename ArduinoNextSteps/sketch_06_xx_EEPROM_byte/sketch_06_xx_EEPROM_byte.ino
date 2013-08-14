// sketch_06_0todo_EEPRROM_byte

#include <EEPROM.h>

void setup()
{
  byte valueToSave = 123;
  EEPROM.write(0, valueToSave);
}

void loop()
{
}
