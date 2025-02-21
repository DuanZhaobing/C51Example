#include "reg52.h"

sbit led1     = P1 ^ 0;
sbit led2     = P1 ^ 1;
sbit led3     = P1 ^ 2;
sbit led4     = P1 ^ 3;
sbit led1Ctrl = P3 ^ 2;
sbit led2Ctrl = P3 ^ 3;
sbit button1  = P3 ^ 4;
sbit button2  = P3 ^ 5;

unsigned int timer0Counter = 0;

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
    led1 = ~led1;
}

void externalInterrupt1Init(void)
{
    IT1 = 1;
    EX1 = 1;
    EA  = 1;
}
void exint1(void) interrupt 2
{
    led2 = ~led2;
}

// 1ms timer
void timer0Init(void)
{
    TMOD &= 0xf0;
    TMOD |= 0x01;  // mode 1
    TH0 = 0xfc;    // timer0 high byte
    TL0 = 0x66;    // timer0 low byte
    ET0 = 1;       // enable timer 0 interrupt
    EA  = 1;       // enable global interrupt
    TR0 = 1;       // start timer 0
}

/**
 * @brief Timer0 interrupt service routine
 */
void time0(void) interrupt 1
{
    TH0 = 0xfc;                     // timer0 high byte, reload value by hand
    TL0 = 0x66;                     // timer0 low byte
    if (++timer0Counter == 1000) {  // if timer0 counter reaches 1000
        timer0Counter = 0;          // reset timer0 counter
        led3          = ~led3;      // toggle led3
    }
}

void main(void)
{
    externalInterrupt0Init();
    externalInterrupt1Init();
    timer0Init();
    while (1) {
        if (button1 == 0) {
            delay1Ms(10);
            if (button1 == 0) {
                led1Ctrl = ~led1Ctrl;
            }
        }
        if (button2 == 0) {
            delay1Ms(10);
            if (button2 == 0) {
                led2Ctrl = ~led2Ctrl;
            }
        }
    }
}