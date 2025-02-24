#ifndef PATTERN_H
#define PATTERN_H

#include "REG52.H"
#include "timer.h"

sbit SER   = P3 ^ 4;     // 串行数据
sbit CLK   = P3 ^ 5;     // 串行时钟
sbit SRCLK = P3 ^ 6;     // 移位寄存器时钟
#define PATTERN_PORT P0  // 点阵显示端口

/**
 * @brief 初始化LED点阵的P0口
 */
void PatternInit();

/**
 * @brief 将数据写入74HC595移位寄存器
 */
void WriteData(unsigned char dat);

/**
 * @brief LED点阵显示图案
 */
void PatternDisplay();

/**
 * @brief LED点阵显示单个点
 */
void PatternDisplayPoint();


/**
 * @brief LED点阵显示图案
 */
void PatternDisplayPattern(unsigned char *pattern);

#endif /*PATTER_H*/