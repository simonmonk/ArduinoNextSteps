#include <TimerOne.h>

//http://www.schwietering.com/jayduino/filtuino/index.php?characteristic=bu&passmode=bs&order=2&usesr=usesr&sr=200&frequencyLow=49&noteLow=&frequencyHigh=51&noteHigh=&pw=pw&calctype=float&run=Send

const int analogInPin = A0;
const int analogOutPin = 9;

const byte PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
const byte PS_16 = (1 << ADPS2);


float v[5];

void setup()                 
{
  ADCSRA &= ~PS_128;  // remove prescale of 128
  ADCSRA |= PS_16;    // add prescale of 16 (1MHz)

  for(int i=0; i <= 6; i++)
  {
     v[i]=0.0;
  }
//  Timer1.initialize(10000); // uS
  Timer1.attachInterrupt(sample);
  Timer1.pwm(analogOutPin, 0, 100);
  Serial.begin(115200);
}

void loop()                   
{
}

void sample()
{
  int raw = analogRead(analogInPin);
  int smoothed = (int)(step(raw));
 // Serial.print(raw); Serial.print(","); Serial.println(smoothed);
  Timer1.setPwmDuty(analogOutPin, raw);
}

float step(float x)
{
			v[0] = v[1];
			v[1] = v[2];
			v[2] = v[3];
			v[3] = v[4];
			v[4] = (9.991118180304e-1 * x)
				 + ( -0.9982244250 * v[0])
				 + (  3.9918341618 * v[1])
				 + ( -5.9889945425 * v[2])
				 + (  3.9953827892 * v[3]);
			return 
				 (v[0] + v[4])
				- 3.997159 * v[1]
				- 3.997159 * v[3]
				+5.994319 * v[2];
}
