#include "Animation.hpp"

Animation::Animation(unsigned frameCount) : frameCount(frameCount) {
    frames.reserve(frameCount);
}
Animation::Animation(unsigned frameCount, unsigned refreshRate,
                     unsigned frameRate)
    : frameCount(frameCount), refreshRate(refreshRate), frameRate(frameRate) {
    frames.reserve(frameCount);
}

void Animation::setRefreshRate(unsigned rate) {
    if (!start) refreshRate = rate;
}
void Animation::setFrameRate(unsigned rate) {
    if (!start) frameRate = rate;
}

void Animation::addFrame(Frame frame) {
    if (!start) frames.push_back(frame);
}
void Animation::addFrame(unsigned bin) {
    if (!start) frames.push_back(Frame(bin));
}

bool Animation::startAnimation() {
    if (frames.size() < frameCount) return false;

    if (!start) {
        start = true;
        return true;
    }
    return false;
}

bool Animation::stopAnimation() {
    if (!start) return false;

    start = false;
    return true;
}

Frame Animation::getFrame(unsigned frameIndex) {
    if (!start) return Frame(0);

    return frames[frameIndex++];
}