#ifndef Display_h
#define Display_h

#include "Arduino.h"
#include "Sensor.h"

class Display
{   
    private:
        Sensor sensor;
        long onTime;
        long offTime;
        unsigned long previousMillis;
        String displayState;

    public:
        Display(long onTime, long offTime, Sensor sensor);
        void Start();
        void ShowStartPage();
        void ShowWiFiPage();
        void ShowDataPage();
        void Update();
};

#endif