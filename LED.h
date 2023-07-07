#ifndef LED_h
#define LED_h

#include "Arduino.h"

/* 
Default Constructor for LED Class
Setting the pin, on- and offtime for LED
Setting the mode for pin as output
@param int pin -> Define a pin for the LED
@param long onTime -> Define a time where the LED on 
@param long offTime -> Define a time where the LED off
*/
class LED 
{
    private:
        int ledPin;
        long onTime;
        long offTime;
        unsigned long previousMillis;
        int ledState;
        
    public:
        LED(int pin, long on, long off);
        void Update();
        void TurnOff();
        void TurnOn();
};

#endif
