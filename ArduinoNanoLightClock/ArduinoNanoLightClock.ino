#include <Wire.h>
#include <SPI.h>
#include "TM1637Display.h"
#include "RTClib.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "allFunctions.h"
//#include "bitmapArray.h"
//#include "remoteCode.h"
#include "IRremote.h"

//Pins and obeject for the 4-Digit Display module
int CLK = 7;
int DIO = 8;
TM1637Display digitDisplay(CLK, DIO);

//Pins and object for rtc module        //D -> SDA     C - SCL     NC -> No connection -> GND
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//OLED Display
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET    -1  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


//LED pins
int red = 5;
int green = 6;
int blue = 9;

//Other input and output pins
int buzzer = 9;
int temp = 14;

//IR remote and receiver
int irSensor = 15;
IRrecv irrecv(irSensor);
decode_results results;
unsigned long pushedButton = 0;

int irInput = 0;
bool error = false;

void setup()
{
  Serial.begin(9600);
  delay(2000);
  
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  //noTone(buzzer);
  irrecv.enableIRIn(); // Start the receiver

  //Initialize the rtc module
  if(!rtc.begin())
  {
    Serial.println("Couldn't find RTC");
    error = true;
    while(true)  // Don't proceed, loop forever
    {
      digitalWrite(red, error);
      error = !error;
      delay(1000);
    }
  }

  //initialize the OLED display and display Logo
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))  // Address 0x3C for 128x64
  {
    Serial.println(F("SSD1306 allocation failed"));
    error = true;
    while(true)  // Don't proceed, loop forever
    {
      digitalWrite(red, error);
      error = !error;
      delay(200);
    }
  }
  display.clearDisplay();
  display.drawBitmap(0, 0, lovejoy_inventions_bitmap, 128, 64, 1);
  display.display();
  delay(2000);

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
    }
    pushedButton = 0;
    irrecv.resume();
    
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  
}

void loop()
{

}
