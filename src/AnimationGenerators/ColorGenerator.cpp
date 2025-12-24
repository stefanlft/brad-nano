#include <cstdint>

#include "AnimationGenerators.hpp"
void generateColor(Animation &animation) {
    animation = Animation(5, 5, 1000);
    Frame frame(0);

    uint8_t redLeds[] = {9, 5, 17, 8, 18, 15};
    uint8_t greenLeds[] = {2, 7, 1, 10};
    uint8_t blueLeds[] = {11, 6, 3, 14};
    uint8_t whiteLeds[] = {16, 19};
    uint8_t yellowLeds[] = {0, 4, 12, 13};

    frame.reset();
    for (auto led : redLeds) {
        frame.setLed(led, true);
    }
    animation.addFrame(frame);

    frame.reset();
    for (auto led : greenLeds) {
        frame.setLed(led, true);
    }
    animation.addFrame(frame);

    frame.reset();
    for (auto led : blueLeds) {
        frame.setLed(led, true);
    }
    animation.addFrame(frame);

    frame.reset();
    for (auto led : whiteLeds) {
        frame.setLed(led, true);
    }
    animation.addFrame(frame);

    frame.reset();
    for (auto led : yellowLeds) {
        frame.setLed(led, true);
    }
    animation.addFrame(frame);
}