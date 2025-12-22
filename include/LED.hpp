#pragma once

class LED {
   private:
    unsigned char high_pin = 0;
    unsigned char low_pin = 0;

   public:
    LED() = default;
    LED(unsigned char hp, unsigned char lp);
    ~LED() {};

    void setPins(unsigned char high, unsigned char low);

    void light();

    void reset();

    unsigned char getHighPin() { return high_pin; }
    unsigned char getLowPin() { return low_pin; }
};