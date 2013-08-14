// sketch_03_03_1kHz
#include <avr/sleep.h>
#include <avr/power.h>
#include <TimerOne.h>

NO NARCOLEPTIC LIBARAY IS THE WAY TO GO FOR THIS - THEN DELVE INTO HOW NARCOLEPTIC WORKS.

ALSO THE POWER LIBRARY.

int ledPin = 13;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  Timer1.initialize(5000000); // wake every 5 seconds 
  //Timer1.attachInterrupt(everySoOften); 
  TIMSK1=0x01;
}
 
void loop()
{
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(250000);
  digitalWrite(ledPin, LOW);
  delayMicroseconds(250000);
  
  set_sleep_mode(SLEEP_MODE_IDLE);
  sleep_enable();
  power_adc_disable();
  power_spi_disable();
  power_timer0_disable();
  power_timer2_disable();
  power_twi_disable();  
  sleep_mode();
}

//void everySoOften()
//{
//  
//}

// http://donalmorrissey.blogspot.co.uk/2011/11/sleeping-arduino-part-4-wake-up-via.html
