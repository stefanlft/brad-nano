#include "LED.hpp"

#include <Arduino.h>

LED::LED(unsigned char high, unsigned char low)
    : high_pin(high), low_pin(low) {}

void LED::setPins(unsigned char high, unsigned char low) {
    high_pin = high;
    low_pin = low;
}

void LED::light() {
    pinMode(high_pin, OUTPUT);
    pinMode(low_pin, OUTPUT);

    digitalWrite(high_pin, HIGH);
    digitalWrite(low_pin, LOW);
}

void LED::reset() {
    pinMode(high_pin, INPUT);
    pinMode(low_pin, INPUT);
}