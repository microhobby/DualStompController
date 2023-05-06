#ifndef DEFCONFIG_H
#define DEFCONFIG_H

/* libs */
#include <MIDI.h>
#include <Usb.h>
#include <usbhub.h>
#include <usbh_midi.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

/* FOOT SWITCHES */
#define FOOT_SWITCH0    A5
#define FOOT_SWITCH1    3
#define FOOT_SWITCH2    4
#define FOOT_SWITCH3    5
#define FOOT_SWITCH4    6
#define FOOT_SWITCH5    A0
#define FOOT_SWITCH6    A1
#define FOOT_SWITCH7    A2
#define FOOT_SWITCH8    A3
#define FOOT_SWITCH9    A4
#define NUMFOOTSWITCHES 10

/* NEOPIXEL LED */
#define NEO_LED_PIN 7
#define NUMPIXELS   10

#endif // DEFCONFIG_H
