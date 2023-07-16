#ifndef WebServer_h
#define WebServer_h

#include "Sensor.h"

#include "Arduino.h"
#include "ESPAsyncWebServer.h"

class WebServer
{
    private:
        Sensor sensor;  
        int webserverPort;
        
    public:
        WebServer(Sensor sensor);
        void Configure();
        void Start();
        void Update();
};

#endif