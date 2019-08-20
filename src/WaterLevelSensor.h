#include <Arduino.h>

class WaterLevelSensor {
    private:
        int _pin;
        int _led;
        int _lowWaterLevel;
        float _waterLevel;
        void ActivateLed(bool activate);

    public:
        WaterLevelSensor();
        void Init(int pin, int led, int lowWaterLevel);
        void Read();
};