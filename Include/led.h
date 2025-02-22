#ifndef LED_H
#define LED_H
#include "reg52.h"

#define LED_Port P2

sbit LED0 = P2 ^ 0;
sbit LED1 = P2 ^ 1;
sbit LED2 = P2 ^ 2;
sbit LED3 = P2 ^ 3;
sbit LED4 = P2 ^ 4;
sbit LED5 = P2 ^ 5;
sbit LED6 = P2 ^ 6;
sbit LED7 = P2 ^ 7;

/**
 * @brief Control the LED
 *
 * @param ledIndex The index of the LED to control
 */
void LEDControl(const unsigned char ledIndex);

/**
 * @brief Loop through all LEDs
 *
 */
void LEDLoop();

/**
 * @brief LED loop for single LED
 */
void LEDLoopSingle();

#endif /* LED_H */
