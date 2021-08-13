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
 * @file      hw_Timer2.c
 * 
 * @brief     硬件支持组件：定时器2
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
#include "hw_Timer2.h"

#ifdef TIMER2_CONFIG
/* ------------------------------------------------------------------------------------------------------------------ */

static u8 timer_h;
static u8 timer_l;

static bit mode_flg = 0;

int (*pointer_interupt_timer2)(void *arg);

static int interupt_timer_function (void *arg) 
{
	return 0;
}




void Timer2() interrupt 5
{
	TF2   = 0;
	
	pointer_interupt_timer2(NULL);
	
}

/* ------------------------------------------------------------------------------------------------------------------ */
void Timer2Init(TIMER2_MODE mode, uint us, void *callback)
{
	switch (mode)
	{
		case TIMER2_MODE_CAPTURE:T2CON=0X09;
		                         timer_h = (65536-us) / 256;
		                         timer_l = (65536-us) % 256;
		                         break;
		case TIMER2_MODE_TIMING :T2CON=0X00;
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
	TR2   = 0;
	ET2   = 0;
	switch (mode)
	{
		case TIMER2_MODE_CAPTURE:T2CON=0X09;
		                         timer_h = (65536-us) / 256;
		                         timer_l = (65536-us) % 256;
		                         break;
		case TIMER2_MODE_TIMING :T2CON=0X00;
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
	ET2   = 1;
	TR2   = 1;
}

void Timer2Close(void)
{
	TR2   = 0;
	ET2   = 0;
}

void Timer2Pause(void)
{
	TR2   = 0;
}

void Timer2Start(void)
{
	TR2   = 1;
}




/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* TIMER2_CONFIG */

