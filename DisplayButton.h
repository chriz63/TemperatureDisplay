#ifndef DisplayButton_h
#define DisplayButton_h

#include "Arduino.h"
#include "Display.h"

class DisplayButton
{
    private:
        Display display;
        int buttonPin;
        byte lastButtonState;
        unsigned long debounceDuration;
        unsigned long lastTimeButtonStateChanged;
        bool state;
    public:
        DisplayButton(int buttonPin, Display display);
        void Observe();
        bool GetState();
};

#endif