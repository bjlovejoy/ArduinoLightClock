#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 screen(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const unsigned char alarm_bell[] PROGMEM = {
  B00000001,B10000000,B00000000,
  B00000011,B11000000,B00000000,
  B00000111,B11100000,B00000000,
  B00001100,B00110000,B00000000,
  B00001000,B00010000,B00000000,
  B00011000,B00011000,B00000000,
  B00011000,B00011000,B00000000,
  B00011000,B00011000,B00000000,
  B00011000,B00011000,B00000000,
  B00010000,B00001000,B00000000,
  B00110000,B00001100,B00000000,
  B01110000,B00001110,B00000000,
  B01100000,B00000110,B00000000,
  B00111111,B11111100,B00000000,
  B00000011,B11000000,B00000000,
  B00000001,B10000000,B00000000 
};

void setup()
{
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!screen.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
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

void loop()
{

}
