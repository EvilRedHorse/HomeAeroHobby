#include <WaterLevelSensor.h>

WaterLevelSensor::WaterLevelSensor() {}

void WaterLevelSensor::Init(int pin, int led, int lowWaterLevel) {
    _pin = pin;
    _led = led;
    _lowWaterLevel = lowWaterLevel;
    _waterLevel = 0;
}

void WaterLevelSensor::Read() {
    _waterLevel = analogRead(_pin);

    if(_waterLevel < _lowWaterLevel) {
        Serial.println("Water Level Low!");
        ActivateLed(true);
    }
    else
        ActivateLed(false);

    Serial.print("Water Level: ");
    Serial.println(_waterLevel);
}

void WaterLevelSensor::ActivateLed(bool activate) {
    if(activate) {
        digitalWrite(_led, 1);
    }

    if(!activate) {
        digitalWrite(_led, 0);
    }
}