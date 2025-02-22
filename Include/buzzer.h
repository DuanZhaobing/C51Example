#ifndef BUZZER_H
#define BUZZER_H

#include "reg52.h"

sbit BUZZER = P2 ^ 5;

void BuzzerInit();

#endif  // BUZZER_H