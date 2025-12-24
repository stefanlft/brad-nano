#include <cstdint>

#include "Animation.hpp"
#include "AnimationGenerators.hpp"
void generateCircle(Animation &animation) {
    animation = Animation(40, 5, 100);
    Frame frame(0);

    uint8_t ledOrder[] = {0,  4,  5, 1, 8, 10, 19, 14, 15, 11,
                          18, 16, 3, 2, 7, 17, 12, 13, 6,  9};

    for (int i = 0; i < 20; ++i) {
        frame.setLed(ledOrder[i], true);
        animation.addFrame(frame);
    }

    for (int i = 0; i < 20; ++i) {
        frame.setLed(ledOrder[i], false);
        animation.addFrame(frame);
    }
}