#ifndef FOOTSWITCH_H
#define FOOTSWITCH_H

#include <defconfig.h>
#include <LED.h>

class FootSwitch
{
private:
    int _index;
    int _pin;
    bool _activated;
    void (*_active)();
    void (*_deactive)();
    LED* _led;
    int _lastState;

public:
    FootSwitch(int index, int pin);
    bool isPressed();
    void setActiveAction(void (*action)());
    void setDeactiveAction(void (*action)());
    void toggle();
    void setLED(LED* led);
    ~FootSwitch();
};

#endif // FOOTSWITCH_H
