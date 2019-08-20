class Solenoid {
    private:
        int _pin;
        bool _active;

    public:
        Solenoid();
        void Init(int pin);
        bool IsActive();
        void On();
        void Off();
};


