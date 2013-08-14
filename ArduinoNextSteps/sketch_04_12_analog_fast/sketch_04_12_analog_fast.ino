// sketch 04_11_analog

const byte PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
const byte PS_16 = (1 << ADPS2);

void setup()
{
  ADCSRA &= ~PS_128;  // remove prescale of 128
  ADCSRA |= PS_16;    // add prescale of 16 (1MHz)
  Serial.begin(9600);
  while (! Serial) {};
  Serial.println(PS_128, 2);
  Serial.println(PS_16, 2); 
  Serial.println("Starting Test");
  long startTime = millis();
  
  // test code here
  long  i = 0;
  for (i = 0; i < 1000000; i ++)
  {
    analogRead(A0);
  }
  // end of test code
  long endTime = millis();
  
  Serial.println("Finished Test");
  Serial.print("Seconds taken: "); 
  Serial.println((endTime - startTime) / 1000l);
}

void loop()
{
}
