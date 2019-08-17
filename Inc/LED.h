#ifndef __LED_H
#define __LED_H

class LED
{
	private:
		uint8_t redPin;
		uint8_t greenPin;
		uint8_t bluePin;
		
		uint8_t redLED   = [0, 0, 0, 0, 0, 0, 0, 0, 255, 0]
		uint8_t greenLED = [0, 0, 0, 0, 0, 0, 0, 0, 255, 0]
		uint8_t blueLED  = [0, 0, 0, 0, 0, 0, 0, 0, 255, 0]
		
		uint8_t red		= 0;
		uint8_t orange	= 1;
		uint8_t yellow	= 2;
		uint8_t green	= 3;
		uint8_t teal	= 4;
		uint8_t blue	= 5;
		uint8_t violet	= 6;
		uint8_t pink	= 7;
		uint8_t white	= 8;
		uint8_t off		= 9;
		
	public:
		LED(uint8_t, uint8_t, uint8_t);
		//bool for if repeating in loop or one-time
		void allOff();
		void solidColor();
		void blinkColor(bool);
		void smoothColor(bool);
		void fadeHigh(bool);
		void fadeLow(bool);
		void switchColor(bool);
		void rainbowFade(bool);
		void errorColor(bool);
};

#endif