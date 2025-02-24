/**
 * 注意：J24跳键帽的GND与OE短接
 */
#include "INTRINS.H"
#include "pattern.h"

unsigned char DriverBuffer[8]      = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };  // 74HC595驱动缓冲区
unsigned char PortPatternBuffer[8] = { 0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F };  // P0端口缓冲区
unsigned char Pattern[][8]         = {
    { 0x00, 0x7C, 0x82, 0x82, 0x82, 0x7c, 0x00, 0x00 },  // 0
    { 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00 },  // 1
};

void PatternInit()
{
    PATTERN_PORT = 0;
}

void WriteData(unsigned char dat)
{
    unsigned char i;
    for (i = 0; i < 8; i++) {
        SER = dat & 0x80;  // Send HSB first
        dat <<= 1;
        SRCLK = 0;
        Delay10Us(1);
        SRCLK = 1;
    }
    CLK = 0;
    Delay10Us(1);
    CLK = 1;
}

void PatternDisplay()
{
    unsigned char i;
    for (i = 0; i < 8; i++) {
        WriteData(0);
        WriteData(DriverBuffer[i]);
        DelayMs(500);
    }
}

void PatternDisplayPoint()
{
    int cow;
    for (cow = 0; cow < 8; cow++) {
        int col;
        PATTERN_PORT = ~(1 << cow);  // 选择第i列（阴极）
        for (col = 0; col < 8; col++) {
            WriteData(DriverBuffer[col]);
            DelayMs(200);
            WriteData(0);
        }
        PATTERN_PORT = 0xFF;  // 关闭所有列（阴极）
    }
}
void PatternDisplayPattern(unsigned char pattern[][8])
{
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 8; j++) {
            PATTERN_PORT = ~(1 << j);  // 选择第i列（阴极）
            WriteData(pattern[i][j]);
            DelayMs(1);
            WriteData(0);
        }
        DelayMs(500);
        // PATTERN_PORT = 0xFF;  // 关闭所有列（阴极）
    }
}
