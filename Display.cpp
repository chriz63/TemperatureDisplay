#include "Display.h"
#include "Sensor.h"

#include "Arduino.h"
#include "Wire.h"
#include "U8g2lib.h"

String ssid = "";
String password = "";
String ip = "";

/*
Initialize the Display
*/
U8G2_SH1106_128X64_NONAME_F_HW_I2C 
u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

/*
Default Constructor for Display Class
*/
Display::Display() {}

/* 
Default Constructor for Display Class
Setting the sensor, on- and offtime for Display

@param Senmsor sensor -> Define a sensor to get temperature data
@param long onTime -> Define a time where display shows data  
@param long offTime -> Define a time where display changes data   
*/
Display::Display(long on, long off, Sensor sensor) {
    onTime = on;
    offTime = off;
    displayState = "WiFiPage";
    displayOn = true;
}

/*
Start the display
*/
void Display::Start() {
    u8g2.begin();
}

/*
Display a starting screen
*/
void Display::ShowStartPage() {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_7x14B_tf);
    u8g2.drawStr(35,25, "Starting");
    u8g2.drawStr(20,40, "Please wait...");
    u8g2.sendBuffer();
};

/*
Display SSID and IP for web ui
*/
void Display::ShowWiFiPage() {
    const char* SSID = ssid.c_str();
    const char* PASSWORD = password.c_str();
    const char* IP = ip.c_str();
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_7x14B_tf);
    u8g2.drawUTF8(0,10, "SSID: ");
    u8g2.drawUTF8(38,10, SSID);
    u8g2.drawUTF8(0,25, "PWD:");
    u8g2.drawUTF8(30,25, PASSWORD);
    u8g2.drawUTF8(0, 40, "IP: ");
    u8g2.drawUTF8(25, 40, IP);
    u8g2.sendBuffer();
}

/*
Display temperature and humidity data on the display

This method gets temperarture data from the sensor
converting them into a c style string, we have to do this to be able to 
display the data on the display
*/
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

void Display::ShowStaConnectingPage() {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_7x14B_tf);
    u8g2.drawStr(20,25, "Please wait...");
    u8g2.drawStr(0,40, "Connecting to WiFi");
    u8g2.sendBuffer();
}

void Display::ShowApStartingPage() {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_7x14B_tf);
    u8g2.drawStr(20,25, "Please wait...");
    //u8g2.drawStr(0,40, "Connecting to WiFi");
    u8g2.drawStr(10,40, "AP is starting");
    u8g2.sendBuffer();
}

/*
Update the Display
Display data for given on- and offtimes from constructor

NodeMCU is based on a single core processor because of this there is no way for a multithreading procedure
We have to remember the on- and off times and update the ledState, so multiple LED's can blink simultaneously with various time
*/
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

/*
Turn the display on
*/
void Display::TurnOn() {
    u8g2.setPowerSave(0);
};

/*
Turn the display off
*/
void Display::TurnOff() {
    u8g2.setPowerSave(1);
};

void Display::SetWiFiData(String SSID, String PASSWD, String IP) {
    ssid = SSID;
    password = PASSWD;
    ip = IP;
}
