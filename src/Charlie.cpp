#include "Charlie.hpp"

#include <Arduino.h>

// Charlie class implementation
Charlie::Charlie(unsigned char resolution) : animation(0), currentFrame(0) {
    this->resolution = resolution;
    leds.reserve(resolution);
}

unsigned char Charlie::getResolution() { return resolution; }

void Charlie::addLED(LED led) {
    int check = 0;
    for (auto pin : pins) {
        if (led.getHighPin() == pin || led.getLowPin() == pin) {
            ++check;
        }
    }

    if (check != 2) {
        return;
    }

    leds.push_back(led);
}
void Charlie::addPin(unsigned char pin) {
    pins.push_back(pin);
    resetBoard();
}

void Charlie::setAnimation(Animation a) { animation = a; }

int Charlie::play() {
    if (!animation.startAnimation()) {
        return 1;
    }

    if (status) {
        return 2;
    }

    status = true;

    resetBoard();

    return 0;
}

int Charlie::stop() {
    if (!status || !animation.stopAnimation()) {
        return 1;
    }

    status = false;

    resetBoard();

    return 0;
}

void Charlie::update() {
    if (!status) {
        return;
    }

    const unsigned long currTime = millis();

    if (currTime - lastUpdate > animation.getFrameRate()) {
        currentFrame = animation.getFrame(frameIndex++);
        lastUpdate = currTime;
    }

    if (frameIndex >= animation.getFrameCount()) {
        frameIndex = 0;
    }

    for (unsigned char i = 0; i < resolution; ++i) {
        if (currentFrame.getLed(i)) {
            leds[i].light();
        }
        delayMicroseconds(animation.getRefreshRate());
        leds[i].reset();
    }
}

void Charlie::resetPin(unsigned char pin) {
    pinMode(pin, INPUT);
    digitalWrite(pin, LOW);
}

void Charlie::resetBoard() {
    for (auto pin : pins) {
        resetPin(pin);
    }
}