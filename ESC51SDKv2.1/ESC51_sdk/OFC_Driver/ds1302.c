#include "ds1302.h"

#ifdef DS1302_CONFIG


uchar code READ_RTC_ADDR[7]  = {0x81, 0x83, 0x85, 0x87, 0x89, 0x8b, 0x8d}; 
uchar code WRITE_RTC_ADDR[7] = {0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c};

/*------------------------------------------------
                 DS1302写字节函数
------------------------------------------------*/
void DS1302_WriteByte(uchar dat)
{
	uchar i;
	for(i = 0;i < 8;i++)
	{
		DS1302_CLK  = 0;
		DS1302_Data = dat & 0x01;
		dat       >>= 1;
		DS1302_CLK  = 1;
	}
}
/*------------------------------------------------
                DS302写数据函数
------------------------------------------------*/
void DS1302_Write(uchar addr,uchar dat)
{
	DS1302_RST   = 0;
	_nop_();
	DS1302_CLK   = 0;
	_nop_();
	DS1302_RST   = 1;
	_nop_();
	DS1302_WriteByte(addr);
	DS1302_WriteByte(dat);
	DS1302_RST   = 0;
}
/*------------------------------------------------
                 DS1302读数据函数
------------------------------------------------*/
uchar DS1302_Read(uchar addr)
{
	uchar i;
	uchar mask = 0x00;
	DS1302_RST   = 0;
	DS1302_CLK   = 0;
	DS1302_RST   = 1;
	DS1302_WriteByte(addr);
	for(i = 0;i < 8;i++)
	{
		if(DS1302_Data) {
			mask  |= 0x80;
		}
		mask     >>= 1;
		DS1302_CLK = 1;
		DS1302_CLK = 0;
	}
	DS1302_CLK   = 1;
	DS1302_RST   = 0;
	return mask;
}

void DS1302_Init(void)
{
	uchar n;
	uchar TIME[7] = {0, 0, 0x12, 0x01, 0x01, 0x02, 0x13};
	DS1302_Write(0x8E,0X00);
	for (n=0; n<7; n++) {
		DS1302_Write(WRITE_RTC_ADDR[n],TIME[n]);	
	}
	DS1302_Write(0x8E,0x80);
}

#endif /* DS1302_CONFIG */