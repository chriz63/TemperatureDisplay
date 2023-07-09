// Project TemperatureDisplay based on NodeMCU with DHT22 Sensor and SH1106 128X64 Display

// All imports that are needed
#include "LED.h"
#include "WiFiAP.h"
#include "WiFiSTA.h"
#include "WebServer.h"

#include "Arduino.h"
#include "ESP8266WiFi.h"
#include "ESPAsyncWebServer.h"

String currentIP;

// Indicates that the system is on turn on and off every 1000 milliseconds
LED systemLED(2, 1000, 1000);
LED secondLED(16, 200, 200);

// Open access point with ssid and password in arguments
WiFiAP accessPoint("TemperatureDisplayWiFi", "!1q2w3e4R!");

//WiFiSTA wifiClient("ssid", "password");

WebServer webServer;

// Initialize all that is needed
void setup() {
    Serial.begin(115200);
    Serial.println("");
    Serial.println("Starting please wait");
    
    //wifiClient.Start();

    // Start access point and remember the current ip
    accessPoint.Start();
    currentIP = accessPoint.GetIP();

    webServer.Configure();
    webServer.Start();
   }

// Run the program 
void loop() {
    systemLED.Update();
    secondLED.Update();
}