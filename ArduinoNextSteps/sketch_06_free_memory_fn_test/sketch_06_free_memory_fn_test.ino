#include <MemoryFree.h>

void setup() 
{
    Serial.begin(115200);
}

void loop() 
{
    Serial.print("freeMemory()=");
    Serial.println(freeMemory());
    delay(1000);
}
