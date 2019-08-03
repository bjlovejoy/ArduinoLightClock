#include <Wire.h>
#include <SPI.h>
#include "TM1637Display.h"
#include "RTClib.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "allFunctions.h"
#include "LEDfunctions.h"
//#include "bitmapArray.h"
//#include "remoteCode.h"
#include "IRremote.h"


//Global Variables ************************************************************************************************************************
int irInput = 0;
bool errorLED = false;
int temperature = 0;
int humidity = 0;

//change all to bytes
___________________________________________________________________________________________________________________________________________



//4-Digit Display module ******************************************************************************************************************
#define CLK 7
#define DIO 8
TM1637Display digitDisplay(CLK, DIO);

  digitDisplay.setBrightness(7, true);  //control with IR (outside programming, still require validation after final selection)
  digitDisplay.clear();
  //if need to enter programming mode:
  digitDisplay.showNumberDecEx(num, 0b01000000, false)  //number, colon, leading 0s, length (3 or 4), pos of first digit (0 0r 1)
___________________________________________________________________________________________________________________________________________



//RTC module (D -> SDA , C - SCL , NC -> No connection -> GND) ****************************************************************************
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

  if(!rtc.begin())
  {
    Serial.println("Couldn't find RTC");
    errorLED = true;
    while(true)  // Don't proceed, loop forever
    {
      digitalWrite(red, errorLED);
      errorLED = !errorLED;
      delay(1000);
    }
  }

  if(rtc.lostPower())
  {
    digitalWrite(blue, HIGH);
    delay(500);
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.cp437(true);
    display.write("Press OK to enter programming mode.");
    display.display();
    while(pushedButton != buttons.OK)
    {
      irrecv.decode(&results);
      pushedButton = results.value;
      delay(10);
      
    }
    pushedButton = 0;
    irrecv.resume();
    
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
___________________________________________________________________________________________________________________________________________



//OLED Display ****************************************************************************************************************************
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET    -1  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

___________________________________________________________________________________________________________________________________________



//IR remote and receiver ******************************************************************************************************************
#define irSensor 15
IRrecv irrecv(irSensor);
decode_results results;
unsigned long pushedButton = 0;

  irrecv.enableIRIn(); // Start the receiver
___________________________________________________________________________________________________________________________________________



//LED pins ********************************************************************************************************************************
int red = 5;
int green = 6;
int blue = 9;

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
___________________________________________________________________________________________________________________________________________



//Other input and output pins *************************************************************************************************************
int buzzerPin = 9;
int tempPin = 14;

  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  pinMode(tempPin, INPUT);
___________________________________________________________________________________________________________________________________________








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


  
}





void loop()
{
/*
 * Must consist of reading time, IR and infrared input to enter programming or set alarms
 * Msut not constantly print to screen or 4 digit display or set LED state (only once)
 * Capacitive sensor input only needed when alarm goes off (all other input through IR)
 */
}
