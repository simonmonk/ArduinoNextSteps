// sketch_13_07_FFT_Freq

#include "fix_fft.h"

const int analogPin = A0;
const long GAIN = 2;
char im[128];
char data[128];

const byte PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
const byte PS_16 = (1 << ADPS2);


void setup()
{
  Serial.begin(9600);
  ADCSRA &= ~PS_128;  // remove prescale of 128
  ADCSRA |= PS_16;    // add prescale of 16 (1MHz)
}

void loop()
{
  sampleWindowFull();
  fix_fft(data, im, 7, 0);
  updateData();

  Serial.println(findF());
}

void sampleWindowFull()
{
  for (int i = 0; i < 128; i++)
  {                               
    int val = (analogRead(analogPin) - 512) * GAIN;                       
    data[i] = val / 4;               
    im[i] = 0;     
  }
}

void updateData()
{
  for (int i = 0; i < 64; i++)
  {
    data[i] = sqrt(data[i] * data[i] + im[i] * im[i]); 
  }
}

int findF()
{
  int maxValue = 0;
  int maxIndex = 0;
  for (int i = 1; i < 64; i++)
  {
    int p = data[i];
    if (p > maxValue)
    {
      maxValue = p;
      maxIndex = i;
    }
  }
  int f = maxIndex * 240;
  return f;
}
