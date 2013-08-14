// sketch_06_02_factorial

void setup()
{
  Serial.begin(9600);
  Serial.println(factorial(15));
}

void loop()
{
}

long factorial(long n)
{
  if (n == 0) 
  {
    return 1;
  }
  else
  {
    return n * factorial(n - 1);
  }
}
