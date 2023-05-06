#ifndef LED_H
#define LED_H

#include <defconfig.h>

static Adafruit_NeoPixel NEO_LEDS =
    Adafruit_NeoPixel(NUMPIXELS, NEO_LED_PIN, NEO_GRB + NEO_KHZ800);

class LED
{
private:
    int _index;
    bool _isOn;
    int _r;
    int _g;
    int _b;

public:
    LED(int index);
    void setColor(int r, int g, int b);
    void turnOn();
    void turnOff();
    bool isOn();
    ~LED();
};

#endif // LED_H
