#include "LCD1602.h"

#ifdef LCD1602_CONFIG


/*------------------------------------------------
                 LCD1602读忙函数
------------------------------------------------*/
static void LCD1602_Wait(void)
{
	uchar sta;
	LCD1602_Data   = 0xff;
	LCD1602_RS     = 0;
	LCD1602_RW     = 1;
	do
	{
		LCD1602_EN = 1;
		sta        = LCD1602_Data;
		LCD1602_EN = 0;
	}while(sta & 0x80);
}
/*------------------------------------------------
                LCD1602写命令函数
------------------------------------------------*/
void LCD1602_WriteCmd(uchar cmd)
{
	LCD1602_Wait();
	LCD1602_RS  = 0;
	LCD1602_RW  = 0;
	LCD1602_Data= cmd;
	LCD1602_EN  = 1;
	LCD1602_EN  = 0;
}
/*------------------------------------------------
                 LCD1602写数据函数
------------------------------------------------*/
void LCD1602_WriteDat(uchar dat)
{
	LCD1602_Wait();
	LCD1602_RS  = 1;
	LCD1602_RW  = 0;
	LCD1602_Data= dat;
	LCD1602_EN  = 1;
	LCD1602_EN  = 0;
}
/*------------------------------------------------
                 LCD1602写地址函数
------------------------------------------------*/
static void LCD1602_SetCursor(uchar x,uchar y)
{
	uchar addr;
	if(y == 0)
		addr = 0x00 + x;
	else
		addr = 0x40 + x;
	LCD1602_WriteCmd(addr | 0x80);
}
/*------------------------------------------------
                 LCD1602写字符函数
------------------------------------------------*/

void LCD1602_ShowByte(uchar x,uchar y,uchar byte)
{
	LCD1602_SetCursor(x,y);
	LCD1602_WriteDat(byte);
}


/*------------------------------------------------
                 LCD1602写字符串函数
------------------------------------------------*/

void LCD1602_ShowStr(uchar x,uchar y,uchar *str)
{
	LCD1602_SetCursor(x,y);
	while(*str != '\0')
	{
		LCD1602_WriteDat(*str++);
	}
}


void LCD1602_ShowLine (uchar *line1, uchar *line2)
{
	uchar i = 0;
	
	LCD1602_SetCursor(0,0);
	for (i = 0; i < 16; i++) {
		LCD1602_WriteDat(*line1++);
	}
	LCD1602_SetCursor(0,1);
	for (i = 0; i < 16; i++) {
		LCD1602_WriteDat(*line2++);
	}
}

void LCD1602_Show_cursor(u8 x, u8 y)
{
	LCD1602_SetCursor(x,y);
	LCD1602_WriteCmd(0x0f);
}
void LCD1602_DisShow_cursor(void)
{
	LCD1602_WriteCmd(0x0c);
}
/*------------------------------------------------
                  LCD1602初始化函数
------------------------------------------------*/
void LCD1602_Init(void)
{
	LCD1602_WriteCmd(0x38);
	LCD1602_WriteCmd(0x0c);
	LCD1602_WriteCmd(0x06);
	LCD1602_WriteCmd(0x01);
}

#endif /* LCD1602_CONFIG */