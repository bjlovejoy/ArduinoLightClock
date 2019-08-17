#include <Arduino.h>
#include "SevenSeg.h"
#include "TM1637Display.h"

SevenSeg::SevenSeg()
{
	digitDisplay.setBrightness(brightness, displayOn);
	digitDisplay.clear();
}

void SevenSeg::update(uint16_t num)
{
	if(num < 1000)
		digitDisplay.showNumberDecEx(num, 0b01000000, false, 3, 1);
	else
		digitDisplay.showNumberDecEx(num, 0b01000000, false, 4, 0);
}

void SevenSeg::toggle()
{
	if(displayOn)
		displayOn = false;
	else
		displayOn = true;
	digitDisplay.setBrightness(brightness, displayOn);
}

//add later on if remote up, increase by 1 until 7, same for down
void SevenSeg::setBright(uint8_t num)
{
	brightness = num;
	digitDisplay.setBrightness(brightness);
}

