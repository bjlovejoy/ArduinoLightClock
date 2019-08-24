#include <Arduino.h>

#include "MyRemote.h"
#include "IRremote.h"

MyRemote::MyRemote()
{
	irrecv_.enableIRIn(); // Start the receiver
}

bool MyRemtote::collectInput()  //pass result by reference, return bool if available
{
	if (irrecv_.decode(&results_))
	{
		Serial.println(results_.value, HEX);
		irrecv_.resume(); // Receive the next value
		return true;
	}
	return false;
}

uint8_t MyRemote::getInput()
{
	unsigned long num = results_.value;
	for(int i =0; i < 21; ++i)
	{
		if(remoteIn_[i] == num)
			return remoteOut_[i];
	}
}


