#ifndef NIXIETUBE_H
#define NIXIETUBE_H

#include "reg52.h"
#include "timer.h"

/**
 * @brief Display the number(0x00-0x0F) on the nixie tube
 */
void NixieTubeDiaplay();

/**
 * @brief Select the digit to display
 */
void SelectDigit(unsigned char digit);

/**
 * @brief Display the number(0x00-0x0F) on the first nixie tube
 */
void SignalNixieTube(u8 number);
#endif  // NIXIETUBE_H