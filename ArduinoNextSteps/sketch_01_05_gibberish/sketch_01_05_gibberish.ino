// sketch 01_05_gibberish

char* messages[] = {
               "My name is Arduino", 
               "Buy books by Simon Monk", 
               "Make something cool with me",
               "Raspberry Pis are fruity"};
               
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int delayPeriod = random(2000, 8000);
  delay(delayPeriod);
  int messageIndex = random(4);
  Serial.println(messages[messageIndex]);
}
