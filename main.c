#include "buzzer.h"
#include "led.h"
#include "reg52.h"
#include "timer.h"

void main()
{
    while (1) {
        LEDLoopSingle();
    }
}