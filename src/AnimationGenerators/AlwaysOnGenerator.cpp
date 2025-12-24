#include "Animation.hpp"
#include "AnimationGenerators.hpp"
void generateAlwaysOn(Animation &animation) {
    animation = Animation(1, 5, 10000);
    Frame frame(0);
    frame.all();
    animation.addFrame(frame);
}