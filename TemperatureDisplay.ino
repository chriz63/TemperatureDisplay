// Project TemperatureDisplay based on NodeMCU with DHT22 Sensor and SH1106 128X64 Display

// All imports that are needed
#include "Arduino.h"
#include "LED.h"

// Indicates that the system is on 
// turn on and off every 1000 milliseconds
LED systemLED(2, 1000, 1000);

// Initialize all that is needed
void setup() {
    Serial.begin(115200);
}

// Run the program 
void loop() {
    systemLED.Update();
}