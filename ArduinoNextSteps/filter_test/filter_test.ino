

// 300 to 3000 band stop filter
// 100 kHz sample rate
// http://www.schwietering.com/jayduino/filtuino/index.php?characteristic=bu&passmode=bs&order=2&usesr=usesr&sr=100000&frequencyLow=300&noteLow=&frequencyHigh=3000&noteHigh=&pw=pw&calctype=float&run=Send

//Band stop butterworth filter order=2 alpha1=0.003 alpha2=0.03 
class filter
{
	public:
		filter()
		{
			for(int i=0; i <= 4; i++)
				v[i]=0.0;
		}
	private:
		float v[5];
	public:
		float step(float x)
		{
			v[0] = v[1];
			v[1] = v[2];
			v[2] = v[3];
			v[3] = v[4];
			v[4] = (8.869368704884e-1 * x)
				 + ( -0.7866981284 * v[0])
				 + (  3.3285093824 * v[1])
				 + ( -5.2961761521 * v[2])
				 + (  3.7543536539 * v[3]);
			return 
				 1.000000 * v[0]
				+v[4]
				- 3.992879 * (v[1] + v[3])
				+5.985770 * v[2];
		}
};

filter f;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int r = analogRead(A0);
  float filtered = f.step(r);
  Serial.print(r); Serial.print(","); Serial.println((int)filtered);
  delay(100);
}


