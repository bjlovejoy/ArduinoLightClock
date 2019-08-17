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
	
	public:
		ArduinoClock();
		void stateMachine();
};






#endif