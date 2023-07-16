#ifndef WiFiService_h
#define WiFiService_h

#include "Arduino.h"
#include "Display.h"

class WiFiService
{   private:
        bool isAp;
        bool isSta;
        Display display;

    public:
        WiFiService();
        WiFiService(Display display);
        void ChangeWiFiMode();
        void APMode();
        void STAMode();
};

#endif