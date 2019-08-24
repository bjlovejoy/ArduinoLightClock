#ifndef __ARDUINO_CLOCK_H
#define __ARDUINO_CLOCK_H

#include "Alarm.h"
#include "Buzzer.h"
#include "LED.h"
#include "MyRemote.h"
#include "OLED.h"
#include "RTCModule.h"
#include "SevenSeg.h"
#include "TempHumidity.h"

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

#define NUM0 0
#define NUM1 1
#define NUM2 2
#define NUM3 3
#define NUM4 4
#define NUM5 5
#define NUM6 6
#define NUM7 7
#define NUM8 8
#define NUM9 9

#define CONFIRM 15
#define SELECT 14
#define PROGMODE 16
#define LEFT 10
#define RIGHT 12
#define DOWN 11
#define UP 13
#define TIMEDOWN 11
#define TIMEUP 13
#define EQ 17
#define REPT 18  //use for back button

class ArduinoClock
{
	private:
		uint8_t state_;
		uint8_t errorCode_;
		uint16_t currentTime_;
		uint16_t currentDay_;
		
		uint8_t pos_;
		uint8_t next_pos_;
		uint8_t selection_;
		//bool remoteInputAvailable_;
		
		uint8_t remoteInput;
		
		
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