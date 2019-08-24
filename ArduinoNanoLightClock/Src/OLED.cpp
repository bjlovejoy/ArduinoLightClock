#include <Arduino.h>
#include "OLED.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

OLED::OLED()
{
	Serial.begin(9600);

	// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
	if(!screen_.begin(SSD1306_SWITCHCAPVCC, 0x3C))  // Address 0x3D for 128x64
	{
		Serial.println(F("SSD1306 allocation failed"));
		for(;;); // Don't proceed, loop forever
	}
}

void OLED::clearAll()
{
	screen_.clearDisplay();
}


uint8_t getSelection()
{
	return selection;
}


void OLED::updateRunning()
{
	screen_.setTextSize(2);      // Normal 1:1 pixel scale
	screen_.setTextColor(WHITE); // Draw white text
	screen_.cp437(true);         // Use full 256 char 'Code Page 437' font
	screen_.setCursor(0, 0);     // Start at top-left corner

	delay(500);
	screen_.clearDisplay();

	screen_.print(F("AM"));
	screen_.drawBitmap(50, 0, alarm_bell, 17, 16, 1);
	screen_.setCursor(75, 0);
	screen_.print(F("1"));
	screen_.setCursor(95, 0);
	screen_.print(F("2"));
	screen_.setCursor(115, 0);
	screen_.print(F("3"));
	
	screen_.display();
}

//dir_ will be controller input for number or up/down, set to zero for first round through to highlight none of them
uint8_t OLED::updateProgMenu(uint8_t dirInput)
{
	screen_.setTextSize(1);      // Normal 1:1 pixel scale
	screen_.setTextColor(WHITE); // Draw white text
	screen_.cp437(true);         // Use full 256 char 'Code Page 437' font
	screen_.setCursor(15, 0);     // Start at top-left corner

	delay(500);
	screen_.clearDisplay();
	screen_.writeFillRect(0, 11, 128, 2, 1);
	screen_.print(F("Programming Mode"));
	screen_.setCursor(0, 16);
	screen_.print(F("1) Alarms"));

	screen_.setCursor(0, 26);
	screen_.print(F("2) Time"));
	screen_.setCursor(0, 36);
	screen_.print(F("3) Date"));
	screen_.setCursor(0, 46);
	screen_.print(F("4) Night Light"));
	screen_.setCursor(0, 56);
	screen_.print(F("5) Brightness"));
	
	if(dirInput == 13)							//move up
		--dir_;
	else if(dirInput == 11)						//move down
		++dir_;
	else if(dirInput >= 1 || dirInput <= 5)		//set to number
		dir_ == dirInput;

	if(dir_ < 1)		//range checking, wrap around
		dir_ = 5;
	else if (dir_ > 5)
		dir_ = 1;

	if(dir_ == 1)
		screen_.writeFillRect(0, 16, 128, 9, 2);
	if(dir_ == 2)
		screen_.writeFillRect(0, 25, 128, 9, 2);
	if(dir_ == 3)
		screen_.writeFillRect(0, 35, 128, 9, 2);
	if(dir_ == 4)
		screen_.writeFillRect(0, 45, 128, 10, 2);
	if(dir_ == 5)
		screen_.writeFillRect(0, 55, 128, 9, 2);

	screen_.display();
	return dir_;
}

void OLED::updateProgAlarm()  //instead of programming empty ones to say "NONE", set to Monday at 7 am
{
	screen_.setTextSize(2);
	screen_.setTextColor(WHITE);
	screen_.cp437(true);
	screen_.setCursor(0, 0);

	int num = 2;   //start with alarm 1, then shift through all info
	delay(500);
	screen_.clearDisplay();
	screen_.print(F("< Alarm"));
	screen_.print((num));
	screen_.print(F(" >"));

	screen_.setTextSize(1);  //print days and time (unique input based on alarm 1, 2 or 3)

	screen_.setCursor(0, 20);
	screen_.print(F("Days:"));
	screen_.setCursor(40, 20);
	screen_.print(F("SuMoTuWeThFrSa"));

	screen_.setCursor(0, 36);
	screen_.print(F("Time:"));
	screen_.setCursor(40, 36);
	screen_.print(F("7:00 AM"));


	screen_.setCursor(10, 55);    //print at bottom and use inverse rectangle to select with remote input
	screen_.print(F("Preview"));
	screen_.setCursor(85, 55);
	screen_.print(F("Edit"));
	screen_.writeLine(65, 53, 65, 63, 1);
	screen_.writeLine(0, 53, 127, 53, 1);
	
	screen_.writeFillRect(0, 54, 65, 10, 2);    //highlight preview
	screen_.writeFillRect(66, 54, 127, 10, 2);  //highlight edit

	screen_.display();
}

void OLED::updateProgDay()
{
	screen_.setTextSize(1);      // Normal 1:1 pixel scale
	screen_.setTextColor(WHITE); // Draw white text
	screen_.cp437(true);         // Use full 256 char 'Code Page 437' font
	screen_.setCursor(0, 0);     // Start at top-left corner

	int num = 2;
	delay(500);
	screen_.clearDisplay();
	screen_.writeFillRect(0, 11, 128, 2, 1);
	screen_.print(F("Alarm "));
	screen_.print(num);
	screen_.print(F(" - Days"));

	screen_.setTextSize(2);
	screen_.setCursor(15, 16);
	screen_.print(F("Mo Tu We"));
	screen_.setCursor(35, 33);
	screen_.print(F("Th Fr"));
	screen_.setCursor(35, 50);
	screen_.print(F("Sa Su"));

	//screen_.writeFillRect(10, 16, 32, 15, 2);  //Mo
	//screen_.writeFillRect(45, 16, 32, 15, 2);  //Tu
	//screen_.writeFillRect(80, 16, 32, 15, 2);  //We
	//screen_.writeFillRect(30, 32, 32, 16, 2);  //Th
	//screen_.writeFillRect(65, 32, 32, 16, 2);  //Fr
	//screen_.writeFillRect(30, 49, 32, 15, 2);  //Sa
	//screen_.writeFillRect(65, 49, 32, 15, 2);  //Su
	
	//consider empty fill box when making selection
	//left and right movement only
	
	screen_.display();
}

void OLED::updateProgTime()
{
  screen_.setTextSize(1);      // Normal 1:1 pixel scale
  screen_.setTextColor(WHITE); // Draw white text
  screen_.cp437(true);         // Use full 256 char 'Code Page 437' font
  screen_.setCursor(0, 0);     // Start at top-left corner

  int num = 2;
  delay(500);
  screen_.clearDisplay();
  screen_.writeFillRect(0, 11, 128, 2, 1);
  screen_.print(F("Alarm "));
  screen_.print(num);
  screen_.print(F(" - Time"));

  screen_.setTextSize(3);
  screen_.setCursor(17, 20);
  screen_.print(F("12:00"));

  screen_.setTextSize(2);
  screen_.setCursor(27, 48);
  screen_.print(F("AM  PM"));

  //screen_.writeFillRect(16, 19, 15, 25, 2);  //1
  //screen_.writeFillRect(32, 19, 20, 25, 2);  //2
  //screen_.writeFillRect(67, 19, 20, 25, 2);  //3
  //screen_.writeFillRect(88, 19, 20, 25, 2);  //4
  //screen_.writeFillRect(22, 46, 30, 17, 2);  //AM
  //screen_.writeFillRect(72, 46, 30, 17, 2);  //PM

  screen_.display();
}

void OLED::updateProgLight()
{
	screen_.setTextSize(1);      // Normal 1:1 pixel scale
	screen_.setTextColor(WHITE); // Draw white text
	screen_.cp437(true);         // Use full 256 char 'Code Page 437' font
	screen_.setCursor(0, 0);     // Start at top-left corner

	int num = 2;
	delay(500);
	screen_.clearDisplay();
	screen_.writeFillRect(0, 11, 128, 2, 1);
	screen_.print(F("Alarm "));
	screen_.print(num);
	screen_.print(F(" - Time"));

	screen_.setCursor(0, 16);
	screen_.print(F("1) Off"));
	screen_.setCursor(0, 28);
	screen_.print(F("2) Solid"));
	screen_.setCursor(0, 40);
	screen_.print(F("3) Blink"));
	screen_.setCursor(0, 52);
	screen_.print(F("4) Smooth"));
	screen_.setCursor(65, 16);
	screen_.print(F("5) FadeU"));
	screen_.setCursor(65, 28);
	screen_.print(F("6) FadeD"));
	screen_.setCursor(65, 40);
	screen_.print(F("7) Switch"));
	screen_.setCursor(65, 52);
	screen_.print(F("8) Rainbow"));

	//screen_.writeFillRect(0, 16, 12, 10, 2);  //1
	//screen_.writeFillRect(0, 27, 12, 10, 2);  //2
	//screen_.writeFillRect(0, 38, 12, 10, 2);  //3
	//screen_.writeFillRect(0, 50, 12, 10, 2);  //4
	//screen_.writeFillRect(64, 16, 12, 10, 2);  //5
	//screen_.writeFillRect(64, 27, 12, 10, 2);  //6
	//screen_.writeFillRect(64, 38, 12, 10, 2);  //7
	//screen_.writeFillRect(64, 50, 12, 10, 2);  //8

	screen_.display();
}

void OLED::updateProgLight2()
{
	screen_.setTextSize(2);      // Normal 1:1 pixel scale
	screen_.setTextColor(WHITE); // Draw white text
	screen_.cp437(true);         // Use full 256 char 'Code Page 437' font
	screen_.setCursor(0, 0);     // Start at top-left corner

	int num = 2;
	delay(500);
	screen_.clearDisplay();

	screen_.setCursor(8, 20);
	screen_.print(F("< COLOR >"));
	screen_.setCursor(2, 45);
	screen_.print(F("< BRIGHT >"));
	//screen_.print(F("  BRIGHT >"));
	//screen_.print(F("< BRIGHT"));


	//screen_.writeFillRect(0, 16, 127, 22, 2);  //color
	//screen_.writeFillRect(0, 41, 127, 22, 2);  //bright

	screen_.display();
}

void OLED::updateProgBuzzer()
{
	screen_.setTextSize(1);      // Normal 1:1 pixel scale
	screen_.setTextColor(WHITE); // Draw white text
	screen_.cp437(true);         // Use full 256 char 'Code Page 437' font
	screen_.setCursor(0, 0);     // Start at top-left corner

	int num = 2;
	delay(500);
	screen_.clearDisplay();
	screen_.writeFillRect(0, 11, 128, 2, 1);
	screen_.print(F("Alarm "));
	screen_.print(num);
	screen_.print(F(" - Buzzer"));

	screen_.setCursor(0, 16);
	screen_.print(F("1) Off"));
	screen_.setCursor(0, 28);
	screen_.print(F("2) Beep"));
	screen_.setCursor(0, 40);
	screen_.print(F("3) Beepx2"));
	screen_.setCursor(0, 52);
	screen_.print(F("4) Beepx3"));

	screen_.setCursor(65, 16);
	screen_.print(F("5) Fast"));
	screen_.setCursor(65, 28);
	screen_.print(F("6) Range"));
	screen_.setCursor(65, 40);
	screen_.print(F("7) Tune 1"));
	screen_.setCursor(65, 52);
	screen_.print(F("8) Tune 2"));

	//screen_.writeFillRect(0, 16, 12, 10, 2);  //1
	//screen_.writeFillRect(0, 27, 12, 10, 2);  //2
	//screen_.writeFillRect(0, 38, 12, 10, 2);  //3
	//screen_.writeFillRect(0, 50, 12, 10, 2);  //4
	//screen_.writeFillRect(64, 16, 12, 10, 2);  //5
	//screen_.writeFillRect(64, 27, 12, 10, 2);  //6
	//screen_.writeFillRect(64, 38, 12, 10, 2);  //7
	//screen_.writeFillRect(64, 50, 12, 10, 2);  //8

	screen_.display();
}

void OLED::updateProgBuzzer2()
{
	screen_.setTextSize(2);      // Normal 1:1 pixel scale
	screen_.setTextColor(WHITE); // Draw white text
	screen_.cp437(true);         // Use full 256 char 'Code Page 437' font
	screen_.setCursor(0, 0);     // Start at top-left corner

	int num = 2;
	delay(500);
	screen_.clearDisplay();

	screen_.setCursor(8, 30);
	screen_.print(F("< PITCH >"));
	//screen_.print(F("  PITCH >"));
	//screen_.print(F("< PITCH"));

	screen_.writeFillRect(0, 26, 127, 22, 2);  //color

	screen_.display();
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

