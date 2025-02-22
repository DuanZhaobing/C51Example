#include "timer.h"

void DelayMs(u16 ms)
{
    u16 i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 120; j++) {
            ;
        }
    }
}

void Delay10Us(u16 us)
{
    u16 i;
    for (i = 0; i < us; i++) {
        ;
    }
}
