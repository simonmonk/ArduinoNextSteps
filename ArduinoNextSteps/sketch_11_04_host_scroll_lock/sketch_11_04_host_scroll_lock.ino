// sketch_11_04_host_scroll_lock

// This sketch is based on the LCDlbd example sketch from the USB_Host_Shield library

#include <Spi.h>
#include <Max3421e.h>
#include <Usb.h>


/* keyboard data taken from configuration descriptor */
#define KBD_ADDR        1
#define KBD_EP          1
#define KBD_IF          0
#define EP_MAXPKTSIZE   8
#define EP_POLL         0x0a

/**/
EP_RECORD ep_record[ 2 ];  //endpoint record structure for the keyboard

char buf[ 8 ] = { 0 };      //keyboard buffer
char old_buf[ 8 ] = { 0 };  //last poll

char leds = 0;


MAX3421E Max;
USB Usb;

void setup() {
  // set up the LCD's number of rows and columns: 
  Serial.begin( 9600 );
  Serial.println("Start");
  Max.powerOn();
  delay( 200 );
}

void loop() {
    Max.Task();
    Usb.Task();
    if( Usb.getUsbTaskState() == USB_STATE_CONFIGURING ) {  //wait for addressing state
        kbd_init();
        Usb.setUsbTaskState( USB_STATE_RUNNING );
    }
    if( Usb.getUsbTaskState() == USB_STATE_RUNNING ) {  //poll the keyboard  
        toggleLEDs();
        delay(500);
    }
}
/* Initialize keyboard */
void kbd_init( void )
{
  byte rcode = 0;  //return code
  ep_record[ 0 ] = *( Usb.getDevTableEntry( 0,0 ));  //copy endpoint 0 parameters
  ep_record[ 1 ].MaxPktSize = EP_MAXPKTSIZE;
  ep_record[ 1 ].Interval  = EP_POLL;
  ep_record[ 1 ].sndToggle = bmSNDTOG0;
  ep_record[ 1 ].rcvToggle = bmRCVTOG0;
  Usb.setDevTableEntry( 1, ep_record );              //plug kbd.endpoint parameters to devtable
  /* Configure device */
  rcode = Usb.setConf( KBD_ADDR, 0, 1 );                    
  if( rcode ) {
      Serial.print("Error attempting to configure keyboard. Return code :");
      Serial.println( rcode, HEX );
      while(1);  //stop
  }
  /* Set boot protocol */
  rcode = Usb.setProto( KBD_ADDR, 0, 0, 0 );
  if( rcode ) {
      Serial.print("Error attempting to configure boot protocol. Return code :");
      Serial.println( rcode, HEX );
      while( 1 );  //stop
  }
  Serial.println("Keyboard initialized");
  delay(2000);
}


void toggleLEDs( void )
{
  if (leds == 0) {
    leds = 0b00000111;
  }
  else {
    leds = 0;
  }
  Usb.setReport( KBD_ADDR, 0, 1, KBD_IF, 0x02, 0, &leds );
}



