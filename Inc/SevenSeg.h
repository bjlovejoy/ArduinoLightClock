#ifndef __SEVEN_SEG_H
#define __SEVEN_SEG_H

#include "TM1637Display.h"

#define CLK 7
#define DIO 8

class SevenSeg
{
	private:
		TM1637Display digitDisplay(CLK, DIO);
		bool displayOn = true;
		uint8_t brightness = 5;   //range from 1 to 7
		
	public:
		SevenSeg();
		void update(uint16_t);
		void toggle();
		void setBright(uint8_t);
};

#endif