#ifndef Display_h
#define Display_h

#include "Arduino.h"
#include "Sensor.h"

/* 
Default Constructor for Display Class
Setting the sensor, on- and offtime for Display
@param Senmsor sensor -> Define a sensor to get temperature data
@param long onTime -> Define a time where display shows data  
@param long offTime -> Define a time where display changes data   
*/
class Display
{   
    private:
        Sensor sensor;
        long onTime;
        long offTime;
        unsigned long previousMillis;
        String displayState;
        bool displayOn;

    public:
        Display();
        Display(long onTime, long offTime, Sensor sensor);
        void Start();
        void ShowStartPage();
        void ShowWiFiPage();
        void ShowDataPage();
        void ShowApStartingPage();
        void ShowStaConnectingPage();
        void Update();
        void TurnOn();
        void TurnOff();
        void SetWiFiData(String SSID, String PASSWD, String IP);
};

#endif