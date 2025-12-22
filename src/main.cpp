#include <Arduino.h>

#include "Animation.hpp"
#include "Charlie.hpp"
#include "HardwareSerial.h"

// Pins for charlieplexing
#define P0 6
#define P1 7
#define P2 8

Charlie charlie(6);

extern int __heap_start, *__brkval;

int freeRam() {
    int v;
    return (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);
}

unsigned lastUpdate = 0;

void setup() {
    Serial.begin(9600);

    charlie.addPin(P0);
    charlie.addPin(P1);
    charlie.addPin(P2);

    charlie.addLED(LED(P0, P1));
    charlie.addLED(LED(P1, P0));
    charlie.addLED(LED(P0, P2));
    charlie.addLED(LED(P2, P0));
    charlie.addLED(LED(P1, P2));
    charlie.addLED(LED(P2, P1));

    Animation animation(6, 5, 200);
    Frame frame(6);

    const uint8_t diag[3][2] = {{0, 1}, {2, 3}, {4, 5}};

    for (unsigned i = 0; i < 3; i++) {
        frame.setLed(diag[i][0], true);
        animation.addFrame(frame);

        frame.setLed(diag[i][1], true);
        animation.addFrame(frame);

        frame.reset();
    }

    charlie.setAnimation(animation);

    Serial.println("Setup complete");
    int s = 0;
    do {
        s = charlie.play();
        if (s == 0) {
            Serial.println("Charlie started");
        } else {
            Serial.print("Error code: ");
            Serial.println(s);
            Serial.println("Charlie not started");
        }

        delay(1000);
    } while (s != 0);
}

void loop() {
    charlie.update();

    if (millis() - lastUpdate > 1000) {
        lastUpdate = millis();

        Serial.print("Free RAM: ");
        Serial.println(freeRam());
    }
}