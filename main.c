#include "buzzer.h"
#include "key.h"
#include "led.h"
#include "nixietube.h"
#include "pattern.h"
#include "reg52.h"
#include "timer.h"

extern u8 Pattern[][8];

void main()
{
    // PatternInit();
    while (1) {
        // LEDLoopSingle();
        // BuzzerInit();
        // NixieTubeDiaplay();
        // KeyScan();
        // u8 number = MatrixKeyFlipScan();
        // SignalNixieTube(number);
        // PatternDisplay();
        // PatternDisplayPoint();
        PatternDisplayPattern(Pattern);
    }
}