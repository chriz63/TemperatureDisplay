#include "LED.h"

#include "Arduino.h"

/* 
Default Constructor for LED Class
Setting the pin, on- and offtime for LED
Setting the mode for pin as output

@param int pin -> Define a pin for the LED
@param long onTime -> Define a time where the LED on 
@param long offTime -> Define a time where the LED off
*/
LED::LED(int pin, long on, long off )
{
    ledPin = pin;
    onTime = on;
    offTime = off;
    ledState = LOW;
    previousMillis = 0;

    pinMode(ledPin, OUTPUT);
}

/*
Update the LED
Turn it on and off for given on- and offtimes from constructor

Because on NodeMCU state is inverted LOW = HIGH and HIGH = LOW

NodeMCU is based on a single core processor because of this there is no way for a multithreading procedure
We have to remember the on- and off times and update the ledState, so multiple LED's can blink simultaneously with various time
*/
void LED::Update() {
    unsigned long currentMillis = millis();
    if((ledState == HIGH) && (currentMillis - previousMillis >= onTime))
    {
    	ledState = LOW;  // Turn it ON
        previousMillis = currentMillis;
        digitalWrite(ledPin, ledState);
        //Serial.println("off: " + String(ledPin));
    }
    else if ((ledState == LOW) && (currentMillis - previousMillis >= offTime))
    {
        ledState = HIGH;  // turn it OFF
        previousMillis = currentMillis;
        digitalWrite(ledPin, ledState);
        //Serial.println("on: "  + String(ledPin));
    }
};

/*
Turns off the LED manually
*/
void LED::TurnOff() {
  ledState = HIGH;
  digitalWrite(ledPin, ledState);
};

/*
Turns on the LED manually
*/
void LED::TurnOn() {
  ledState = LOW;
  digitalWrite(ledPin, ledState);
};