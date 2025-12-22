#include "Frame.hpp"

#include <Arduino.h>

Frame::Frame(unsigned char bin) { leds = bin; }

Frame::~Frame() {}

void Frame::setLed(unsigned char ledNum, bool state) {
    leds = state ? leds | (1 << ledNum) : leds & ~(1 << ledNum);
}

unsigned char Frame::getLed(unsigned char ledNum) {
    return leds & (1 << ledNum);
}

void Frame::reset() { leds = 0; }

void Frame::dump() {
    Serial.print("Frame: ");
    Serial.println(leds, BIN);
}