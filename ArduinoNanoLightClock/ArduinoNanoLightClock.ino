#include <Wire.h>
#include <SPI.h>

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
*/

#include "Adafruit_GFX.h"       //Now in 
#include "Adafruit_SSD1306.h"   //Now in 
//___________________________________________________________________________________________________________________________________________
//4-Digit Display module ******************************************************************************************************************
//___________________________________________________________________________________________________________________________________________
//RTC module (D -> SDA , C - SCL , NC -> No connection -> GND) ****************************************************************************
//___________________________________________________________________________________________________________________________________________
//OLED Display ****************************************************************************************************************************
//___________________________________________________________________________________________________________________________________________
//IR remote and receiver ******************************************************************************************************************
//___________________________________________________________________________________________________________________________________________
//LED pins ********************************************************************************************************************************
//___________________________________________________________________________________________________________________________________________
//Other input and output pins *************************************************************************************************************
//___________________________________________________________________________________________________________________________________________








void setup()
{
  Serial.begin(9600);
  delay(2000);

  //4-Digit Display module


  //RTC module


  //OLED Display


  //IR remote and receiver


  //LEDs


  //Other input and output pins
  

  //Initialize the rtc module


  //initialize the OLED display and display Logo

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
  screen.setTextSize(1);      // Normal 1:1 pixel scale
  screen.setTextColor(WHITE); // Draw white text
  screen.cp437(true);         // Use full 256 char 'Code Page 437' font
  screen.setCursor(15, 0);     // Start at top-left corner

  delay(500);
  screen.clearDisplay();
  screen.writeFillRect(0, 11, 128, 2, 1);
  screen.print(F("Programming Mode"));
  screen.setCursor(0, 16);
  screen.print(F("1) Alarms"));
  
  //rotate through based on remote input to highlight with reactangle and change color
  //try 5 sets of if/else statements
  screen.setCursor(0, 25);
  screen.setTextColor(BLACK);
  screen.writeFillRect(0, 24, 128, 9, 1);
  screen.print(F("2) Time"));
  screen.setTextColor(WHITE);
  
  screen.setCursor(0, 34);
  screen.print(F("3) Date"));
  screen.setCursor(0, 43);
  screen.print(F("4) Night Light"));
  screen.setCursor(0, 52);
  screen.print(F("5) Brightness"));

  screen.display();
  
}





void loop()
{
/*
 * Must consist of reading time, IR and infrared input to enter programming or set alarms
 * Msut not constantly print to screen or 4 digit display or set LED state (only once)
 * Capacitive sensor input only needed when alarm goes off (all other input through IR)
 */
}
