#include <Arduino.h>
#include "OLED.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

OLED::OLED()
{
	Serial.begin(9600);

	// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
	if(!screen.begin(SSD1306_SWITCHCAPVCC, 0x3C))  // Address 0x3D for 128x64
	{
		Serial.println(F("SSD1306 allocation failed"));
		for(;;); // Don't proceed, loop forever
	}
}

void OLED::clearAll()
{
	screen.clearDisplay();
}

void OLED::updateRunning()
{
	screen.setTextSize(2);      // Normal 1:1 pixel scale
	screen.setTextColor(WHITE); // Draw white text
	screen.cp437(true);         // Use full 256 char 'Code Page 437' font
	screen.setCursor(0, 0);     // Start at top-left corner

	delay(500);
	screen.clearDisplay();

	screen.print(F("AM"));
	screen.drawBitmap(50, 0, alarm_bell, 17, 16, 1);
	screen.setCursor(75, 0);
	screen.print(F("1"));
	screen.setCursor(95, 0);
	screen.print(F("2"));
	screen.setCursor(115, 0);
	screen.print(F("3"));
	
	screen.display();
}

//dir will be controller input for number or up/down, set to zero for first round through to highlight none of them
void OLED::updateProgMenu(uint8_t dir)
{
	screen.setTextSize(1);      // Normal 1:1 pixel scale
	screen.setTextColor(WHITE); // Draw white text
	screen.cp437(true);         // Use full 256 char 'Code Page 437' font
	screen.setCursor(15, 0);     // Start at top-left corner

	delay(500);
	screen.clearDisplay();
	screen.writeFillRect(0, 11, 128, 2, 1);
	screen.print(F("Programming Mode"));
	screen.setCursor(0, 16);
	screen.print(F("1) Alarms"));

	screen.setCursor(0, 26);
	screen.print(F("2) Time"));
	screen.setCursor(0, 36);
	screen.print(F("3) Date"));
	screen.setCursor(0, 46);
	screen.print(F("4) Night Light"));
	screen.setCursor(0, 56);
	screen.print(F("5) Brightness"));
	
	if(dir == 1)
		screen.writeFillRect(0, 16, 128, 9, 2);
	if(dir == 2)
		screen.writeFillRect(0, 25, 128, 9, 2);
	if(dir == 3)
		screen.writeFillRect(0, 35, 128, 9, 2);
	if(dir == 4)
		screen.writeFillRect(0, 45, 128, 10, 2);
	if(dir == 5)
		screen.writeFillRect(0, 55, 128, 9, 2);

	screen.display();
}

void OLED::updateProgAlarm()  //instead of programming empty ones to say "NONE", set to Monday at 7 am
{
	screen.setTextSize(2);
	screen.setTextColor(WHITE);
	screen.cp437(true);
	screen.setCursor(0, 0);

	int num = 2;   //start with alarm 1, then shift through all info
	delay(500);
	screen.clearDisplay();
	screen.print(F("< Alarm"));
	screen.print((num));
	screen.print(F(" >"));

	screen.setTextSize(1);  //print days and time (unique input based on alarm 1, 2 or 3)

	screen.setCursor(0, 20);
	screen.print(F("Days:"));
	screen.setCursor(40, 20);
	screen.print(F("SuMoTuWeThFrSa"));

	screen.setCursor(0, 36);
	screen.print(F("Time:"));
	screen.setCursor(40, 36);
	screen.print(F("7:00 AM"));


	screen.setCursor(10, 55);    //print at bottom and use inverse rectangle to select with remote input
	screen.print(F("Preview"));
	screen.setCursor(85, 55);
	screen.print(F("Edit"));
	screen.writeLine(65, 53, 65, 63, 1);
	screen.writeLine(0, 53, 127, 53, 1);
	
	screen.writeFillRect(0, 54, 65, 10, 2);    //highlight preview
	screen.writeFillRect(66, 54, 127, 10, 2);  //highlight edit

	screen.display();
}

void OLED::updateProgDay()
{
	screen.setTextSize(1);      // Normal 1:1 pixel scale
	screen.setTextColor(WHITE); // Draw white text
	screen.cp437(true);         // Use full 256 char 'Code Page 437' font
	screen.setCursor(0, 0);     // Start at top-left corner

	int num = 2;
	delay(500);
	screen.clearDisplay();
	screen.writeFillRect(0, 11, 128, 2, 1);
	screen.print(F("Alarm "));
	screen.print(num);
	screen.print(F(" - Days"));

	screen.setTextSize(2);
	screen.setCursor(15, 16);
	screen.print(F("Mo Tu We"));
	screen.setCursor(35, 33);
	screen.print(F("Th Fr"));
	screen.setCursor(35, 50);
	screen.print(F("Sa Su"));

	//screen.writeFillRect(10, 16, 32, 15, 2);  //Mo
	//screen.writeFillRect(45, 16, 32, 15, 2);  //Tu
	//screen.writeFillRect(80, 16, 32, 15, 2);  //We
	//screen.writeFillRect(30, 32, 32, 16, 2);  //Th
	//screen.writeFillRect(65, 32, 32, 16, 2);  //Fr
	//screen.writeFillRect(30, 49, 32, 15, 2);  //Sa
	//screen.writeFillRect(65, 49, 32, 15, 2);  //Su
	
	//consider empty fill box when making selection
	//left and right movement only
	
	screen.display();
}

void OLED::updateProgTime()
{
  screen.setTextSize(1);      // Normal 1:1 pixel scale
  screen.setTextColor(WHITE); // Draw white text
  screen.cp437(true);         // Use full 256 char 'Code Page 437' font
  screen.setCursor(0, 0);     // Start at top-left corner

  int num = 2;
  delay(500);
  screen.clearDisplay();
  screen.writeFillRect(0, 11, 128, 2, 1);
  screen.print(F("Alarm "));
  screen.print(num);
  screen.print(F(" - Time"));

  screen.setTextSize(3);
  screen.setCursor(17, 20);
  screen.print(F("12:00"));

  screen.setTextSize(2);
  screen.setCursor(27, 48);
  screen.print(F("AM  PM"));

  //screen.writeFillRect(16, 19, 15, 25, 2);  //1
  //screen.writeFillRect(32, 19, 20, 25, 2);  //2
  //screen.writeFillRect(67, 19, 20, 25, 2);  //3
  //screen.writeFillRect(88, 19, 20, 25, 2);  //4
  //screen.writeFillRect(22, 46, 30, 17, 2);  //AM
  //screen.writeFillRect(72, 46, 30, 17, 2);  //PM

  screen.display();
}

void OLED::updateProgLight()
{
	screen.setTextSize(1);      // Normal 1:1 pixel scale
	screen.setTextColor(WHITE); // Draw white text
	screen.cp437(true);         // Use full 256 char 'Code Page 437' font
	screen.setCursor(0, 0);     // Start at top-left corner

	int num = 2;
	delay(500);
	screen.clearDisplay();
	screen.writeFillRect(0, 11, 128, 2, 1);
	screen.print(F("Alarm "));
	screen.print(num);
	screen.print(F(" - Time"));

	screen.setCursor(0, 16);
	screen.print(F("1) Off"));
	screen.setCursor(0, 28);
	screen.print(F("2) Solid"));
	screen.setCursor(0, 40);
	screen.print(F("3) Blink"));
	screen.setCursor(0, 52);
	screen.print(F("4) Smooth"));
	screen.setCursor(65, 16);
	screen.print(F("5) FadeU"));
	screen.setCursor(65, 28);
	screen.print(F("6) FadeD"));
	screen.setCursor(65, 40);
	screen.print(F("7) Switch"));
	screen.setCursor(65, 52);
	screen.print(F("8) Rainbow"));

	//screen.writeFillRect(0, 16, 12, 10, 2);  //1
	//screen.writeFillRect(0, 27, 12, 10, 2);  //2
	//screen.writeFillRect(0, 38, 12, 10, 2);  //3
	//screen.writeFillRect(0, 50, 12, 10, 2);  //4
	//screen.writeFillRect(64, 16, 12, 10, 2);  //5
	//screen.writeFillRect(64, 27, 12, 10, 2);  //6
	//screen.writeFillRect(64, 38, 12, 10, 2);  //7
	//screen.writeFillRect(64, 50, 12, 10, 2);  //8

	screen.display();
}

void OLED::updateProgLight2()
{
	screen.setTextSize(2);      // Normal 1:1 pixel scale
	screen.setTextColor(WHITE); // Draw white text
	screen.cp437(true);         // Use full 256 char 'Code Page 437' font
	screen.setCursor(0, 0);     // Start at top-left corner

	int num = 2;
	delay(500);
	screen.clearDisplay();

	screen.setCursor(8, 20);
	screen.print(F("< COLOR >"));
	screen.setCursor(2, 45);
	screen.print(F("< BRIGHT >"));
	//screen.print(F("  BRIGHT >"));
	//screen.print(F("< BRIGHT"));


	//screen.writeFillRect(0, 16, 127, 22, 2);  //color
	//screen.writeFillRect(0, 41, 127, 22, 2);  //bright

	screen.display();
}

void OLED::updateProgBuzzer()
{
	screen.setTextSize(1);      // Normal 1:1 pixel scale
	screen.setTextColor(WHITE); // Draw white text
	screen.cp437(true);         // Use full 256 char 'Code Page 437' font
	screen.setCursor(0, 0);     // Start at top-left corner

	int num = 2;
	delay(500);
	screen.clearDisplay();
	screen.writeFillRect(0, 11, 128, 2, 1);
	screen.print(F("Alarm "));
	screen.print(num);
	screen.print(F(" - Buzzer"));

	screen.setCursor(0, 16);
	screen.print(F("1) Off"));
	screen.setCursor(0, 28);
	screen.print(F("2) Beep"));
	screen.setCursor(0, 40);
	screen.print(F("3) Beepx2"));
	screen.setCursor(0, 52);
	screen.print(F("4) Beepx3"));

	screen.setCursor(65, 16);
	screen.print(F("5) Fast"));
	screen.setCursor(65, 28);
	screen.print(F("6) Range"));
	screen.setCursor(65, 40);
	screen.print(F("7) Tune 1"));
	screen.setCursor(65, 52);
	screen.print(F("8) Tune 2"));

	//screen.writeFillRect(0, 16, 12, 10, 2);  //1
	//screen.writeFillRect(0, 27, 12, 10, 2);  //2
	//screen.writeFillRect(0, 38, 12, 10, 2);  //3
	//screen.writeFillRect(0, 50, 12, 10, 2);  //4
	//screen.writeFillRect(64, 16, 12, 10, 2);  //5
	//screen.writeFillRect(64, 27, 12, 10, 2);  //6
	//screen.writeFillRect(64, 38, 12, 10, 2);  //7
	//screen.writeFillRect(64, 50, 12, 10, 2);  //8

	screen.display();
}

void OLED::updateProgBuzzer2()
{
	screen.setTextSize(2);      // Normal 1:1 pixel scale
	screen.setTextColor(WHITE); // Draw white text
	screen.cp437(true);         // Use full 256 char 'Code Page 437' font
	screen.setCursor(0, 0);     // Start at top-left corner

	int num = 2;
	delay(500);
	screen.clearDisplay();

	screen.setCursor(8, 30);
	screen.print(F("< PITCH >"));
	//screen.print(F("  PITCH >"));
	//screen.print(F("< PITCH"));

	screen.writeFillRect(0, 26, 127, 22, 2);  //color

	screen.display();
}

void updateProgDate()
{

}

void updateProgNightLight()
{

}

void updateProgBrightness()
{

}

