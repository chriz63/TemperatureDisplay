// Project TemperatureDisplay based on NodeMCU with DHT22 Sensor and SH1106 128X64 Display

// All imports that are needed
#include "LED.h"
#include "WiFiAP.h"

#include "Arduino.h"

String currentIP;

// Indicates that the system is on turn on and off every 1000 milliseconds
LED systemLED(2, 1000, 1000);
WiFiAP accessPoint("TemperatureDisplayWiFi", "!1q2w3e4R!");

// Initialize all that is needed
void setup() {
    Serial.begin(115200);

    // Start access point and remember the current ip
    accessPoint.Start();
    currentIP = accessPoint.GetIP();
}

// Run the program 
void loop() {
    systemLED.Update();
}