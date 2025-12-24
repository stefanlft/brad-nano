#include "AnimationGenerators.hpp"

void generatePowerOn(Animation &animation) {
    animation = Animation(9, 5, 200);
    Frame frame(0);

    frame.reset();

    frame.setLed(0, true);
    frame.setLed(4, true);
    animation.addFrame(frame);

    frame.setLed(9, true);
    frame.setLed(5, true);
    animation.addFrame(frame);

    frame.setLed(17, true);
    frame.setLed(8, true);
    animation.addFrame(frame);

    frame.setLed(6, true);
    frame.setLed(7, true);
    frame.setLed(1, true);
    animation.addFrame(frame);

    frame.setLed(2, true);
    frame.setLed(12, true);
    frame.setLed(13, true);
    frame.setLed(10, true);
    animation.addFrame(frame);

    frame.setLed(16, true);
    frame.setLed(3, true);
    frame.setLed(14, true);
    frame.setLed(19, true);
    animation.addFrame(frame);

    frame.setLed(18, true);
    frame.setLed(15, true);
    animation.addFrame(frame);

    frame.setLed(11, true);
    animation.addFrame(frame);
    animation.addFrame(frame);

    animation.setLoop(1);
}