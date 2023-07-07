#include "WiFiAP.h"

#include "Arduino.h"
#include "ESP8266WiFi.h"

WiFiAP::WiFiAP(String ssid, String password)
{
    ssidAP = ssid;
    passwordAP = password;

    IPAddress ip(10,0,0,1);
    IPAddress gateway(10,0,0,1);
    IPAddress subnet(255,255,255,0);

    WiFi.softAPConfig(ip, gateway, subnet);
}

void WiFiAP::Start() {
    WiFi.softAP(ssidAP, passwordAP);
};

String WiFiAP::GetIP() {
    return WiFi.softAPIP().toString();
}