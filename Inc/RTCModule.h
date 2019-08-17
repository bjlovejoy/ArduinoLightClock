#ifndef __RTC_MODULE_H
#define __RTC_MODULE_H

#include "RTClib.h"

class RTCModule
{
	private:
		RTC_DS3231 rtc;
		char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		
	public:
		RTCModule();
		bool findError();
		void setTime();
};

#endif