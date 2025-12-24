#pragma once

#include <Arduino.h>

#include <vector>

#include "Animation.hpp"
#include "Frame.hpp"
#include "LED.hpp"

class Charlie {
   private:
    std::vector<LED> leds;
    std::vector<unsigned char> pins;
    unsigned resolution = 0;

    Animation animation;
    bool status = false;
    unsigned char frameIndex = 0;

    void resetPin(unsigned char pin);

    void resetBoard();

    unsigned long lastUpdate = 0;
    unsigned long currentLoop = 0;
    Frame currentFrame;

   public:
    Charlie(unsigned char resolution);
    ~Charlie() {}

    unsigned char getResolution();

    void addLED(LED led);
    void addPin(unsigned char pin);

    bool isPlaying() { return status; }

    void setAnimation(Animation a);

    int play();

    int stop();

    void update();
};