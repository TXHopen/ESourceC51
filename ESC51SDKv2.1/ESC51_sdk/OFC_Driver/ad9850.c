#include "ad9850.h"

#ifdef AD9850_CONFIG




void ad9850_reset_serial()
{
	AD9850_CLK=0;
	AD9850_UD=0;
	//rest信号
	AD9850_REST=0;
	AD9850_REST=1;
	AD9850_REST=0;
	//w_clk信号
	AD9850_CLK=0;
	AD9850_CLK=1;
	AD9850_CLK=0;
	//fq_up信号
	AD9850_UD=0;
	AD9850_UD=1;
	AD9850_UD=0;
}

void ad9850_wr_serial(unsigned char w0,double frequence)
{
	unsigned char i,w;
	long int y;
	double x;
	//计算频率的HEX值
	x=4294967295/125;//适合125M晶振
	//如果时钟频率不为180MHZ，修改该处的频率值，单位MHz  ！！！
	frequence=frequence/1000000;
	frequence=frequence*x;
	y=frequence;
	//写w4数据
	w=(y>>=0);
	for(i=0;i<8;i++)
	{
		AD9850_DATA=(w>>i)&0x01;
		AD9850_CLK=1;
		AD9850_CLK=0;
	}
	//写w3数据
	w=(y>>8);
	for(i=0;i<8;i++)
	{
		AD9850_DATA=(w>>i)&0x01;
		AD9850_CLK=1;
		AD9850_CLK=0;
	}
	//写w2数据
	w=(y>>16);
	for(i=0;i<8;i++)
	{
		AD9850_DATA=(w>>i)&0x01;
		AD9850_CLK=1;
		AD9850_CLK=0;
	}
	//写w1数据
	w=(y>>24);
	for(i=0;i<8;i++)
	{
		AD9850_DATA=(w>>i)&0x01;
		AD9850_CLK=1;
		AD9850_CLK=0;
	}
	//写w0数据
	w=w0;   
	for(i=0;i<8;i++)
	{
		AD9850_DATA=(w>>i)&0x01;
		AD9850_CLK=1;
		AD9850_CLK=0;
	}
	//移入始能
	AD9850_UD=1;
	AD9850_UD=0;
}


#endif /* AD9850_CONFIG */

