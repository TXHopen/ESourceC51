/***********************************************************************************************************************
 *                                                      ESourceOpen
 *                                           -----------------------------------
 *                                           explore and open  embedded platform
 * 
 * Contact information:
 * e-mail: 1786409879@qq.com / txh17778443952@169.com
 *                                                                                 +-------------+---------------------+
 * ESourceOpen：                                                                   |   founder   |       TXHopen       |
 *   The ESource plan is a difficult and long-term plan. This plan                 +-------------+---------------------+
 *   does not limit the use of code, only to provide an open platform              |   encode    |    UTF-8 / utf-8    |
 *   to explore the software development of embedded platforms.                    +-------------+---------------------+
***********************************************************************************************************************/
/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      hw_Timer1.c
 * 
 * @brief     硬件支持组件：定时器1源码
 * 
 * @version   V0.00.01
 * 
 * @author    TXHopen (3332695529@qq.com)
 * 
 * @date      2021-08-08
 * 
 * @copyright Copyright (c) 2021
 * 
 * *****************************************************ESourceOPEN*****************************************************
 * 
 * *****************************************************ESourceOPEN*****************************************************
 **/
#include "hw_Timer1.h"

#ifdef TIMER1_CONFIG

/* ------------------------------------------------------------------------------------------------------------------ */


static u8 timer_h;
static u8 timer_l;

static bit mode_flg = 0;


static int (*pointer_interupt_timer1)(void *arg);


static int interupt_timer_function (void *arg) 
{
	return 0;
}




void Timer1() interrupt 3
{
	if (mode_flg == 0) {
		TH1 = timer_h;
		TL1 = timer_l;
	}
	
	pointer_interupt_timer1(NULL);
}


/* ------------------------------------------------------------------------------------------------------------------ */
void Timer1Init(TIMER1_MODE mode, uint us, void *callback)
{
	switch (mode)
	{
		case TIMER1_MODE_0:TMOD   |= 0X00;
		                   timer_h = (8192-us) / 8;
		                   timer_l = (8192-us) % 8;
		                   break;
		case TIMER1_MODE_1:TMOD   |= 0X10;
		                   timer_h = (65536-us) / 256;
		                   timer_l = (65536-us) % 256;
		                   break;
		case TIMER1_MODE_2:TMOD   |= 0X20;
		                   timer_h = (256-us) % 256;
		                   timer_l = timer_h;
		                   break;
		default:return ;   break;
	}
	
	if (callback == NULL) {
		pointer_interupt_timer1 = interupt_timer_function;
	} else {
		pointer_interupt_timer1 = callback;
	}
	
	TH1   = timer_h;
	TL1   = timer_l;	
	ET1=1;
	EA=1;
	TR1=1;	
}






void Timer1Init_NoOpen(TIMER1_MODE mode, uint us, void *callback)
{
	TR1   = 0;
	ET1   = 0;
	switch (mode)
	{
		case TIMER1_MODE_0:TMOD   |= 0X00;
		                   timer_h = (8192-us) / 8;
		                   timer_l = (8192-us) % 8;
		                   break;
		case TIMER1_MODE_1:TMOD   |= 0X10;
		                   timer_h = (65536-us) / 256;
		                   timer_l = (65536-us) % 256;
		                   break;
		case TIMER1_MODE_2:TMOD   |= 0X20;
		                   timer_h = (256-us) % 256;
		                   timer_l = timer_h;
		                   mode_flg = 1;
		                   break;
		default:return ;   break;
	}
	
	if (callback == NULL) {
		pointer_interupt_timer1 = interupt_timer_function;
	} else {
		pointer_interupt_timer1 = callback;
	}
	
	TH1   = timer_h;
	TL1   = timer_l;	
	ET1   = 0;
	EA    = 1;
	TR1   = 0;
}

void Timer1Open(void)
{
	TH1   = timer_h;
	TL1   = timer_l;
	ET1   = 1;
	TR1   = 1;
}

void Timer1Close(void)
{
	TR1   = 0;
	ET1   = 0;
	TH1   = timer_h;
	TL1   = timer_l;	
}

void Timer1Pause(void)
{
	TR1   = 0;
	ET1   = 0;
}

void Timer1Start(void)
{
	ET1   = 1;
	TR1   = 1;
}








/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* TIMER1_CONFIG */

