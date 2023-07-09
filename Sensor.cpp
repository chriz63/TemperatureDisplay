#include "Sensor.h"

#include "Arduino.h"
#include "DHT.h"
#include "Wire.h"
#include "Adafruit_Sensor.h"

#define DHT_TYPE DHT22
const int DHT_PIN = 9;

DHT dht(DHT_PIN, DHT_TYPE);

Sensor::Sensor() {
  dht.begin();
}

float Sensor::GetTemperature() {
    return dht.readTemperature();
};

float Sensor::GetHumidity() {
    return dht.readHumidity();
};