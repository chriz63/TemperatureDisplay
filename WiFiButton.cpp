#include "WiFiButton.h"
#include "Display.h"

#include "Arduino.h"

/* 
Default Constructor for WiFiButton Class
Setting the pin for the Button and the WiFiService

@param int pin -> Define a pin for the Button 
@param WiFiService service -> Set the WiFiService  
*/
WiFiButton::WiFiButton(int pin, WiFiService service)
{
    buttonPin = pin;
    lastButtonState = LOW;
    debounceDuration = 50;
    lastTimeButtonStateChanged = 0;
    state = LOW;
    pinMode(buttonPin, INPUT);
}

/*
Obvserve the Button
Change the state if button is pressed and turn the Display on or off
*/
void WiFiButton::Observe() {
    if (millis() - lastTimeButtonStateChanged > debounceDuration) {
      byte buttonState = digitalRead(buttonPin);
      if (buttonState != lastButtonState) {
      lastTimeButtonStateChanged = millis();
      lastButtonState = buttonState;
      if (buttonState == LOW) {
        if (state == LOW)
        {
            Serial.println("Button pressed");
            state = HIGH;
            wifiService.STAMode();
            Serial.println("WiFi Mode changed to STA");
        }
        else if (state == HIGH)
        {   
            Serial.println("Button pressed");
            state = LOW;
            wifiService.APMode();
            Serial.println("WiFi Mode changed to AP");
        }
      }
    }
  }
}