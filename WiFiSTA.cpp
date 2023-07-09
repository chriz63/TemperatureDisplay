#include "WiFiSTA.h"

#include "Arduino.h"
#include "ESP8266WiFi.h"

WiFiSTA::WiFiSTA(String ssid, String password)
{
    ssidAP = ssid;
    passwordAP = password;
}

void WiFiSTA::Start() {
    WiFi.begin(ssidAP, passwordAP);

    Serial.println("");
    Serial.println("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.print("Connected, IP address: ");
    Serial.println(WiFiSTA::GetIP());
};

String WiFiSTA::GetIP() {
    return WiFi.localIP().toString();
}