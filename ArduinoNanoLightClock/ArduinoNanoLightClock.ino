#include <TM1637Display.h>
#include <Wire.h>
#include <RTClib.h>

//Pins and obeject for the 4-Digit Display module
int CLK = 7;
int DIO = 8;
TM1637Display display(CLK, DIO);

//Pins and object for rtc module
//D -> SDA     //C - SCL     //NC -> No connection -> GND
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//LED pins
int red = 5;
int green = 6;
int blue = 9;

void setup()
{
  Serial.begin(9600);
  
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT;
}

void loop()
{

}
