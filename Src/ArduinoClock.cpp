#include <Arduino.h>
#include "ArduinoClock.h"

#include "Alarm.h"
#include "Buzzer.h"
#include "LED.h"
#include "MyRemote.h"
#include "OLED.h"
#include "RTCModule.h"
#include "SevenSeg.h"
#include "TempHumidity.h"


//Refer to GitHub to see original version of ArduinoNanoLightClock

ArduinoClock::ArduinoClock()
{
	Alarm AC_alarm1;
	Buzzer AC_alarm2;
	LED AC_alarm3;
	MyRemote AC_buzzer;
	OLED AC_led;
	RTCModule AC_remote;
	AC_oled;
	AC_rtc;
	AC_7seg;
	AC_temp;
	AC_;
}

void ArduinoClock::stateMachine()
{
	if(state == RUNNING_MODE)
	{
		;
	}
	else if(state == PROGRAMMING_MODE)
	{
		;
	}
	else if(state == STARTUP_MODE)
	{
		if(AC_remote.findError())
		{
			state = ERROR_MODE;
			errorCode = 1;
			return;
		}
		else if(AC_OLED.findError())
		{
			state = ERROR_MODE;
			errorCode = 2;
			return;
		}
		else if(AC_7seg.findError())
		{
			state = ERROR_MODE;
			errorCode = 3;
			return;
		}
	}
	else if(state == ERROR_MODE)
	{
		;
	}
}

