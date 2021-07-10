#include "hw_Timer2.h"

#ifdef TIMER2_CONFIG


static u8 timer_h;
static u8 timer_l;

static bit mode_flg = 0;

int (*pointer_interupt_timer2)(void *arg);

static int interupt_timer_function (void *arg) 
{
	return 0;
}



/*******************************************************************************
* 函 数 名         : Timer1Init
* 函数功能		   : 定时器1初始化
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Timer2Init(TIMER2_MODE mode, uint us, void *callback)
{
	switch (mode)
	{
		case TIMER2_MODE_CAPTURE:T2CON=0X09;  //设置T2为捕获模式，下降沿则产生中断
		                         timer_h = (65536-us) / 256;
		                         timer_l = (65536-us) % 256;
		                         break;
		case TIMER2_MODE_TIMING :T2CON=0X00;  //设置T2为捕获模式，下降沿则产生中断
		                         timer_h = (65536-us) / 256;
		                         timer_l = (65536-us) % 256;
		                         break;
		default:                 return ;
                                 break;
	}
	
	if (callback == NULL) {
		pointer_interupt_timer2 = interupt_timer_function;
	} else {
		pointer_interupt_timer2 = callback;
	}
	
	RCAP2H = timer_h;
	RCAP2L = timer_l;
	TH2 = RCAP2H;
	TL2 = RCAP2L;
	
	EA  = 1;
	
	TR2 = 1;
	ET2 = 1;
}




void Timer2Init_NoOpen(TIMER2_MODE mode, uint us, void *callback)
{
	TR2   = 0;//关闭定时器
	ET2   = 0;//关闭定时器1中断允许
	switch (mode)
	{
		case TIMER2_MODE_CAPTURE:T2CON=0X09;  //设置T2为捕获模式，下降沿则产生中断
		                         timer_h = (65536-us) / 256;
		                         timer_l = (65536-us) % 256;
		                         break;
		case TIMER2_MODE_TIMING :T2CON=0X00;  //设置T2为
		                         timer_h = (65536-us) / 256;
		                         timer_l = (65536-us) % 256;
		                         break;
		default:                 return ;
                                 break;
	}
	
	if (callback == NULL) {
		pointer_interupt_timer2 = interupt_timer_function;
	} else {
		pointer_interupt_timer2 = callback;
	}
	
	RCAP2H = timer_h;
	RCAP2L = timer_l;
	TH2 = RCAP2H;
	TL2 = RCAP2L;
	
	TR2 = 0;
	ET2 = 0;
	
	EA  = 1;
}

void Timer2Open(void)
{
	ET2   = 1;//打开定时器0中断允许
	TR2   = 1;//打开定时器
}

void Timer2Close(void)
{
	TR2   = 0;//关闭定时器
	ET2   = 0;//关闭定时器0中断允许
}

void Timer2Pause(void)
{
	TR2   = 0;//关闭定时器
}

void Timer2Start(void)
{
	TR2   = 1;//打开定时器
}





/*******************************************************************************
* 函 数 名         : void Timer2() interrupt 5
* 函数功能		   : 定时器0中断函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Timer2() interrupt 5
{
	TF2   = 0;
	
	pointer_interupt_timer2(NULL);
	
}
#endif /* TIMER2_CONFIG */

