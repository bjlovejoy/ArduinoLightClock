# ArduinoLightClock
Button-less Arduino clock with tri-color LEDs


All of the libraries and references used are included below for easy setup.
I also included an over-detailed set-up description below.

**Important Notes:**
This code was initially written for the Arduino Nano and then converted for the Arduino Pro Micro.  I have included links to the Amazon page I bought them from.  I included code for the Arduino Uno, however it is mostly similar to the code for the Nano.

I also inlucded links to all of the sensors I used and their data sheets (if I could find them).  Some of the libraries/code I used may not be compatible with other sensors, however, I will try to make the documentation as clear as possible so that adjustments and substitutions can be made easily.

For Arduino Nano:

For Arduino Pro Micro:

For Arduino Uno:




**Tri-Colored LEDs:**

I used common cathode LEDs (1 pin to GND, the other 3 need +5V from Arduino pins to turn on)



**4-Digit 7-Segment Display:**

Used the TM1637 Arduino library by avishorp.
(https://github.com/avishorp/TM1637)


**Real-Time-Clock (RTC) Module:**

Used the RTClib Arduino library by adafruit (a fork of Jeelab's fantastic RTC library).
(https://github.com/adafruit/RTClib


**i2c Information:**

Used i2c_scanner sketch by Nick Gammon to find the i2c addresses of the OLED display and the RTC module.
Here is the Arduino Playground page containing an alternate sketch and a link to Nick Gammon's version and explantation:
(https://playground.arduino.cc/Main/I2cScanner/)
Here is where I got the code that I used:
(http://henrysbench.capnfatz.com/henrys-bench/arduino-projects-tips-and-more/arduino-quick-tip-find-your-i2c-address/)


**OLED Display:**
Used Adafruit SSD1306 and GFX libraries
(https://github.com/adafruit/Adafruit_SSD1306)
(https://github.com/adafruit/Adafruit-GFX-Library)
Change the i2c address in main file to 3C or 3D

**Infra-red Remote and Receiver:**

Used IRremote library by Ken Shirriff
(https://github.com/z3t0/Arduino-IRremote)


**Temperature and Humidity Modules:**

Used SimpleDHT by winlin
(https://github.com/winlinvip/SimpleDHT/)




**LED Error Indicators**
Solid red:       OLED display not working
Blinking red:    RTC module not working
Solid blue:      
Blinking blue:   
Solid green:     
Blinking green:  

//make blue need input, green okay, red warning













