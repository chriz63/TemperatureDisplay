#ifndef WiFiAP_h
#define WiFiAP_h

#include "Arduino.h"

class WiFiAP
{
    private:
        String ssidAP;
        String passwordAP;

    public:
        WiFiAP(String ssid, String password);
        void Start();
        void Stop();
        String GetIP();
};

#endif