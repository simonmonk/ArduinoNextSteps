// sketch_11_06_mouse_due

#include <MouseController.h>

USBHost usb;
MouseController mouse(usb);

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

// This function intercepts mouse movements
void mouseMoved() 
{
  int x = mouse.getXChange();
  int y = mouse.getYChange();
  if (x > 50) Serial.print("R");
  if (x < -50) Serial.print("L");
  if (y > 50) Serial.print("D");
  if (y < -50) Serial.print("U");  
}
