#include "Animation.hpp"
#include "AnimationGenerators.hpp"
void generatePowerOff(Animation &animation) {
    animation = Animation(9, 5, 200);
    Frame frame(0);

    frame.all();
    animation.addFrame(frame);

    frame.setLed(11, false);
    animation.addFrame(frame);

    frame.setLed(18, false);
    frame.setLed(15, false);
    animation.addFrame(frame);

    frame.setLed(16, false);
    frame.setLed(3, false);
    frame.setLed(14, false);
    frame.setLed(19, false);
    animation.addFrame(frame);

    frame.setLed(2, false);
    frame.setLed(12, false);
    frame.setLed(13, false);
    frame.setLed(10, false);
    animation.addFrame(frame);

    frame.setLed(6, false);
    frame.setLed(7, false);
    frame.setLed(1, false);
    animation.addFrame(frame);

    frame.setLed(17, false);
    frame.setLed(8, false);
    animation.addFrame(frame);

    frame.setLed(9, false);
    frame.setLed(5, false);
    animation.addFrame(frame);

    frame.setLed(0, false);
    frame.setLed(4, false);
    animation.addFrame(frame);
    animation.addFrame(frame);

    animation.setLoop(1);
}