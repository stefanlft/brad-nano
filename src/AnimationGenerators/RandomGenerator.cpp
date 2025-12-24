#include <cstdlib>

#include "Animation.hpp"
#include "AnimationGenerators.hpp"
#include "Arduino.h"
#include "Frame.hpp"

void generateRandom(Animation &animation) {
    animation = Animation(10, 5, 100);

    Frame frame(0);

    srand(millis());
    for (int i = 0; i < 10; i++) {
        unsigned numLeds = rand() % 10 + 1;
        for (int j = 0; j < numLeds; j++) {
            frame.setLed(rand() % 20, true);
        }
        animation.addFrame(frame);
        frame.reset();
    }
}