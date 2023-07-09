#ifndef WebServer_h
#define WebServer_h

#include "Arduino.h"
#include "ESPAsyncWebServer.h"

class WebServer
{
    private:
        int webserverPort;

    public:
        WebServer();
        void Configure();
        void Start();
};

#endif