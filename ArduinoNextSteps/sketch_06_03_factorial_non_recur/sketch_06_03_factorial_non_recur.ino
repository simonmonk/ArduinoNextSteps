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
  long result = 1;
  while (n > 0)
  {
    result = result * n;
    n--;
  }
  return result;
}
