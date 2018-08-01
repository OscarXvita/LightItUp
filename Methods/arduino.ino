/* 
This script can be used with arduino uno and MAX485
*/

/*-----( Import needed libraries )-----*/
#include <CustomSoftwareSerial.h>
/*-----( Declare Constants and Pin Numbers )-----*/
#define SSerialRX        10  //Serial Receive pin
#define SSerialTX        11  //Serial Transmit pin

#define SSerialTxControl 3   //RS485 Direction control

#define RS485Transmit    HIGH
#define RS485Receive     LOW

#define Pin13LED         13
/*-----( Declare objects )-----*/

#include <CustomSoftwareSerial.h>
#include <string.h>
CustomSoftwareSerial* customSerial;               // Declare serial
byte const powerOn[] =  {0x68,0x99,0x99,0x99,0x99,0x99,0x99,0x68,0x1C,0x10,0x33,0x33,0x33,0x33,0x74,0x74,0x74,0x74,0x4F,0xDD,0x33,0x33,0x33,0x33,0x33,0x33,0x8C,0x16,0x00};
byte const powerOff[] = {0x68,0x99,0x99,0x99,0x99,0x99,0x99,0x68,0x1C,0x10,0x33,0x33,0x33,0x33,0x74,0x74,0x74,0x74,0x4D,0xDD,0x33,0x33,0x33,0x33,0x33,0x33,0x8A,0x16,0x00};
// Init value
void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.write("Hello World");

  customSerial = new CustomSoftwareSerial(SSerialRX, SSerialTX); // rx, tx
  customSerial->begin(2400, CSERIAL_8E1);         // Baud rate: 9600, configuration: CSERIAL_8N1
  Serial.print(strlen(powerOff));
  customSerial->write(powerOff, strlen(powerOff));            // Write test data
}
bool mode = true;
void loop() {
  if(mode)
    customSerial->write(powerOff, strlen(powerOff));            // Write test data
  else
    customSerial->write(powerOn, strlen(powerOn));
    /*
  if (customSerial->available())
    Serial.write(customSerial->read());
  if (Serial.available())
    customSerial->write(Serial.read());*/
  mode = !mode;
  Serial.print(mode);
  delay(10000);
}
/*-----( Declare User-written Functions )-----*/

//NONE
//*********( THE END )***********
