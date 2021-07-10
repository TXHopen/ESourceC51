#include "hw_Timer0.h"

#ifdef TIMER0_CONFIG
//#ifndef GTIMER_CONFIG


static u8 timer_h;
static u8 timer_l;

static bit mode_flg = 0;

static int (*pointer_interupt_timer0)(void *arg);

static int interupt_timer_function (void *arg) 
{
	return 0;
}

/*******************************************************************************
* 函 数 名         : Timer0Init
* 函数功能		   : 定时器0初始化
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Timer0Init(TIMER0_MODE mode, uint us, void *callback)
{
	switch (mode)
	{
		case TIMER0_MODE_0:TMOD   |= 0X00;
		                   timer_h = (8192-us) / 8;
		                   timer_l = (8192-us) % 8;
		                   break;
		case TIMER0_MODE_1:TMOD   |= 0X01;
		                   timer_h = (65536-us) / 256;
		                   timer_l = (65536-us) % 256;
		                   break;
		case TIMER0_MODE_2:TMOD   |= 0X02;
		                   timer_h = (256-us) % 256;
		                   timer_l = timer_h;
						   mode_flg = 1;
		                   break;
		case TIMER0_MODE_3:TMOD   |= 0X03;
		                   timer_h = (8192-us) / 8;
		                   timer_l = (8192-us) % 8;
		                   break;
		default:return ;   break;
	}
	
	if (callback == NULL) {
		pointer_interupt_timer0 = interupt_timer_function;
	} else {
		pointer_interupt_timer0 = callback;
	}
	
	TH0   = timer_h;	//给定时器赋初值，定时1ms
	TL0   = timer_l;	
	ET0   = 1;//打开定时器0中断允许
	EA    = 1;//打开总中断
	TR0   = 1;//打开定时器
}

void Timer0Init_NoOpen(TIMER0_MODE mode, uint us, void *callback)
{
	TR0   = 0;//关闭定时器
	ET0   = 0;//关闭定时器0中断允许
	switch (mode)
	{
		case TIMER0_MODE_0:TMOD   |= 0X00;
		                   timer_h = (8192-us) / 8;
		                   timer_l = (8192-us) % 8;
		                   break;
		case TIMER0_MODE_1:TMOD   |= 0X01;
		                   timer_h = (65536-us) / 256;
		                   timer_l = (65536-us) % 256;
		                   break;
		case TIMER0_MODE_2:TMOD   |= 0X02;
		                   timer_h = (256-us) % 256;
		                   timer_l = timer_h;
		                   break;
		case TIMER0_MODE_3:TMOD   |= 0X03;
		                   timer_h = (8192-us) / 8;
		                   timer_l = (8192-us) % 8;
		                   break;
		default:return ;   break;
	}
	
	if (callback == NULL) {
		pointer_interupt_timer0 = interupt_timer_function;
	} else {
		pointer_interupt_timer0 = callback;
	}
	
	TH0   = timer_h;	//给定时器赋初值，定时1ms
	TL0   = timer_l;	
	ET0   = 0;//关闭定时器0中断允许
	EA    = 1;//打开总中断
	TR0   = 0;//打开定时器
}

void Timer0Open(void)
{
	ET0   = 1;//打开定时器0中断允许
	TR0   = 1;//打开定时器
}

void Timer0Close(void)
{
	TR0   = 0;//关闭定时器
	ET0   = 0;//关闭定时器0中断允许
	TH0   = timer_h;	//给定时器赋初值，定时1ms
	TL0   = timer_l;	
}



/*******************************************************************************
* 函 数 名         : void Timer0() interrupt 1
* 函数功能		   : 定时器0中断函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Timer0() interrupt 1
{
	if (mode_flg == 0) {
		TH0 = timer_h;	//给定时器赋初值
		TL0 = timer_l;
	}
	pointer_interupt_timer0(NULL);
}

//#endif /* GTIMER_CONFIG */

#endif /* TIMER0_CONFIG */