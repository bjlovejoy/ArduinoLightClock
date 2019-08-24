#include <Arduino.h>
#include "RTCModule.h"
#include "RTClib.h"

RTCModule::RTCModule()
{
	if(!rtc.begin())
	{
		Serial.println("Couldn't find RTC");
		while(true)  // Don't proceed, loop forever
		{
			//slow blink red
		}
	}

	if(rtc.lostPower())
	{
		digitalWrite(blue, HIGH);
		delay(500);
		display.clearDisplay();
		display.setTextSize(1);
		display.setCursor(0, 0);
		display.cp437(true);
		display.write("Press OK to enter programming mode.");
		display.display();
		while(pushedButton != buttons.OK)
		{
			irrecv.decode(&results);
			pushedButton = results.value;
			delay(10);
		}
		pushedButton = 0;
		irrecv.resume();

		// rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
	}
}

