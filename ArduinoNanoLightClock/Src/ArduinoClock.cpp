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
		
		//if programming mode clicked, confirm and set this: updateProgMenu(0);
		
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
	
//********************************************************************************************************************************************

	else if(state == PROGRAMMING_MODE)
	{
		if(pos == 0)  //print the menu selections
		{
			AC_oled.updateProgMenu(1);
			++pos;
		}
		if(pos == 1)  //scroll through the menu and select item
		{
			//not the right data type, may need to do in MyRemote and pass multiple parameters by reference
			remoteInputAvailable = AC_remote.collectInput(uint32_t & tester1234)
			if(remoteInputAvailable)  // && tester1234 != back, confirm, number selections, etc.
			{
				AC_oled.updateProgMenu(bool(tester1234));  //for up and down arrows only
			}

			else if(tester1234 ==)  //code for back, confirm, number selections, etc.
			{
				;  //include else if for all other possibilities
			}
		}
	}

//********************************************************************************************************************************************

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

//********************************************************************************************************************************************

//add alarm-going-off mode

	else if(state == ERROR_MODE)
	{
		;
	}
}

