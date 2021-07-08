#include "ad0809.h"

#ifdef AD0809_CONFIG



static void ad0809_delay(uchar i)
{
	uchar j;
	while(i--)
	{
		for(j=125;j>0;j--);
	}
}


int ad0809_read(uchar channel, uchar *ad_data)
{
	AD_START = 0;
	switch (channel)
	{
		case 0:AD_ADDCS_A = 0;
		       AD_ADDCS_B = 0;
			   AD_ADDCS_C = 0;
		       break;
		case 1:AD_ADDCS_A = 1;
		       AD_ADDCS_B = 0;
			   AD_ADDCS_C = 0;
		       break;
		case 2:AD_ADDCS_A = 0;
		       AD_ADDCS_B = 1;
			   AD_ADDCS_C = 0;
		       break;
		case 3:AD_ADDCS_A = 1;
		       AD_ADDCS_B = 1;
			   AD_ADDCS_C = 0;
		       break;
		case 4:AD_ADDCS_A = 0;
		       AD_ADDCS_B = 0;
			   AD_ADDCS_C = 1;
		       break;
		case 5:AD_ADDCS_A = 1;
		       AD_ADDCS_B = 0;
			   AD_ADDCS_C = 1;
		       break;
		case 6:AD_ADDCS_A = 0;
		       AD_ADDCS_B = 1;
			   AD_ADDCS_C = 1;
		       break;
		case 7:AD_ADDCS_A = 1;
		       AD_ADDCS_B = 1;
			   AD_ADDCS_C = 1;
		       break;
		default:
			   AD_ADDCS_A = 0;
		       AD_ADDCS_B = 0;
			   AD_ADDCS_C = 0;
		       break;
	}
	ad0809_delay(10);
	AD_START = 1;
	ad0809_delay(10);
	AD_START = 0;
	while(0  == AD_EOC);
	AD_OUTEN = 1;
	*ad_data = AD_DATA;
	AD_OUTEN = 0;
	
	return 0;
}

void ad0809_clk_init()
{
	EA       = 1;    //开总中断
	TMOD     = 0x02; //设定定时器T0工作方式
	TH0      = 216;  //利用T0中断产生CLK信号
	TL0      = 216;
	TR0      = 1;    //启动定时器T0
	ET0      = 1;
	AD_START = 0;
	AD_OUTEN = 0;
}

void t0(void) interrupt 1 using 0
{
	AD_CLK =~ AD_CLK;
}

#endif /* AD0809_CONFIG */
