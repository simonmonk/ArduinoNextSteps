// sketch_05_02_powering_off

#include <avr/power.h>

void setup() 
{
  pinMode(13, OUTPUT);
//  power_adc_disable();
  power_spi_disable();
//  power_twi_disable();
//  power_usart0_disable();
//  power_timer0_disable();
//  power_timer1_disable();
//  power_timer2_disable();
//  power_all_disable();
}

void loop() 
{
}
