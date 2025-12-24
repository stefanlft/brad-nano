#include <Arduino.h>

#include <cstdint>

#include "Animation.hpp"
#include "AnimationGenerators.hpp"
#include "Charlie.hpp"

// Pins for charlieplexing
#define P0 6
#define P1 7
#define P2 8
#define P3 9
#define P4 10
#define STAR 4

#define BUTTON_PIN 2

#define LONG_PRESS_TIMER (750)

#define ANIM_COUNT 5

bool power = false;

Animation powerOnAnimation;
Animation powerOffAnimation;

Animation animList[ANIM_COUNT] = {};
unsigned currentAnimation = 0;

Charlie charlie(20);

extern int __heap_start, *__brkval;

int freeRam() {
    int v;
    return (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);
}

unsigned long lastRead = 0;
bool buttonState = false;

void setup() {
    Serial.begin(9600);

    charlie.addPin(P0);
    charlie.addPin(P1);
    charlie.addPin(P2);
    charlie.addPin(P3);
    charlie.addPin(P4);

    charlie.addLED(LED(P0, P1));
    charlie.addLED(LED(P0, P2));
    charlie.addLED(LED(P0, P3));
    charlie.addLED(LED(P0, P4));

    charlie.addLED(LED(P1, P0));
    charlie.addLED(LED(P1, P2));
    charlie.addLED(LED(P1, P3));
    charlie.addLED(LED(P1, P4));

    charlie.addLED(LED(P2, P0));
    charlie.addLED(LED(P2, P1));
    charlie.addLED(LED(P2, P3));
    charlie.addLED(LED(P2, P4));

    charlie.addLED(LED(P3, P0));
    charlie.addLED(LED(P3, P1));
    charlie.addLED(LED(P3, P2));
    charlie.addLED(LED(P3, P4));

    charlie.addLED(LED(P4, P0));
    charlie.addLED(LED(P4, P1));
    charlie.addLED(LED(P4, P2));
    charlie.addLED(LED(P4, P3));

    generatePowerOn(powerOnAnimation);
    generatePowerOff(powerOffAnimation);

    uint8_t insertIndex = 0;

    generateCounter(animList[insertIndex++]);
    generateCircle(animList[insertIndex++]);
    generateRandom(animList[insertIndex++]);
    generateWorm(animList[insertIndex++]);
    generateColor(animList[insertIndex++]);

    Serial.println("Setup complete");

    pinMode(BUTTON_PIN, INPUT);
    pinMode(STAR, OUTPUT);
}

void loop() {
    if (power) charlie.update();

    if (!buttonState && digitalRead(BUTTON_PIN) &&
        millis() - lastRead > LONG_PRESS_TIMER) {
        buttonState = true;
        lastRead = millis();
    } else if (buttonState && !digitalRead(BUTTON_PIN)) {
        buttonState = false;
        lastRead = millis();
        Serial.println("Short press detected!");
        Serial.print("Available RAM:");
        Serial.println(freeRam());
        Serial.println();

        if (power) {
            charlie.stop();

            currentAnimation = (currentAnimation + 1) % ANIM_COUNT;
            charlie.setAnimation(animList[currentAnimation]);
            charlie.play();
        }

    } else if (buttonState && millis() - lastRead > LONG_PRESS_TIMER) {
        Serial.println("Long press detected!");
        power = !power;
        digitalWrite(STAR, LOW);

        if (power) {
            charlie.setAnimation(powerOnAnimation);
            charlie.play();

            while (charlie.isPlaying()) {
                charlie.update();
            }

            charlie.stop();

            charlie.setAnimation(animList[currentAnimation]);
            Serial.println("First frame: ");
            animList[currentAnimation].getFrame(0).dump();
            charlie.play();

        } else {
            charlie.stop();

            charlie.setAnimation(powerOffAnimation);
            charlie.play();

            while (charlie.isPlaying()) {
                charlie.update();
            }

            delay(1000);
            charlie.stop();
        }

        buttonState = false;
        lastRead = millis();

        delay(20);
    }

    digitalWrite(STAR, digitalRead(BUTTON_PIN));
}