// sketch_06_02_static

int array[100];

void setup()
{
  array[0] = 1;
  array[50] = 2;
  Serial.begin(9600);
  Serial.println(array[50]);
}

void loop()
{
}

// 2368 bytes
