#include <Arduino.h>

#include <DHT.h>
#include <Solenoid.h>
#include <WaterLevelSensor.h>
#include <WaterPressureSensor.h>

#define DHTPIN 2
#define DHTTYPE DHT11

class HomeAeroHobby {
    private:
        // Time Keeping
        uint32_t _sensorStartTime;
        uint32_t _actionStartTime;
        uint32_t _currentTime;
        uint32_t _actionTime;
        uint32_t _restInterval;
        uint32_t _actionInterval;
        uint32_t _sensorInterval;

        // Temp & Humidity
        // DHT _dht;
        // int _dhtPin;
        // int _dhtType;
        // float _temperature;
        // float _humidity;

        // Solenoid
        Solenoid _valve;
        int _solenoidPin;

        // Water Level
        WaterLevelSensor _waterSensor;
        int _waterLevelPin;

        // Water Pressure
        WaterPressureSensor _pressureSensor;
        int _waterPressurePin;

    public:
        HomeAeroHobby();
        void Init(int solenoidPin, int waterLevelPin, int waterPressurePin,
            int waterLevelLed, int waterPressureLed);
        void SetCurrentTime(uint32_t time);
        void SetSensorTime(uint32_t time);
        void SetActionTime(uint32_t time);
        uint32_t GetCurrentTime();
        uint32_t GetSensorTime();
        uint32_t GetActionTime();
        uint32_t GetRestInterval();
        uint32_t GetActionInterval();
        uint32_t GetSensorInterval();
        void ReadSensors();
        bool ValveIsActive();
        void ActivateMisters(bool activate);
};