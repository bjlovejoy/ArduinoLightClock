#ifndef __MY_REMOTE_H
#define __MY_REMOTE_H

#include "IRremote.h"

#define irSensor 15

class MyRemote
{
	private:
		  unsigned long confirm		= 16753245;		//power
		  unsigned long select		= 16712445;     //play/pause
		  unsigned long progMode	= 16769565;     //FUNC/STOP
		  
		  unsigned long moveLeft	= 16720605;   	//rewind
		  unsigned long moveRight	= 16761405;  	//fast forward
		  unsigned long down		= 16769055;     //down triangle
		  unsigned long up			= 16748655;     //up triangle
		  
		  unsigned long timeDown	= 16754775;   	//volume down
		  unsigned long timeUp		= 16736925;     //volume up
		  unsigned long eq			= 16750695;
		  unsigned long rept		= 16756815;
		  
		  unsigned long num0 = 3238126971;
		  unsigned long num1 = 16724175;       //alarm 1
		  unsigned long num2 = 16718055;       //alarm 2
		  unsigned long num3 = 16743045;       //alarm 3
		  unsigned long num4 = 16716015;
		  unsigned long num5 = 16726215;
		  unsigned long num6 = 16734885;
		  unsigned long num7 = 16728765;
		  unsigned long num8 = 16730805;
		  unsigned long num9 = 1053031451;
		
	public:
		MyRemote();
		bool findError();
		uint8_t collectInput();
};

#endif