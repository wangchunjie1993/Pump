#include "LCD12864User.h"

unsigned char lcd_buffer[64][16];//lcdͼ����ʾ������


unsigned char gImage_test1[1024] = { /* 0X10,0X01,0X00,0X80,0X00,0X40, */
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X20,0X08,0X02,0X00,0X80,0X20,0X08,0X02,0X00,0X80,0X20,0X08,0X02,0X00,0X80,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
};


unsigned char gImage_yanshan[1024] = { /* 0X10,0X01,0X00,0X80,0X00,0X30, */
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X80,0X00,
0X00,0X01,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XE8,0X00,
0X00,0X03,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFC,0X00,
0X00,0X01,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XF8,0X00,
0X00,0X01,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XCF,0X00,
0X00,0XC1,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XDF,0X80,
0X00,0XC3,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0C,0XDD,0XC0,
0X00,0X7F,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XE1,0X80,
0X01,0XFF,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X6C,0XFD,0X80,
0X07,0XFF,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3C,0X00,0X00,0X7D,0XBF,0X00,
0X07,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X78,0X00,0X00,0X75,0XB7,0X00,
0X03,0XF6,0X0C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XF6,0X00,0X00,0X77,0XAF,0X00,
0X01,0XFF,0X1C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0X80,0X00,0X37,0XEF,0X00,
0X0E,0XFF,0X8C,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,0XC0,0X00,0X37,0XE7,0X60,
0X1F,0X7F,0X0E,0X00,0X00,0X03,0X00,0X00,0X00,0X7F,0XFF,0X80,0X00,0X37,0XFF,0XF8,
0X0F,0X3E,0XDF,0X00,0X00,0X07,0X80,0X00,0X00,0X7F,0XC0,0X00,0X02,0X17,0XFF,0XFC,
0X07,0X9F,0XFB,0X80,0X00,0X07,0X80,0X00,0X00,0X03,0XC0,0X00,0X07,0X3F,0XC0,0XF8,
0X07,0X9F,0XFF,0X80,0X00,0X07,0XC0,0XC0,0X00,0X07,0X80,0X00,0X07,0XBC,0X01,0XF0,
0X0F,0XFF,0XDF,0X00,0X00,0X07,0XE0,0XE0,0X00,0X07,0X00,0X00,0X07,0X80,0X03,0XC0,
0X3F,0X7D,0XBC,0X00,0X00,0XC7,0XE0,0XF0,0X00,0X0F,0X00,0X00,0X07,0X80,0X7E,0X00,
0XFF,0X77,0X78,0X00,0X00,0XC7,0XE0,0XF0,0X00,0X0E,0X00,0X00,0X0F,0X01,0XFE,0X00,
0X37,0XE7,0XF0,0X00,0X01,0XC7,0XE0,0XF0,0X00,0X1E,0X00,0X00,0X06,0X03,0XFE,0X00,
0X07,0XEE,0XE0,0X00,0X03,0XE7,0XF0,0XF0,0X00,0X3F,0XF8,0X00,0X06,0X07,0X38,0X00,
0X07,0XEE,0X7F,0X80,0X03,0XFF,0XFE,0XF0,0X00,0X3D,0XFF,0XE0,0X00,0X00,0X30,0X00,
0X0F,0X6E,0X7F,0XC0,0X07,0XFF,0XFE,0XF0,0X01,0XF8,0X07,0XF0,0X00,0X00,0X70,0X00,
0X1E,0X06,0XFF,0X80,0X03,0XF0,0X00,0X60,0X03,0XF0,0X03,0XF0,0X00,0X00,0X78,0X00,
0X1E,0X00,0X78,0X00,0X03,0XC0,0X00,0X00,0X03,0XE0,0X07,0XF8,0X00,0X00,0X3F,0XE0,
0X1C,0X00,0XC0,0X00,0X00,0XC0,0X00,0X00,0X03,0XC0,0X1F,0XF8,0X00,0X00,0XFF,0XE0,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X00,0X00,0X00,0X00,0X03,0XFF,0XF0,
0X00,0X04,0X0F,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X02,0X1C,0X10,
0X07,0X1F,0X8F,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X02,0X3C,0X00,
0X1F,0X0F,0X01,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XF8,0X00,
0X07,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XF0,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X80,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X24,0X18,0X6C,0X70,0XB0,0XC1,0XA0,0X09,0X1B,0X18,0X90,0XE3,0XC3,0XC6,0X3C,0X48,
0X3C,0X38,0X6C,0XD8,0XB0,0XE1,0XA0,0X09,0X1B,0X18,0X90,0X81,0X62,0XC6,0X18,0X78,
0X18,0X28,0X7C,0X60,0XB0,0XA1,0XA0,0X09,0X1F,0X18,0XF0,0X81,0X63,0X06,0X18,0X70,
0X18,0X2C,0X7C,0X30,0XF0,0XA1,0XE0,0X09,0X1F,0X18,0XF0,0XE3,0XC1,0XC6,0X18,0X30,
0X18,0X3C,0X7C,0X18,0XB1,0XE1,0X60,0X09,0X1F,0X18,0X70,0X81,0X60,0XC6,0X18,0X30,
0X18,0X2C,0X6C,0XD8,0XB1,0XB1,0X60,0X09,0X1B,0X18,0X60,0X81,0X62,0XC6,0X18,0X30,
0X18,0X64,0X6C,0X70,0XB1,0X31,0X60,0X0F,0X1B,0X18,0X60,0XE1,0X63,0X86,0X18,0X30,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};







/**************************************************************************
//����void lcd_string_write(unsigned char address_8,unsigned char *string_8)
//���ܣ�д�ַ���
//��������ʼ��ַ���ַ���ָ��
***************************************************************************/
void lcd_string_write(unsigned char address_8,unsigned char *string_8)
{
	lcd_command_write(0x30);	//����ָ�
	lcd_command_write(address_8);
	while(*string_8!='\0')
	{
		lcd_data_write(*string_8);	//һ������Ҫд����
		string_8++;
		//lcd_data_write(*string_8);
		//string_8++;
	}
}

/**************************************************************************
//����void lcd_multi_line_string_write(unsigned char address_8,unsigned char *string_8)
//���ܣ�д�����ַ���
//��������ʼ��ַ���ַ���ָ��
//��ע����������δ����
***************************************************************************/
void lcd_multi_line_string_write(unsigned char address_8,unsigned char *string_8)
{
	lcd_command_write(0x30);	//����ָ�
	while(*string_8!='\0')
	{	
		switch(address_8)
		{
			case 0x88 : address_8=0x90;break;
			case 0x98 : address_8=0x88;break;
			case 0x90 : address_8=0x98;break;
			case 0x80 : address_8=0x80;break;
			default   : break;
		}
		lcd_command_write(address_8++);
		lcd_data_write(*string_8++);	
	}
}
/**************************************************************************
//����void lcd_display_left_move(unsigned char number_8)
//���ܣ���ʾ����
//�������ƶ�����
***************************************************************************/
void lcd_display_left_move(unsigned char number_8)
{
	unsigned char move;
	lcd_command_write(0x30);		//����ָ�
	for(move=number_8;move>0;move--)
	{
		lcd_command_write(0x18);	//��ʾ�����ƶ����α�����ƶ�
	}
}
/**************************************************************************
//����void lcd_display_right_move(unsigned char number_8)
//���ܣ���ʾ����
//�������ƶ�����
***************************************************************************/
void lcd_display_right_move(unsigned char number_8)
{
	unsigned char move;
	lcd_command_write(0x30);		//����ָ�
	for(move=number_8;move>0;move--)
	{
		lcd_command_write(0x1C);	//��ʾ�����ƶ����α�����ƶ�
	}
}
/**************************************************************************
//����void lcd_display_inverse(void)
//���ܣ�ȫ�����ס������������ַ��ס�
//��������
***************************************************************************/
void lcd_display_inverse(void)
{
	unsigned char count=2,X=0x80,i,j;		//ѭ������
	lcd_command_write(0x34);	//����ָ�����ͼ��ʾ��
	lcd_command_write(0x36);	//����ָ�����ͼ��ʾ�� 
	for(count=2;count>0;count--)
	{
		for(i=0;i<32;i++)
		{   
			lcd_command_write(0x80|i);
			lcd_command_write(X); 		//X��ַ����,�Զ���1.
			for(j=0;j<16;j++)  			//16*8=128
				lcd_data_write(0xFF); 	//����
		}
		X=0x88;	//�°���   
	}  
	lcd_command_write(0x30);	//����ָ�
}
/**************************************************************************
//����void lcd_picture_clear(void)
//���ܣ�ͼƬ����
//��������
***************************************************************************/
void lcd_picture_clear(void)
{
	unsigned char count=2,X=0x80,i,j;		//ѭ������
	unsigned char m,n;		//ѭ������
	for(m=0;m<64;m++)		//���LCDͼƬ��������
	{
		for(n=0;n<16;n++)
		{
			lcd_buffer[m][n]=0x00;
		}
	}
	lcd_command_write(0x34);	//����ָ�����ͼ��ʾ��
	lcd_command_write(0x36);	//����ָ�����ͼ��ʾ�� 
	for(count=2;count>0;count--)//���LCD��ͼ�λ�������GDRAM��
	{
		for(i=0;i<32;i++)
		{   
			lcd_command_write(0x80|i);
			lcd_command_write(X); 		//X��ַ����,�Զ���1.
			for(j=0;j<16;j++)  			//16*8=128
				lcd_data_write(0x00); 	//�����ɫ
		}
		X=0x88;	//�°���   
	}


	lcd_command_write(0x30);	//����ָ�
}

void _lcd_picture_clear(void)
{
	unsigned char count=2,X=0x80,i,j;		//ѭ������
	lcd_command_write(0x34);	//����ָ�����ͼ��ʾ��
	lcd_command_write(0x36);	//����ָ�����ͼ��ʾ�� 
	for(count=2;count>0;count--)
	{
		for(i=0;i<32;i++)
		{   
			lcd_command_write(0x80|i);
			lcd_command_write(X); 		//X��ַ����,�Զ���1.
			for(j=0;j<16;j++)  			//16*8=128
				lcd_data_write(0x00); 	//�����ɫ
		}
		X=0x88;	//�°���   
	}  
	lcd_command_write(0x30);	//����ָ�
}

/**************************************************************************
//����void lcd_picture_draw(unsigned char *picture_8)
//���ܣ���ȫ��ͼƬ������Ϊ128*64����
//������ȫ��ͼƬ����ָ��
***************************************************************************/
void lcd_picture_draw(unsigned char *picture_8)
{
	unsigned char count=2,X=0x80,i,j;	//ѭ������
	unsigned char m,n;		//ѭ������
	unsigned char *temp=picture_8;	//���ͼƬ�����׵�ַ
	for(m=0;m<64;m++)				//��ͼƬ����LCDͼƬ��������
	{
		for(n=0;n<16;n++)
		{
			lcd_buffer[m][n]|=(*temp++);
		}
	}
	picture_8=&lcd_buffer[0][0];	//���LCDͼƬ���������׵�ַ
	lcd_command_write(0x34);	//����ָ�����ͼ��ʾ��
	lcd_command_write(0x36);	//����ָ�����ͼ��ʾ��
	for(count=2;count>0;count--)	//��LCDͼƬ��������ͼƬд��LCDGDRAM
	{
		for(i=0;i<32;i++)
		{   
			lcd_command_write(0x80|i);
			lcd_command_write(X); 		//X��ַ����,�Զ���1.
			for(j=0;j<16;j++)  			//16*8=128
				lcd_data_write(*picture_8++); 
		}
		X=0x88;	//�°���   
	}  
	lcd_command_write(0x30);	//����ָ�
}

void __lcd_picture_draw(unsigned char picture_8[][16])
{
	unsigned char count=2,X=0x80,i,j,hang;	//ѭ������
	unsigned char m,n;		//ѭ������
	unsigned char *temp=picture_8;	//���ͼƬ�����׵�ַ
	for(m=0;m<64;m++)				//��ͼƬ����LCDͼƬ��������
	{
		for(n=0;n<16;n++)
		{
			lcd_buffer[m][n]|=(*temp++);
		}
	}
	picture_8=&lcd_buffer[0][0];	//���LCDͼƬ���������׵�ַ
	lcd_command_write(0x34);	//����ָ�����ͼ��ʾ��
	lcd_command_write(0x36);	//����ָ�����ͼ��ʾ��
	for(count=2;count>0;count--)	//��LCDͼƬ��������ͼƬд��LCDGDRAM
	{
		for(i=0;i<32;i++)
		{   
			lcd_command_write(0x80|i);
			lcd_command_write(X); 		//X��ַ����,�Զ���1.
			for(j=0;j<16;j++)  			//16*8=128
				lcd_data_write(picture_8[hang][j]); 
			hang++;
		}
		X=0x88;	//�°���   
	}  
	lcd_command_write(0x30);	//����ָ�
}


void _lcd_picture_draw(unsigned char picture_8[][8])
{
	unsigned char count=2,X=0x80,i,j,k,hang=0;		//ѭ������
	lcd_command_write(0x34);	//����ָ�����ͼ��ʾ��
	lcd_command_write(0x36);	//����ָ�����ͼ��ʾ��
	for(count=2;count>0;count--)
	{
		for(i=0;i<32;i++)
		{   
			lcd_command_write(0x80|i);
			lcd_command_write(X); 		//X��ַ����,�Զ���1.
			for(j=0;j<2;j++)  			//16*8=128
			{
				for(k=0;k<8;k++)
				{
					lcd_data_write(picture_8[hang][k]);					
				}
				hang++;
			}
				
		}
		X=0x88;	//�°���   
	}  
	lcd_command_write(0x30);	//����ָ�
}

/**************************************************************************
//����void lcd_small_picture_draw(unsigned char x_8,unsigned char y_8,
//							unsigned char lenght_8,unsigned char height_8,
//							const unsigned char *picture_8)
//���ܣ���ָ�����꿪ʼ����ͼƬ��ʹ��ǰ�����GDRAM��
//���������꣨x��y�����ߣ�����ͼƬ����ָ�롣
//		ע�⣺���귶Χ��0��0��~��128��64�������ȷ�Χ0~128���߶ȷ�Χ0~64��
//			  lenght_8ӦΪ16�ı�����x����ӦΪ16�ı�����
***************************************************************************/
void lcd_small_picture_draw(unsigned char x_8,unsigned char y_8,
							unsigned char lenght_8,unsigned char height_8,
							const unsigned char *picture_8)
{
	unsigned char x_start_8=x_8/16,y_start_8=y_8;	//���忪ʼ���겢����ֵ
	unsigned char x_end_8=0,y_end_8=0;				//�����������
	unsigned char X=x_start_8,Y=y_start_8;			//ѭ������
	x_end_8=x_start_8+lenght_8/16;		//����X��������
	y_end_8=y_start_8+height_8;			//����Y��������
	if(x_end_8>128) x_end_8=x_start_8;
	if(y_end_8>64) y_end_8=y_start_8;
	lcd_command_write(0x34);	//����ָ�����ͼ��ʾ��
	lcd_command_write(0x36);	//����ָ�����ͼ��ʾ��
	for(Y=y_start_8;Y<y_end_8;Y++)
	{
		if(Y>=32)
		{
			Y-=32;y_start_8-=32;y_end_8-=32;	//ѭ������Y��Y��ʼֵ��Y����ֵͬʱ����32
			x_start_8+=8; x_end_8+=8;			//ѭ������X��X��ʼֵ��X����ֵͬʱ����8
		}
		lcd_command_write(0x80|Y);			//Y����
		lcd_command_write(0x80|x_start_8);	//X����
		for(X=x_start_8;X<x_end_8;X++)
		{
			lcd_data_write(*picture_8++);	//D15~D8д��RAM
			lcd_data_write(*picture_8++);	//D7~D0д��RAM  
		}
	}
	lcd_command_write(0x30);	//����ָ�
}
/**************************************************************************
//����void lcd_point_draw(unsigned char x_8,unsigned char y_8,unsigned char color_8)
//���ܣ�����
//������ˮƽ����X����Χ0~127������ֱ����Y����Χ0~63����
//		��ɫcolor��color=1:��ʾ;color=0:���;color=2:ȡ������
***************************************************************************/
void lcd_point_draw(unsigned char x_8,unsigned char y_8,unsigned char color_8)
{
	unsigned char x_word_8=(x_8/16);	//����x��16�����е���һ��
	unsigned char x_bit_8=(x_8&0x0F);	//����x��һ�����еĵڼ�λ
	unsigned char y_screen_8=(y_8/32);	//����y���İ�����1Ϊ�ϰ�����0Ϊ�°�����
	unsigned char y_line_8=(y_8&0x1F);	//����y��0~31���е���һ��
	unsigned char *GDRAM_high_byte;	//��ǰ��ʾ���ݸ�8λ
	unsigned char *GDRAM_low_byte;	//��ǰ��ʾ���ݵ�8λ
	if((x_8/8)%2==0)
	{
		GDRAM_high_byte=&lcd_buffer[y_8][x_8/8];
		GDRAM_low_byte=&lcd_buffer[y_8][x_8/8+1];
	}
	else
	{
		GDRAM_high_byte=&lcd_buffer[y_8][x_8/8-1];
		GDRAM_low_byte=&lcd_buffer[y_8][x_8/8];
	}										
	if(x_bit_8<8)	//�ж�x�ڸ�8λ,�����ڵ�8λ
	{
		if(color_8==1)
		{
			
			*GDRAM_high_byte=(*GDRAM_high_byte|(0x01<<(7-x_bit_8)));	 	//��λGDRAM���и�8λ��������Ӧ�ĵ�
		}
		else if(color_8==0)
			*GDRAM_high_byte=(*GDRAM_high_byte&(~(0x01<<(7-x_bit_8))));		//���GDRAM���и�8λ��������Ӧ�ĵ�
			 else if(color_8==2)
					*GDRAM_high_byte=(*GDRAM_high_byte^(0x01<<(7-x_bit_8)));//��������ȡ��һλ����			
	}
	else
	{
		if(color_8==1)
		{
			*GDRAM_low_byte=(*GDRAM_low_byte|(0x01<<(15-x_bit_8)));			//��λGDRAM���е�8λ��������Ӧ�ĵ�
		}
		else if(color_8==0)
				*GDRAM_low_byte=(*GDRAM_low_byte&(~(0x01<<(15-x_bit_8)))); 	//���GDRAM���е�8λ��������Ӧ�ĵ�
			 else if(color_8==2)
					*GDRAM_low_byte=(*GDRAM_low_byte^(0x01<<(15-x_bit_8))); //��������ȡ��һλ����
	}
	lcd_command_write(0x34);	//����ָ�����ͼ��ʾ��

	lcd_command_write(0x80+y_line_8);				//�趨�е�ַ��y���꣩����ֱ����
	lcd_command_write(0x80+x_word_8+8*y_screen_8);	//�趨�е�ַ��x���꣩��ˮƽ����
													//ͨ��y_screen_8ѡ������������ˮƽ��ַ	
	lcd_data_write(*GDRAM_high_byte);	//д��GDRAM���и�8λ����
	lcd_data_write(*GDRAM_low_byte);	//д��GDRAM���е�8λ����
	lcd_command_write(0x36);	//����ָ�����ͼ��ʾ��	
	lcd_command_write(0x30);	//����ָ�	
}

void lcd_point_draw_buffer(unsigned char x_8,unsigned char y_8,unsigned char color_8)
{
	unsigned char x_word_8=(x_8/16);	//����x��16�����е���һ��
	unsigned char x_bit_8=(x_8&0x0F);	//����x��һ�����еĵڼ�λ
	unsigned char y_screen_8=(y_8/32);	//����y���İ�����1Ϊ�ϰ�����0Ϊ�°�����
	unsigned char y_line_8=(y_8&0x1F);	//����y��0~31���е���һ��
	unsigned char *GDRAM_high_byte;	//��ǰ��ʾ���ݸ�8λ
	unsigned char *GDRAM_low_byte;	//��ǰ��ʾ���ݵ�8λ
	if((x_8/8)%2==0)
	{
		GDRAM_high_byte=&lcd_buffer[y_8][x_8/8];
		GDRAM_low_byte=&lcd_buffer[y_8][x_8/8+1];
	}
	else
	{
		GDRAM_high_byte=&lcd_buffer[y_8][x_8/8-1];
		GDRAM_low_byte=&lcd_buffer[y_8][x_8/8];
	}										
	if(x_bit_8<8)	//�ж�x�ڸ�8λ,�����ڵ�8λ
	{
		if(color_8==1)
		{
			
			*GDRAM_high_byte=(*GDRAM_high_byte|(0x01<<(7-x_bit_8)));	 	//��λGDRAM���и�8λ��������Ӧ�ĵ�
		}
		else if(color_8==0)
			*GDRAM_high_byte=(*GDRAM_high_byte&(~(0x01<<(7-x_bit_8))));		//���GDRAM���и�8λ��������Ӧ�ĵ�
			 else if(color_8==2)
					*GDRAM_high_byte=(*GDRAM_high_byte^(0x01<<(7-x_bit_8)));//��������ȡ��һλ����			
	}
	else
	{
		if(color_8==1)
		{
			*GDRAM_low_byte=(*GDRAM_low_byte|(0x01<<(15-x_bit_8)));			//��λGDRAM���е�8λ��������Ӧ�ĵ�
		}
		else if(color_8==0)
				*GDRAM_low_byte=(*GDRAM_low_byte&(~(0x01<<(15-x_bit_8)))); 	//���GDRAM���е�8λ��������Ӧ�ĵ�
			 else if(color_8==2)
					*GDRAM_low_byte=(*GDRAM_low_byte^(0x01<<(15-x_bit_8))); //��������ȡ��һλ����
	}
	/*lcd_command_write(0x34);	//����ָ�����ͼ��ʾ��

	lcd_command_write(0x80+y_line_8);				//�趨�е�ַ��y���꣩����ֱ����
	lcd_command_write(0x80+x_word_8+8*y_screen_8);	//�趨�е�ַ��x���꣩��ˮƽ����
													//ͨ��y_screen_8ѡ������������ˮƽ��ַ	
	lcd_data_write(*GDRAM_high_byte);	//д��GDRAM���и�8λ����
	lcd_data_write(*GDRAM_low_byte);	//д��GDRAM���е�8λ����
	lcd_command_write(0x36);	//����ָ�����ͼ��ʾ��	
	lcd_command_write(0x30);	//����ָ�*/	
}


/**************************************************************************
//����
//���ܣ���ֱ��
//������
***************************************************************************/
void lcd_line_draw(unsigned char x0_8,unsigned char y0_8,
				   unsigned char x1_8,unsigned char y1_8,unsigned char color_8)
{
	;
}
/**************************************************************************
//����
//���ܣ���Բ
//������
***************************************************************************/
void lcd_circle_draw(unsigned char x_8,unsigned char y_8,unsigned char radius_8)
{
	;
}

/**************************************************************************
//����
//���ܣ�
//������
***************************************************************************/

/**************************************************************************
//����
//���ܣ�
//������
***************************************************************************/
