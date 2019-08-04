#include <Arduino.h>
#include "ArduinoClock.h"
#include "Alarm.h"

#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "IRremote.h"
#include "SimpleDHT.h"

//Refer to GitHub to see original version of ArduinoNanoLightClock

ArduinoClock::ArduinoClock()
{
	digitDisplay.setBrightness(7, true);
	digitDisplay.clear();
	
}