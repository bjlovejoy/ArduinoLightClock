#include <Wire.h>
#include <SPI.h>

#include "libraries/Inc/ArduinoClock.h"

/*
#include "ArduinoClock.h"
#include "Buzzer.h"
#include "LED.h"
#include "MyRemote.h"
#include "OLED.h"
#include "RTCModule.h"
#include "SevenSeg.h"
#include "TempHumidity.h"
#include "Alarm.h"
*/
/*
#include "TM1637Display.h"      //Now in SevenSeg
#include "RTClib.h"             //Now in RTCModule

#include "allFunctions.h"       //Now in 
#include "LEDfunctions.h"       //Now in 
#include "IRremote.h"           //Now in 

#include "Adafruit_GFX.h"       //Now in 
#include "Adafruit_SSD1306.h"   //Now in 
*/


void setup()
{
  Serial.begin(9600);
  delay(2000);


  /*
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))  // Address 0x3C for 128x64
  {
    Serial.println(F("SSD1306 allocation failed"));
    errorLED = true;
    while(true)  // Don't proceed, loop forever
    {
      digitalWrite(red, errorLED);
      errorLED = !errorLED;
      delay(200);
    }
  }
  display.clearDisplay();
  display.drawBitmap(0, 0, lovejoy_inventions_bitmap, 128, 64, 1);
  display.display();
  delay(2000);
*/

  
}





void loop()
{
/*
 * Must consist of reading time, IR and infrared input to enter programming or set alarms
 * Msut not constantly print to screen or 4 digit display or set LED state (only once)
 * Capacitive sensor input only needed when alarm goes off (all other input through IR)
 */
}
