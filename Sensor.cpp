#include "Sensor.h"

#include "Arduino.h"
#include "DHT.h"
#include "Wire.h"
#include "Adafruit_Sensor.h"

#define DHT_TYPE DHT22
const int DHT_PIN = 9;

/*
Initialize the sensor
*/
DHT dht(DHT_PIN, DHT_TYPE);

/*
Default Constructor for Sensor Class

Sensor is being started here
*/
Sensor::Sensor() {
  dht.begin();
}

/*
Returns the temperature as a float
*/
float Sensor::GetTemperature() {
    return dht.readTemperature();
};

/*
Returns the humidity as a float
*/
float Sensor::GetHumidity() {
    return dht.readHumidity();
};