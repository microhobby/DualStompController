#include <FootSwitch.h>

FootSwitch::FootSwitch(int index, int pin)
{
    this->_index = index;
    this->_pin = pin;
    this->_activated = false;
    this->_active = NULL;
    this->_deactive = NULL;
    this->_lastState = HIGH;
}

FootSwitch::~FootSwitch()
{
}

bool FootSwitch::isPressed()
{
    int state = digitalRead(this->_pin);

    if (state != this->_lastState) {
        this->_lastState = state;

        if (state == LOW) {
            return true;
        }
    }

    return false;
}

void FootSwitch::setActiveAction(void (*action)())
{
    this->_active = action;
}

void FootSwitch::setDeactiveAction(void (*action)())
{
    this->_deactive = action;
}

void FootSwitch::setLED(LED* led)
{
    this->_led = led;
}

void FootSwitch::toggle()
{
    if (this->isPressed())
    {
        if (!this->_activated)
        {
            this->_activated = true;
            this->_led->turnOn();

            if (this->_active != NULL)
                this->_active();
        }
        else
        {
            this->_activated = false;
            this->_led->turnOff();

            if (this->_deactive != NULL)
                this->_deactive();
        }
    }
}
