#include "DisplayButton.h"
#include "Display.h"

#include "Arduino.h"

/* 
Default Constructor for DisplayButton Class
Setting the pin for the Button and the Display

@param int pin -> Define a pin for the Button 
@param Display display -> Define a Display to interact with  
*/
DisplayButton::DisplayButton(int pin, Display display)
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
void DisplayButton::Observe() {
    if (millis() - lastTimeButtonStateChanged > debounceDuration) {
      byte buttonState = digitalRead(buttonPin);
      if (buttonState != lastButtonState) {
      lastTimeButtonStateChanged = millis();
      lastButtonState = buttonState;
      if (buttonState == LOW) {
        if (state == LOW)
        {
            state = HIGH;
            display.TurnOff();
            Serial.println("Display turned off");
        }
        else if (state == HIGH)
        {
            state = LOW;
            display.TurnOn();
            Serial.println("Display turned on");
        }
      }
    }
  }
}