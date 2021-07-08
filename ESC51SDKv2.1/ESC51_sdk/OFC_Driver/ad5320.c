#include "ad5320.h"

#ifdef AD5320_CONFIG
/*------------------------------------------------
函数名:DA_AD5320()
功能:DA转换输出读取函数
参数：Dignum--DA输出值
返回值：无
------------------------------------------------*/
static void delay_ns(uint z)
{
	while(z--)  _nop_();
}
/*
void DA_AD5320(uint dat)
{
   uchar i;
   SYNC_IN = 1;
   SCLK_IN = 0;
   D_IN    = 0;
   SYNC_IN = 0;
   dat=dat<<4;
   for(i=0;i<12;i++)
    {
          D_IN=dat&0x8000;
          SCLK_IN = 1;
          _nop_();			
          dat = dat<<1;
          SCLK_IN = 0;
    }
   SYNC_IN = 1;
}
*/
void DA_AD5320(uint dat)
{
	uint i;
	SCLK_IN  = 1;
	SYNC_IN  = 1;
	delay_ns(40);
	SYNC_IN  = 0;
	delay_ns(20);
	dat      = dat & 0x0fff;
	for(i=0;i<16;i++)
	{
		D_IN     = dat & 0x8000;
		SCLK_IN  = 0;
		delay_ns(20);
		dat      = dat << 1;
		SCLK_IN  = 1;
		delay_ns(20);
	}
	SYNC_IN  = 1;
}

#endif /* AD5320_CONFIG */