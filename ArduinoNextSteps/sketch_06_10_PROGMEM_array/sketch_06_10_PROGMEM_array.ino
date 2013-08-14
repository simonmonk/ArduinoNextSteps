// sketch_06_10_PROGMEM_array

#include <avr/pgmspace.h>

PROGMEM int value[] = {10, 20, 25, 25, 20, 10};

void setup() 
{
  Serial.begin(9600);
  for (int i = 0; i < 6; i++)
  {
    int x = pgm_read_word(&value[i]);
    Serial.println(x);
  }
}

void loop() 
{
}
