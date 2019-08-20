#include <WaterPressureSensor.h>

WaterPressureSensor::WaterPressureSensor() {}

void WaterPressureSensor::Init(int pin, int led, float offset, float lowPressure) {
    _pin = pin;
    _led = led;
    _lowPressure = lowPressure;
    _offset = offset;
}

void WaterPressureSensor::Read() {
    _voltage = analogRead(_pin) * 5.00 / 1024;
    _kpaPressure = (_voltage - _offset) * 400;
    _psiPressure = _kpaPressure / 6.895;

    if(_psiPressure < _lowPressure) {
        Serial.println("System Pressure Low!");
        ActivateLed(true);
    }
    else
        ActivateLed(false);

    Serial.print("Water Pressure: ");
    Serial.print(_kpaPressure);
    Serial.print(" KPa, ");
    Serial.print(_psiPressure);
    Serial.println(" psi");
}

void WaterPressureSensor::ActivateLed(bool activate) {
    if(activate) {
        digitalWrite(_led, 1);
    }

    if(!activate) {
        digitalWrite(_led, 0);
    }
}