#include "INTRINS.H"
#include "led.h"
#include "timer.h"

void LEDControl(const unsigned char ledIndex)
{
    // Invert the bits to turn on the correct LEDs
    switch (ledIndex) {
    case 0:
        LED0 = ~LED0;
        break;
    case 1:
        LED1 = ~LED1;
        break;
    case 2:
        LED2 = ~LED2;
        break;
    case 3:
        LED3 = ~LED3;
        break;
    case 4:
        LED4 = ~LED4;
        break;
    case 5:
        LED5 = ~LED5;
        break;
    case 6:
        LED6 = ~LED6;
        break;
    case 7:
        LED7 = ~LED7;
        break;
    default:
        break;
    }
}

void LEDLoop()
{
    unsigned char i;
    for (i = 0; i < 8; i++) {
        if (i == 8) {
            i = 0;
        }
        LEDControl(i);
        DelayMs(500);
    }
}

void LEDLoopSingle()
{
    char i;           //
    LED_Port = 0xFE;  // 1111 1110

    for (i = 0; i < 7; i++) {
        LED_Port = _crol_(LED_Port, 1);  // 循环左移一位
        DelayMs(500);
    }

    for (i = 0; i < 7; i++) {
        LED_Port = _cror_(LED_Port, 1);  // 循环右移一位
        DelayMs(500);
    }
}
