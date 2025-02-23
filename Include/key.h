#ifndef KEY_H
#define KEY_H

#include "REG52.H"

#define MATRIX_KEY_PORT P1

sbit KEY1 = P3 ^ 0;
sbit KEY2 = P3 ^ 1;
sbit KEY3 = P3 ^ 2;
sbit KEY4 = P3 ^ 3;

sbit row1 = P1 ^ 0;  // 行1
sbit row2 = P1 ^ 1;  // 行2
sbit row3 = P1 ^ 2;  // 行3
sbit row4 = P1 ^ 3;  // 行4

sbit col1 = P1 ^ 4;  // 列1
sbit col2 = P1 ^ 5;  // 列2
sbit col3 = P1 ^ 6;  // 列3
sbit col4 = P1 ^ 7;  // 列4

/**
 * @brief Scan the key is pressed or not
 */
void KeyScan();

/**
 * @brief Scan the matrix key is pressed or not
 */
unsigned char MatrixKeyScan();

/**
 * @brief Flip scan the matrix key is pressed or not
 */
unsigned char MatrixKeyFlipScan();
#endif