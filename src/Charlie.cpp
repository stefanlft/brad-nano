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
    frameIndex = 0;
    lastUpdate = millis();
    currentLoop = 0;
    currentFrame = animation.getFrame(frameIndex);

    resetBoard();

    return 0;
}

int Charlie::stop() {
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
        lastUpdate = currTime;
        currentFrame = animation.getFrame(frameIndex++);
    }

    // Animation completed once
    if (frameIndex >= animation.getFrameCount()) {
        if (animation.getLoop() == 0) {
            frameIndex = 0;
            currentLoop = 0;
        } else if (animation.getLoop() > ++currentLoop) {
            frameIndex = 0;
        } else {
            delay(animation.getFrameRate());
            stop();
            return;
        }
    }

    for (unsigned i = 0; i < resolution; ++i) {
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