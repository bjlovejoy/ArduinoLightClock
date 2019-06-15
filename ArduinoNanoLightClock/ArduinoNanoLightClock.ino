#include "TM1637Display.h"
#include "RTClib.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include <Wire.h>

//Pins and obeject for the 4-Digit Display module
int CLK = 7;
int DIO = 8;
TM1637Display display(CLK, DIO);

//Pins and object for rtc module
//D -> SDA     //C - SCL     //NC -> No connection -> GND
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//OLED Display
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//LED pins
int red = 5;
int green = 6;
int blue = 9;

int buzzer = 4;
int temp = 14;
int irSensor = 15;

void setup()
{
  Serial.begin(9600);
  
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))  // Address 0x3C for 128x64
  {
    Serial.println(F("SSD1306 allocation failed"));
    digitalWrite(red, HIGH);
    for(;;); // Don't proceed, loop forever
  }
}

void loop()
{

}
