# ArduinoLightClock
Button-less Arduino clock with tri-color LEDs


All of the libraries and references used for this project are included below for easy setup.
I also included an over-detailed set-up description below.

Materials:
Aruidno of choice
4-Digit 7-Segment Display
Piezo Buzzer (Passive)
Temperature and Humidity Module (DHT)
OLED Display ()
IR Sensor/Reciever
Tri-Colored LEDs
Breadboard/Perf-Board (for prototyping)
Wires/Jumper-Cables
Arduino Remote (Elegoo)
3 100-330 ohm resistors

(If you don't have or don't wish to include any of the above modules (such as the DHT module), follow the comments in the main Arduino file to remove them).


**Important Notes:**
This code was initially written for the Arduino Nano and then converted for the Arduino Pro Micro.  I have included links to the Amazon pages I bought them from.  I included code for the Arduino Uno, however it is mostly similar to the code for the Nano.

I also inlucded links to all of the sensors I used and their data sheets (if I could find them).  Some of the libraries/code I used may not be compatible with other sensors, however, I will try to make the documentation as clear as possible so that adjustments and substitutions can be made easily (for example, RTClib.h has example code for other modules if you aren't using the same ds3231 module I used).


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

(Links for making custom bitmap:)
https://www.youtube.com/watch?v=iy89vaeMOPY&list=WL&index=51&t=0s
http://marlinfw.org/tools/u8glib/converter.html
https://gist.github.com/ArnauMA/15a9b70538f37dddd3ad32844a634ccb


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













