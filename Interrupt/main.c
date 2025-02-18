#include "reg52.h"

sbit led    = P1 ^ 0;
sbit button = P3 ^ 2;
void delay1Ms(unsigned int counter)
{
    unsigned int i;
    while (counter--) {
        for (i = 0; i < 125; i++)
            ;
    }
}

void externalInterrupt0Init(void)
{
    IT0 = 1;  // falling edge trigger
    EX0 = 1;  // enable external interrupt 0
    EA  = 1;  // enable global interrupt
}

void exint0(void) interrupt 0
{
    delay1Ms(1);
    if (button == 0) {
        led = ~led;
    }
}

void externalInterrupt1Init(void)
{
    IT1 = 1;
    EX1 = 1;
    EA  = 1;
}

void main(void)
{
    externalInterrupt0Init();
    externalInterrupt1Init();
    while (1) {
        ;
    }
}