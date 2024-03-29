#ifndef __MY_REMOTE_H
#define __MY_REMOTE_H

#include "IRremote.h"

#define irSensor 15

class MyRemote
{
	private:
		uint8_t RECV_PIN = 11;		//replace with irSensor (keep to _ member variable formatting)
		IRrecv irrecv_(RECV_PIN);
		decode_results results_;
	
		//Inputs*************************************************************
		unsigned long remoteIn_[] = {3238126971, 16724175, 16718055, 16743045, 16716015, 16726215, 16734885,
									16728765, 16730805, 1053031451, 16753245, 16712445, 16769565, 16720605
									16761405, 16769055, 16748655, 16754775, 16736925, 16750695, 16756815};
		/*
		unsigned long num0			= 3238126971;
		unsigned long num1			= 16724175;     //alarm 1
		unsigned long num2			= 16718055;     //alarm 2
		unsigned long num3			= 16743045;     //alarm 3
		unsigned long num4			= 16716015;
		unsigned long num5			= 16726215;
		unsigned long num6			= 16734885;
		unsigned long num7			= 16728765;
		unsigned long num8			= 16730805;
		unsigned long num9			= 1053031451;
		
		unsigned long confirm		= 16753245;		//power
		unsigned long select		= 16712445;     //play/pause
		unsigned long progMode		= 16769565;     //FUNC/STOP

		unsigned long left			= 16720605;   	//rewind
		unsigned long right			= 16761405;  	//fast forward
		unsigned long down			= 16769055;     //down triangle
		unsigned long up			= 16748655;     //up triangle

		unsigned long timeDown		= 16754775;   	//volume down
		unsigned long timeUp		= 16736925;		//volume up
		unsigned long eq			= 16750695;
		unsigned long rept			= 16756815;
		*/

		//Outputs*************************************************************
		uint8_t remoteOut_[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 14, 16, 10, 12, 11, 13, 11, 13, 17, 18};

		/*
		uint8_t num0Out			= 0;
		uint8_t num1Out			= 1;    //alarm 1
		uint8_t num2Out			= 2;    //alarm 2
		uint8_t num3Out			= 3;    //alarm 3
		uint8_t num4Out			= 4;
		uint8_t num5Out			= 5;
		uint8_t num6Out			= 6;
		uint8_t num7Out			= 7;
		uint8_t num8Out			= 8;
		uint8_t num9Out			= 9;

		uint8_t confirmOut		= 15;	//power
		uint8_t selectOut		= 14;   //play/pause
		uint8_t progModeOut		= 16;   //FUNC/STOP

		uint8_t moveLeftOut		= 10;   //rewind
		uint8_t moveRightOut	= 12;  	//fast forward
		uint8_t downOut			= 11;   //down triangle
		uint8_t upOut			= 13;   //up triangle

		uint8_t timeDownOut		= 11;   //volume down
		uint8_t timeUpOut		= 13;   //volume up
		uint8_t eqOut			= 17;   //eq
		uint8_t reptOut			= 18;   //rept
		*/

	public:
		MyRemote();
		bool findError();
		bool determineInput();  //not correct, but pass variable to hold results and true if results are available
		uint8_t getInput();
};

#endif