#include "AnimationGenerators.hpp"

void generateCounter(Animation &animation) {
    animation = Animation(20, 5, 100);

    Frame frame(0);

    for (unsigned i = 0; i < 20; i++) {
        frame.setLed(i, true);
        animation.addFrame(frame);
    }
    animation.addFrame(frame);
}