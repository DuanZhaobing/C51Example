#include "nixietube.h"

#define SEGMENT_PORT P0
sbit LSA = P2 ^ 2;
sbit LSB = P2 ^ 3;
sbit LSC = P2 ^ 4;
// 段码
unsigned char NixieSegments[16] = {
    0x3F,  // 0
    0x06,  // 1
    0x5B,  // 2
    0x4F,  // 3
    0x66,  // 4
    0x6D,  // 5
    0x7D,  // 6
    0x07,  // 7
    0x7F,  // 8
    0x6F,  // 9
    0x77,  // A
    0x7C,  // b
    0x39,  // C
    0x5E,  // d
    0x79,  // E
    0x71   // F
};

// 片码
unsigned char NixieDigits[8] = {
    0xFE,  // 0
    0xFD,  // 1
    0xFB,  // 2
    0xF7,  // 3
    0xEF,  // 4
    0xDF,  // 5
    0xBF,  // 6
    0x7F   // 7
};

void NixieTubeInit() {}
void NixieTubeDiaplay()
{
    unsigned char i;
    for (i = 0; i < 16; i++) {
        SEGMENT_PORT = NixieSegments[i];
        SelectDigit(i);       // 选择数码管
        DelayMs(500);         // 短暂延时
        SEGMENT_PORT = 0x00;  // 关闭段码，消除残影
    }
}

// 设置74HC138的片选（选择数码管）
void SelectDigit(unsigned char digit)
{
    LSA = digit & 0x01;         // A0 = digit 的最低位
    LSB = (digit >> 1) & 0x01;  // A1 = digit 的次低位
    LSC = (digit >> 2) & 0x01;  // A2 = digit 的最高位
}