#include "Display.h"
#include "Sensor.h"

#include "Arduino.h"
#include "Wire.h"
#include "U8g2lib.h"

U8G2_SH1106_128X64_NONAME_F_HW_I2C 
u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

Display::Display(long on, long off, Sensor sensor) {
    onTime = on;
    offTime = off;
    displayState = "WiFiPage";
}

void Display::Start() {
    u8g2.begin();
}

void Display::ShowStartPage() {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_7x14B_tf);
    u8g2.drawStr(35,25, "Starting");
    u8g2.drawStr(20,40, "Please wait...");
    u8g2.sendBuffer();
};

void Display::ShowWiFiPage() {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_7x14B_tf);
    u8g2.drawStr(0,10, "Web UI");
    u8g2.drawStr(0,25, "IP:");
    u8g2.drawStr(20,25, "0.0.0.0");
    u8g2.sendBuffer();
}

void Display::ShowDataPage() {
    String temperature = String(sensor.GetTemperature()) + " °C";
    String humidity = String(sensor.GetHumidity()) + " %";
    const char* temp = temperature.c_str();
    const char* hum = humidity.c_str();
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_7x14B_tf);
    u8g2.drawUTF8(0,10, "Temperature");
    u8g2.drawUTF8(0,25, temp);
    u8g2.drawUTF8(0,40, "Humidity ");
    u8g2.drawUTF8(0,55, hum);
    u8g2.sendBuffer();
}

void Display::Update() {
    unsigned long currentMillis = millis();
    if ((displayState == "WiFiPage") && (currentMillis - previousMillis >= onTime))
    {
        displayState = "DataPage";
        previousMillis = currentMillis;
        Display::ShowWiFiPage();
    }
    else if ((displayState == "DataPage") && (currentMillis - previousMillis >= onTime))
    {
        displayState = "WiFiPage";
        previousMillis = currentMillis;
        Display::ShowDataPage();
    }
}