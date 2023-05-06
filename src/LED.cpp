#include <LED.h>

LED::LED(int index)
{
    this->_index = index;
    this->turnOff();
}

void LED::setColor(int r, int g, int b)
{
    this->_r = r;
    this->_g = g;
    this->_b = b;

    if (this->_isOn) 
    {
        this->turnOn();
    }
}

void LED::turnOff()
{
    this->_isOn = false;
    NEO_LEDS.setPixelColor(this->_index, 0, 0, 0);
    NEO_LEDS.show();
}

void LED::turnOn()
{
    this->_isOn = true;
    NEO_LEDS.setPixelColor(this->_index, this->_r, this->_g, this->_b);
    NEO_LEDS.show();
}

bool LED::isOn()
{
    return this->_isOn;
}

LED::~LED()
{
}
