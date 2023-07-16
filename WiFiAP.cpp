#include "WiFiAP.h"

#include "Arduino.h"
#include "ESP8266WiFi.h"

WiFiAP::WiFiAP(String ssid, String password)
{
    ssidAP = ssid;
    passwordAP = password;
}

void WiFiAP::Start() {

    WiFi.disconnect();
    WiFi.softAPdisconnect();
    
    WiFi.mode(WIFI_AP);

    if(WiFi.softAP(ssidAP, passwordAP) == true)
    {
        Serial.println();
        Serial.println("Access Point is created with SSID: " + ssidAP);
        Serial.println("Access Point IP: " + String(WiFiAP::GetIP()));
    }
    else
    {
        Serial.println("Unable to Create Access Point");
    }
};

String WiFiAP::GetIP() {
    return WiFi.softAPIP().toString();
}