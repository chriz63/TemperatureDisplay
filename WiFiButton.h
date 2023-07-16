#ifndef WiFiButton_h
#define WiFiButton_h

#include "Arduino.h"
#include "WiFiService.h"

class WiFiButton
{
    private:
        WiFiService wifiService;
        int buttonPin;
        byte lastButtonState;
        unsigned long debounceDuration;
        unsigned long lastTimeButtonStateChanged;
        bool state;
    public:
        WiFiButton(int buttonPin, WiFiService WiFiService);
        void Observe();
        bool GetState();
};

#endif