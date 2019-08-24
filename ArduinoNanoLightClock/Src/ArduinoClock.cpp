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
	if(state_ == RUNNING_MODE)
	{
		//collect time and date
		
		//if programming mode clicked, confirm and set this: updateProgMenu(0);
		
		if(AC_alarm1.alarmOn && AC_alarm1.alarmTime == currentTime_)  //&& AC_alarm1.alarmDate == currentDay_
		{
			;
		}
		else if(AC_alarm2.alarmOn && AC_alarm2.alarmTime == currentTime_)
		{
			;
		}
		else if(AC_alarm3.alarmOn && AC_alarm3.alarmTime == currentTime_)
		{
			;
		}
	}
	
//********************************************************************************************************************************************

	else if(state_ == PROGRAMMING_MODE)
	{
		if(pos_ == 0)  //print the menu selections
		{
			AC_oled.updateProgMenu(1);
			pos_ = 3;
		}
		if(pos_ == 1)  //select button pressed
		{
			;  //blink LED to confirm (need to move outside if statement so it can repeat until new input received)
		}
		if(pos_ == 2)  //confirm button pressed
		{
			;  //confirm (blink stops when pos_ == 1) and move to next position
		}
		if(pos_ == 3)  //scroll through the main menu and select item
		{
			if(AC_remote.determineInput())  //determine if input is available
			{
				remoteInput = AC_remote.getInput();  //gets final input (consider merging with above function)
				
				if(remoteInput == UP || remoteInput == DOWN || remoteInput > NUM0 || remoteInput < NUM6)
				{
					selection_ = AC_oled.updateProgMenu(remoteInput);  //up
				}

				else if(remoteInput == REPT)  //blink different color to go back?
				{
					pos_ = 0;
				}
				else if(remoteInput == SELECT)
				{
					pos = 1;
				}
				else if(remoteInput == CONFIRM)
				{
					pos = 2;  //save selections and set pos to next
					next_pos_ = 4;
				}

			}
		}
		if(pos_ == 4)
		{
			;
		}

	}

//********************************************************************************************************************************************

	else if(state_ == STARTUP_MODE)
	{
		if(AC_remote.findError())
		{
			state_ = ERROR_MODE;
			errorCode_ = 1;
			return;
		}
		else if(AC_OLED.findError())
		{
			state_ = ERROR_MODE;
			errorCode_ = 2;
			return;
		}
		else if(AC_7seg.findError())
		{
			state_ = ERROR_MODE;
			errorCode_ = 3;
			return;
		}
	}

//********************************************************************************************************************************************

//add alarm-going-off mode

	else if(state_ == ERROR_MODE)
	{
		;
	}
}

