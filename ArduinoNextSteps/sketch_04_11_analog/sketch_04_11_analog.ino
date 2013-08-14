// sketch 04_11_analog

void setup()
{
  Serial.begin(9600);
  while (! Serial) {};
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
