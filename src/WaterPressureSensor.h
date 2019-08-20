#include <Arduino.h>

class WaterPressureSensor {
    private:
        int _pin;
        int _led;
        float _lowPressure;
        float _offset;
        float _voltage;
        float _kpaPressure;
        float _psiPressure;
        void ActivateLed(bool activate);

    public:
        WaterPressureSensor();
        void Init(int pin, int led, float offset, float lowPressure);
        void Read();
};