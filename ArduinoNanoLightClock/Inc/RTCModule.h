#ifndef __RTC_MODULE_H
#define __RTC_MODULE_H

#include "RTClib.h"

class RTCModule
{
	private:
		RTC_DS3231 rtc_;
		char daysOfTheWeek_[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		DateTime now_ = rtc_.now();
		
	public:
		RTCModule();
		bool findError();
		void setTime();
		void getDate();  //make string or char string
		uint16_t getTime();
};

#endif