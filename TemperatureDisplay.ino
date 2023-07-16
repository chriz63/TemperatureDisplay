// Project TemperatureDisplay based on NodeMCU with DHT22 Sensor and SH1106 128X64 Display

// All imports that are needed
#include "LED.h"
#include "Display.h"
#include "DisplayButton.h"
#include "WiFiService.h"
#include "WiFiButton.h"
#include "WebServer.h"
#include "Sensor.h"


#include "Arduino.h"
#include "ESP8266WiFi.h"
#include "ESPAsyncWebServer.h"

String currentIP;

// Indicates that the system is on turn on and off every 1000 milliseconds
LED systemLED(2, 1000, 1000);

Sensor sensor;

Display display(2000,100, sensor);

DisplayButton displayButton(0, display);

WiFiService wifiService(display);

WiFiButton wifiButton(14, wifiService);

WebServer webServer(sensor);

// Initialize all that is needed
void setup() {
    Serial.begin(115200);

    display.Start();
    display.ShowStartPage();

    Serial.println("");
    Serial.println("Starting please wait");

    // Start in STA Mode for default
    // this mode can be changed later by pressing a button
    wifiService.APMode();

    webServer.Configure();
    webServer.Start();
   }

// Run the program 
void loop() {
    systemLED.Update();
    display.Update();
    webServer.Update();
    displayButton.Observe();
    wifiButton.Observe();
}