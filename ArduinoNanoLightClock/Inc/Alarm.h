#ifndef __ALARM_H
#define __ALARM_H

#include "SimpleDHT.h"

class Alarm
{
	private:
		bool alarmOn_ = false;
		uint16_t alarmTime_;  //smash hour and minutes into one (ex. 544, 1205)
		bool alarmAM_;  //true for am, false for pm
		
		String alarmDays_;  //can replace with boolean array
		
		uint8_t lightColor_;
		uint8_t lightStyle_;
		uint8_t buzzerPitch_;
		uint8_t buzzerStyle_;
		
	public:
		;
};

#endif