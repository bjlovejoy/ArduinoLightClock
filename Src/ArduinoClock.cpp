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

}

void ArduinoClock::stateMachine()
{
	if(state == RUNNING_MODE)
	{
		//collect time and date
		
		if(AC_alarm1.alarmOn && AC_alarm1.alarmTime == currentTime)  //&& AC_alarm1.alarmDate == currentDay
		{
			;
		}
		else if(AC_alarm2.alarmOn && AC_alarm2.alarmTime == currentTime)
		{
			;
		}
		else if(AC_alarm3.alarmOn && AC_alarm3.alarmTime == currentTime)
		{
			;
		}
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

