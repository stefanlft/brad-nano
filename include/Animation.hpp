#pragma once

#include <Arduino.h>

#include <vector>

#include "Frame.hpp"

class Animation {
   private:
    std::vector<Frame> frames;
    unsigned frameCount = 0;

    unsigned refreshRate = 0;
    unsigned frameRate = 0;

    bool start = false;

   public:
    Animation(unsigned frameCount);
    Animation(unsigned frameCount, unsigned refreshRate, unsigned frameRate);
    ~Animation() {}

    unsigned getRefreshRate() { return refreshRate; }
    unsigned getFrameRate() { return frameRate; }
    unsigned getFrameCount() { return frameCount; }

    void setRefreshRate(unsigned rate);
    void setFrameRate(unsigned rate);

    void addFrame(Frame frame);
    void addFrame(unsigned bin);

    bool startAnimation();
    bool stopAnimation();

    Frame getFrame(unsigned frameIndex);
};