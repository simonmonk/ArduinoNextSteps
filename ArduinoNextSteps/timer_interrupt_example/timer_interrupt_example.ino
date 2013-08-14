#include <TimerOne.h>

double v[11];
 
void setup() 
{
  // Initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards
  pinMode(12, OUTPUT);    
  initFilter();
  Serial.begin(115200);
  Timer1.initialize(5000); 
  Timer1.attachInterrupt( timerIsr ); // attach the service routine here
}
 
void loop()
{
  // Main code loop
  // TODO: Put your regular (non-ISR) logic here
}
 
/// --------------------------
/// Custom ISR Timer Routine
/// --------------------------
void timerIsr()
{
    digitalWrite(12, HIGH);
    int raw = analogRead(A0);
    double input = (double)raw;
    double filtered = filterStep(input);
    Serial.print(input);
    Serial.print(" ");
    Serial.println(filtered);
    digitalWrite(12, LOW);
}

// Sample f 200Hz, band stop 49-50Hz
// http://www.schwietering.com/jayduino/filtuino/index.php?characteristic=bu&passmode=bs&order=3&usesr=usesr&sr=200&frequencyLow=47&noteLow=&frequencyHigh=53&noteHigh=&pw=pw&calctype=double&run=Send
// Band stop butterworth filter order=3 alpha1=0.235 alpha2=0.265
void initFilter()
{
  for(int i=0; i <= 10; i++)
  {
    v[i]=0.0;
  }
}


double filterStep(double x)
{
			v[0] = v[1];
			v[1] = v[2];
			v[2] = v[3];
			v[3] = v[4];
			v[4] = v[5];
			v[5] = v[6];
			v[6] = (8.27971295622e-1 * x)
				 + ( -0.6855359773 * v[0])
				 + ( -0.0000000000 * v[1])
				 + ( -2.3146825811 * v[2])
				 + ( -0.0000000000 * v[3])
				 + ( -2.6235518066 * v[4])
				 + ( -0.0000000000 * v[5]);
			return 
				 (v[0] + v[6])
				+3 * (v[2] + v[4]);
}


