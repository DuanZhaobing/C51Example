#include "buzzer.h"
#include "timer.h"

void BuzzerInit()
{

    BUZZER = ~BUZZER;
    Delay10Us(10);
}