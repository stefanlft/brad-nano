#pragma once

class Frame {
   private:
    unsigned long leds = 0;

   public:
    Frame(unsigned long bin);
    ~Frame() {}

    void setLed(unsigned ledNum, bool state);

    bool getLed(unsigned ledNum);

    void reset() { leds = 0; }
    void all() { leds = 0xFFFFFFFF; }

    unsigned long getLeds() { return leds; }

    void dump();
};