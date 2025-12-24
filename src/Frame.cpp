#include "Frame.hpp"

#include <Arduino.h>

Frame::Frame(unsigned long bin) { leds = bin; }

void Frame::setLed(unsigned ledNum, bool state) {
    leds = state ? leds | ((unsigned long)1 << ledNum)
                 : leds & ~((unsigned long)1 << ledNum);
}

bool Frame::getLed(unsigned ledNum) {
    return leds & ((unsigned long)1 << ledNum);
}

void Frame::dump() {
    Serial.print("Frame: ");
    Serial.println(leds, BIN);
}