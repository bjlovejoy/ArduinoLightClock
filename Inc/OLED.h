#ifndef __OLED_H
#define __OLED_H

#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include <Wire.h>
#include <SPI.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET    -1  // Reset pin # (or -1 if sharing Arduino reset pin)

class OLED
{
	private:
		Adafruit_SSD1306 screen(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
		
	public:
		OLED();
		void clearAll();
		bool findError();
		void printLogo();
		
		void updateRunning();
		void updateProgMenu(uint8_t);
		void updateProgAlarm();
		void updateProgDay();
		void updateProgTime();
		void updateProgLight();
		void updateProgBuzzer();
		
		void updateProgDate();
		void updateProgNightLight();
		void updateProgBrightness();
		
/*
const unsigned char alarm_bell[] PROGMEM = {
  B00000001,B10000000,B00000000,
  B00000011,B11000000,B00000000,
  B00000111,B11100000,B00000000,
  B00001100,B00110000,B00000000,
  B00001000,B00010000,B00000000,
  B00011000,B00011000,B00000000,
  B00011000,B00011000,B00000000,
  B00011000,B00011000,B00000000,
  B00011000,B00011000,B00000000,
  B00010000,B00001000,B00000000,
  B00110000,B00001100,B00000000,
  B01110000,B00001110,B00000000,
  B01100000,B00000110,B00000000,
  B00111111,B11111100,B00000000,
  B00000011,B11000000,B00000000,
  B00000001,B10000000,B00000000 
};
*/
};

#endif