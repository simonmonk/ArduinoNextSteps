// sketch_11_05_keyboard_due

#include <KeyboardController.h>

USBHost usb;
KeyboardController keyboard(usb);

void setup()
{
  Serial.begin(9600);
  Serial.println("Program started");
  delay(200);
}

void loop()
{
  usb.Task();
}

// This function intercepts key press
void keyPressed() 
{
  char key = keyboard.getKey();
  Serial.write(key);
}
