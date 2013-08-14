// sketch_06_EEPROM_example

#include <EEPROM.h>

const int lockPin = 13;
const byte codeSetMarkerValue = 123;
const int defaultCode = 1234;

int code;
boolean locked = true;

void setup()
{
  pinMode(lockPin, OUTPUT);
  Serial.begin(9600);
  while (! Serial) {}; // Wait for Serial to start (Leonardo only)
  lock();
  Serial.println("Enter the command U followed by code to unlock");
  Serial.println("and L to lock again.");
  Serial.println("Use the command C followed by a new code to change the code");
  initializeCode();
}

void loop()
{
  if (Serial.available())
  {
    char command = Serial.read();
    if (command == 'U')
    {
      attemptUnlock();
    }
    else if (command == 'L')
    {
      lock();
    }
    else if (command == 'C')
    {
      if (locked)
      {
        Serial.println("Can only set new code when unlocked");
      }
      else
      {
        changeCode();
      }
    }
  }
}

void initializeCode()
{
  byte codeSetMarker = EEPROM.read(0);
  if (codeSetMarker == codeSetMarkerValue)
  {
    code = readSecretCodeFromEEPROM();
  }
  else
  {
    code = defaultCode;
  }
}

int readSecretCodeFromEEPROM()
{
  byte high = EEPROM.read(1);
  byte low = EEPROM.read(2);
  return (high << 8) + low;
}

void saveSecretCodeToEEPROM()
{
  EEPROM.write(0, codeSetMarkerValue);
  EEPROM.write(1, highByte(code));
  EEPROM.write(2, lowByte(code));
}

void attemptUnlock()
{
  if (code == Serial.parseInt())
  {
    unlock();
  }
  else
  {
    Serial.println("Incorrect code");
  }
}

void lock()
{
  locked = true;
  Serial.println("LOCKED");
  digitalWrite(lockPin, LOW);
}

void unlock()
{
  locked = false;
  Serial.println("UN-LOCKED");
  digitalWrite(lockPin, HIGH);
}

void changeCode()
{
  code = Serial.parseInt();
  saveSecretCodeToEEPROM();
  Serial.print("Code Changed to:");
  Serial.println(code);
}
