/* hardware */
#include <Arduino.h>
#include <defconfig.h>
#include <initialization.h>

REGISTER_FOOTSWITCHES(NUMFOOTSWITCHES);
REGISTER_LEDS(NUMPIXELS);

void setup()
{
    Serial.begin(115200);
    Serial.println("Initializing...");

    pinMode(NEO_LED_PIN, INPUT_PULLUP);
    NEO_LEDS.begin();
    NEO_LEDS.setBrightness(50);
    INIT_LEDS(NUMPIXELS);
    INIT_FOOTSWITCHES(NUMFOOTSWITCHES);

    Serial.println("Sanity check...");
    SANITY_LEDS(NUMPIXELS);
}

void loop()
{
    READ_FOOTSWITCHES(NUMFOOTSWITCHES);
    delay(50);
}
