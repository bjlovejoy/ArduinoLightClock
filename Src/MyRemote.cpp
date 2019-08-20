#include <Arduino.h>

#include "MyRemote.h"
#include "IRremote.h"

MyRemote::MyRemote()
{
	irrecv.enableIRIn(); // Start the receiver
}

bool MyRemtote::collectInput(uint8_t &num)  //pass result by reference, return bool if available
{
	if (irrecv.decode(&num))
	{
		Serial.println(results.value, HEX);
		irrecv.resume(); // Receive the next value
		return true;
	}
	return false;
}



//IRrecv irrecv(irSensor);

