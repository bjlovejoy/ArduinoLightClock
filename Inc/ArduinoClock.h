#ifndef __ARDUINO_CLOCK_H
#define __ARDUINO_CLOCK_H

#include "TM1637Display.h"
#include "RTClib.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "IRremote.h"
#include "SimpleDHT.h"

#define STARTUP_MODE 0
#define RUNNING_MODE 1
#define PROGRAMMING_MODE 2
#define ERROR_MODE 3

class ArduinoClock
{
	private:
		uint8_t state;
		uint8_t errorCode;
		uint8_t pos;
		uint16_t currentTime;
		uint16_t currentDay;
		
		bool remoteInputAvailable;
		
		Alarm AC_alarm1;
		Alarm AC_alarm2;
		Alarm AC_alarm3;
		Buzzer AC_buzzer;
		LED AC_led;
		MyRemote AC_remote;
		OLED AC_oled;
		RTCModule AC_rtc;
		SevenSeg AC_7seg;
		TempHumidity AC_temp;
	
	public:
		ArduinoClock();
		void stateMachine();
};






#endif