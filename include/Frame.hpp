#pragma once

class Frame {
   private:
    unsigned char leds = 0;

   public:
    Frame(unsigned char bin);
    ~Frame();

    void setLed(unsigned char ledNum, bool state);

    unsigned char getLed(unsigned char ledNum);

    void reset();
    void dump();
};