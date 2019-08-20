#include <HomeAeroHobby.h>

HomeAeroHobby::HomeAeroHobby() {}

void HomeAeroHobby::Init(int solenoidPin, int waterLevelPin, int waterPressurePin,
    int waterLevelLed, int waterPressureLed) {
    // Set the pins
    _solenoidPin = solenoidPin;
    _waterLevelPin = waterLevelPin;
    _waterPressurePin = waterPressurePin;

    Serial.println("Pins set!");

    // Set the intial time values
    _sensorStartTime = 0;
    _actionStartTime = 0;
    _currentTime = 0;
    _actionTime = 0;
    _restInterval = 300000;                                                 // Wait 5 Minutes before misting again
    _actionInterval = 4000;                                                 // Wait 4 Seconds before turning the mister off
    _sensorInterval = 60000;                                                // Wait 1 Minute to take a sensor reading

    Serial.println("Times set!");

    // Initialize the other components
    _valve.Init(_solenoidPin);
    _waterSensor.Init(_waterLevelPin, waterLevelLed, 150);                  // Any readings below 150 will be considered "low"
    _pressureSensor.Init(_waterPressurePin, waterPressureLed, 0.483, 80);   // Need to calibrate sensor, Any readings below 80 will be considered "low"

    Serial.println("Valve, Pressure, and Water Level Initialized!");
}

void HomeAeroHobby::SetCurrentTime(uint32_t time) {
    _currentTime = time;
}

void HomeAeroHobby::SetActionTime(uint32_t time) {
    _actionStartTime = time;
}

void HomeAeroHobby::SetSensorTime(uint32_t time) {
    _sensorStartTime = time;
}

uint32_t HomeAeroHobby::GetCurrentTime() {
    return _currentTime;
}

uint32_t HomeAeroHobby::GetSensorTime() {
    return _sensorStartTime;
}

uint32_t HomeAeroHobby::GetActionTime() {
    return _actionStartTime;
}

uint32_t HomeAeroHobby::GetRestInterval() {
    return _restInterval;
}

uint32_t HomeAeroHobby::GetActionInterval() {
    return _actionInterval;
}

uint32_t HomeAeroHobby::GetSensorInterval() {
    return _sensorInterval;
}

void HomeAeroHobby::ReadSensors() {
    // Read values from the sensors
    _waterSensor.Read();
    _pressureSensor.Read();
}

bool HomeAeroHobby::ValveIsActive() {
    return _valve.IsActive();
}

void HomeAeroHobby::ActivateMisters(bool activate) {
    if(activate)
        _valve.On();

    if(!activate)
        _valve.Off();
}