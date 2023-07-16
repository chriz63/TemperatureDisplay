#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"

/*
Default Constructor for Sensor Class
*/
class Sensor
{   
    public:
        Sensor();
        float GetTemperature();
        float GetHumidity();
};

#endif