#ifndef __ARDUINO_CLOCK_H
#define __ARDUINO_CLOCK_H

#include "TM1637Display.h"
#include "RTClib.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "IRremote.h"
#include "SimpleDHT.h"

#define CLK 7
#define DIO 8

class ArduinoClock
{
	private:
		TM1637Display digitDisplay(CLK, DIO);
		RTC_DS3231 rtc;
	
	public:
		ArduinoClock();
};






#endif