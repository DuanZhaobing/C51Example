#ifndef TIMER_H
#define TIMER_H
#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int  u16;

/**
 * @brief Delay in milliseconds
 */
void DelayMs(u16 ms);

/**
 * @brief Delay in microseconds
 */
void Delay10Us(u16 us);

#endif  // TIMER_H