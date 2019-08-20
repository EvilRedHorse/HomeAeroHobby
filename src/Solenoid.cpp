#include <Solenoid.h>
#include <Arduino.h>

Solenoid::Solenoid() {
}

void Solenoid::Init(int pin) {
    _active = false;
    _pin = pin;
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, 0);
}

bool Solenoid::IsActive() {
    return _active;
}

void Solenoid::On() {
    digitalWrite(_pin, 1);
    _active = true;
    Serial.println("Turning Misters On!");
}

void Solenoid::Off() {
    digitalWrite(_pin, 0);
    _active = false;
    Serial.println("Turning Misters Off!");
}