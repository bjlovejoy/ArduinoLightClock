#include <Arduino.h>

#include "MyRemote.h"
#include "IRremote.h"

MyRemote::MyRemote()
{
	irrecv.enableIRIn(); // Start the receiver
}

IRrecv irrecv(irSensor);
decode_results results;