#ifndef WiFiSTA_h
#define WiFiSTA_h

#include "Arduino.h"

class WiFiSTA
{
    private:
        String ssidAP;
        String passwordAP;

    public:
        WiFiSTA(String ssid, String password);
        void Start();
        void Stop();
        String GetIP();
};

#endif