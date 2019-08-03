#ifndef __LED_FUNCTIONS_H
#define __LED_FUNCTIONS_H

#include <Arduino.h>

class LED
{
  private:
    int red;
    int orange;
    int yellow;
    int green;
    int teal;
    int blue;
    int violet;
    int pink;
    int white;
    int off;

  public:
    //include param for delay time when blinking (or how fast to fade)
    void colorWrite();
    void allOff();
    void speedBlink();  //allow adjustable speeds
    void smoothBlink(); //allow adjustable speeds
    void rainbowFade(); //for all colors only
    void 
};






#endif
