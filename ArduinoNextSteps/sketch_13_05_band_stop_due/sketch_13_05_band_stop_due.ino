// sketch_13_05_band_stop_due

const long samplePeriod = 23L; // micro seconds

const int analogInPin = A0;
const int analogOutPin = DAC0;

// 1000 to 1500 band stop filter
// 44100 Hz sample rate
// http://www.schwietering.com/jayduino/filtuino/index.php?characteristic=bu&passmode=bs&order=1&usesr=usesr&sr=44100&frequencyLow=1000&noteLow=&frequencyHigh=1500&noteHigh=&pw=pw&calctype=float&run=Send

//Band stop butterworth filter order=1 alpha1=0.022675736961451 alpha2=0.034013605442177 
class filter
{
	public:
		filter()
		{
			v[0]=0.0;
			v[1]=0.0;
		}
	private:
		float v[3];
	public:
		float step(float x)
		{
			v[0] = v[1];
			v[1] = v[2];
			v[2] = (9.655920584452e-1 * x)
				 + ( -0.9311841169 * v[0])
				 + (  1.9018448769 * v[1]);
			return 
				 (v[0] + v[2])
				- 1.969615 * v[1];
		}
};


filter f;


void setup()                 
{
  // http://www.djerickson.com/arduino/
  REG_ADC_MR = (REG_ADC_MR & 0xFFF0FFFF) | 0x00020000;
  analogWriteResolution(8);
  analogReadResolution(8);
}

void loop()                   
{
  static long lastSampleTime = 0;
  long timeNow = micros();
  if (timeNow > lastSampleTime + samplePeriod)
  {
    int raw = analogRead(analogInPin);
    
    float filtered = f.step(raw);
    
    analogWrite(analogOutPin, (int)filtered);
    lastSampleTime = timeNow;
  }
}
