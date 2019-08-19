#ifndef __ALARM_H
#define __ALARM_H

#include "SimpleDHT.h"

class Alarm
{
	private:
		bool alarmOn = false;
		uint16_t alarmTime;  //smash hour and minutes into one (ex. 544, 1205)
		bool alarmAM;  //true for am, false for pm
		
		String alarmDays;  //can replace with boolean array
		
		uint8_t lightColor;
		uint8_t lightStyle;
		uint8_t buzzerPitch;
		uint8_t buzzerStyle;
		
	public:
		;
};

#endif