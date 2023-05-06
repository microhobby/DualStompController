#ifndef INIT_H
#define INIT_H

#include <boost/preprocessor/repetition/repeat.hpp>
#include <FootSwitch.h>
#include <LED.h>

#define _SANITY_TIME   50
#define _GET_FOOTSWITCH(i) FOOT_SWITCH##i

#define REGISTER_FOOTSWITCH(z, i, j) \
    FootSwitch* foot##i = new FootSwitch(i, FOOT_SWITCH##i);

#define REGISTER_FOOTSWITCHES(_x) \
    BOOST_PP_REPEAT(_x, REGISTER_FOOTSWITCH, 0)

/* yeah I know it's smells bad */
/* but it's needed because leds are not in the linear form */
#define __f(x) ((x >= 0 && x <= 4) ? (9 - x) : ((x >= 5 && x <= 9) ? (x - 5) : 0))

#define REGISTER_LED(z, i, j) \
    LED* led##i = new LED(__f(i));

#define REGISTER_LEDS(_x) \
    BOOST_PP_REPEAT(_x, REGISTER_LED, 0)

#define INIT_LED(z, i, j) \
    led##i->turnOff(); \
    led##i->setColor(0, 255, 0); \
    foot##i->setLED(led##i);

#define INIT_LEDS(_x) \
    BOOST_PP_REPEAT(_x, INIT_LED, 0)

#define SANITY_LED(z, i, j) \
    led##i->turnOn(); \
    delay(_SANITY_TIME); \
    led##i->turnOff(); \
    delay(_SANITY_TIME);

#define SANITY_LEDS(_x) \
    BOOST_PP_REPEAT(_x, SANITY_LED, 0)

#define READ_FOOTSWITCH(z, i, j) \
    foot##i->toggle();

#define READ_FOOTSWITCHES(_x) \
    BOOST_PP_REPEAT(_x, READ_FOOTSWITCH, 0)

#define INIT_FOOTSWITCH(z, i, j) \
    pinMode(FOOT_SWITCH##i, INPUT_PULLUP); \
    foot##i->setActiveAction([]() { \
        Serial.print("ac:"); \
        Serial.print(#i); \
        Serial.println(";"); \
    }); \
    foot##i->setDeactiveAction([]() { \
        Serial.print("dac:"); \
        Serial.print(#i); \
        Serial.println(";"); \
    });

#define INIT_FOOTSWITCHES(_x) \
    BOOST_PP_REPEAT(_x, INIT_FOOTSWITCH, 0)

#endif // INIT_H
