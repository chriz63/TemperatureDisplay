#include "WiFiService.h"
#include "WiFiSTA.h"
#include "WiFiAP.h"

WiFiService::WiFiService() {}

WiFiService::WiFiService(Display display) {}

void WiFiService::APMode() {
    isAp = true;
    isSta = false;

    WiFiAP accessPoint("ESP8266", "!1q2w3e4R!");

    display.ShowApStartingPage();

    accessPoint.Start();

    display.SetWiFiData("ESP8266", "!1q2w3e4R!", accessPoint.GetIP());
};

void WiFiService::STAMode() {
    isSta = true;
    isAp = false;

    WiFiSTA wifiClient("ssid", "password");
    
    display.ShowStaConnectingPage();

    wifiClient.Start();

    display.SetWiFiData("ssid", "password", wifiClient.GetIP());
};