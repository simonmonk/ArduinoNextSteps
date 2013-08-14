// sketch 04_02_benchmark_float

void setup()
{
  Serial.begin(9600);
  while (! Serial) {};
  Serial.println("Starting Test");
  long startTime = millis();
  
  // test code here
  long  i = 0;
  float j = 0.0;
  for (i = 0; i < 20000000; i ++)
  {
    j = i + i * 10.0;
    if (j > 10) j = 0.0;
  }
  // end of test code
  long endTime = millis();
  
  Serial.println(j); // prevent loop being optimized out
  Serial.println("Finished Test");
  Serial.print("Seconds taken: "); 
  Serial.println((endTime - startTime) / 1000l);
}

void loop()
{
  
}
