#include "buzzer.h"
#include "key.h"
#include "led.h"
#include "nixietube.h"
#include "reg52.h"
#include "timer.h"

void main()
{
    while (1) {
        // LEDLoopSingle();
        // BuzzerInit();
        // NixieTubeDiaplay();
        // KeyScan();
        u8 number = MatrixKeyFlipScan();
        SignalNixieTube(number);
    }
}