#include "key.h"
#include "led.h"
#include "timer.h"

void KeyScan()
{
    if (KEY1 == 0) {
        DelayMs(5);  // 消抖
        if (KEY1 == 0) {
            LED1 = ~LED1;  // KEY1按下，LED1翻转，原理图如此
        }
    }
    if (KEY2 == 0) {
        DelayMs(5);  // 消抖
        if (KEY2 == 0) {
            LED0 = ~LED0;  // KEY2按下，LED0翻转，原理图如此
        }
    }
    if (KEY3 == 0) {
        DelayMs(5);  // 消抖
        if (KEY3 == 0) {
            LED2 = ~LED2;
        }
    }
    if (KEY4 == 0) {
        DelayMs(5);  // 消抖
        if (KEY4 == 0) {
            LED3 = ~LED3;
        }
    }
}

u8 MatrixKeyScan()
{
    MATRIX_KEY_PORT = 0xF7;         // 设置第一列为低电平
    if (MATRIX_KEY_PORT != 0xF7) {  // 如果第一行有按键按下
        Delay10Us(1000);
        switch (MATRIX_KEY_PORT) {
            {
            case 0x77:
                return 1;
            case 0xB7:
                return 5;
            case 0xD7:
                return 9;
            case 0xE7:
                return 13;
            default:
                break;
            }
        }
    }
    while (MATRIX_KEY_PORT != 0xF7) {
        ;
    }  // 等待松开

    MATRIX_KEY_PORT = 0xFB;  // 设置第二列为低电平
    if (MATRIX_KEY_PORT != 0xfB) {
        Delay10Us(1000);
        switch (MATRIX_KEY_PORT) {
            {
            case 0x7B:
                return 2;
            case 0xBB:
                return 6;
            case 0xDB:
                return 10;
            case 0xEB:
                return 14;
            default:
                break;
            }
        }
    }
    while (MATRIX_KEY_PORT != 0xfB) {
        ;
    }  // 等待松开

    MATRIX_KEY_PORT = 0xFD;         // 设置第三列为低电平
    if (MATRIX_KEY_PORT != 0xfD) {  //
        Delay10Us(1000);
        switch (MATRIX_KEY_PORT) {
            {
            case 0x7D:
                return 3;
            case 0xBD:
                return 7;
            case 0xDD:
                return 11;
            case 0xED:
                return 15;
            default:
                break;
            }
        }
    }
    while (MATRIX_KEY_PORT != 0xFD) {
    }

    MATRIX_KEY_PORT = 0xFE;  // 设置第四列为低电平
    if (MATRIX_KEY_PORT != 0xFE) {
        Delay10Us(1000);
        switch (MATRIX_KEY_PORT) {
            {
            case 0x7E:
                return 4;
            case 0xBE:
                return 8;
            case 0xDE:
                return 12;
            case 0xEE:

                return 16;
            default:
                break;
            }
        }
    }
    while (MATRIX_KEY_PORT != 0xFE) {
        {
            /* code */
        }
    }
    return 0;
}

unsigned char MatrixKeyFlipScan()
{
    unsigned char rowState, colState;  // 行和列的状态
    unsigned char keyValue = 0;

    // 第一步：将所有行设置为低电平，检测列的状态
    MATRIX_KEY_PORT = 0x0F;                    // 高4位（行）为0（拉低），低4位（列）为1（设置为输入）
    colState        = MATRIX_KEY_PORT & 0x0F;  // 读取列的状态（低4位）

    // 第二步：将所有列设置为低电平，检测行的状态
    MATRIX_KEY_PORT = 0xF0;                    // 低4位（列）为0（拉低），高4位（行）为1（设置为输入）
    rowState        = MATRIX_KEY_PORT & 0xF0;  // 读取行的状态（高4位）

    // 根据行和列的状态计算按键值
    switch (colState) {
    case 0x07:
        keyValue = 1;
        break;  // 列1
    case 0x0B:
        keyValue = 2;
        break;  // 列2
    case 0x0D:
        keyValue = 3;
        break;  // 列3
    case 0x0E:
        keyValue = 4;
        break;  // 列4
    default:
        keyValue = 0;
        break;  // 无按键按下
    }

    switch (rowState) {
    case 0x70:
        keyValue += 0;
        break;  // 行1
    case 0xB0:
        keyValue += 4;
        break;  // 行2
    case 0xD0:
        keyValue += 8;
        break;  // 行3
    case 0xE0:
        keyValue += 12;
        break;  // 行4
    default:
        keyValue = 0;
        break;  // 无按键按下
    }

    DelayMs(20);  // 消抖
    return keyValue;
}