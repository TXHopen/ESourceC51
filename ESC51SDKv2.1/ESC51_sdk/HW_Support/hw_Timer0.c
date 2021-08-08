/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      hw_Timer0.c
 * 
 * @brief     硬件支持组件：定时器0源码
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
#include "hw_Timer0.h"

#ifdef TIMER0_CONFIG
/* ------------------------------------------------------------------------------------------------------------------ */

static u8 timer_h;
static u8 timer_l;

static u8 timer_mode;



static int (*pointer_interupt_timer0)(void *arg);

static int interupt_timer_function (void *arg) 
{
	return 0;
}


void Timer0() interrupt 1
{
	if (timer_mode != TIMER0_MODE_2) {
		TH0 = timer_h;
		TL0 = timer_l;
	}
	pointer_interupt_timer0(NULL);
}
/* ------------------------------------------------------------------------------------------------------------------ */
void Timer0Init(TIMER0_MODE mode, uint16_t us, void *callback)
{
	timer_mode = mode;
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
	
	TH0   = timer_h;
	TL0   = timer_l;	
	ET0   = 1;
	EA    = 1;
	TR0   = 1;
}

void Timer0Init_NoOpen(TIMER0_MODE mode, uint16_t us, void *callback)
{
	timer_mode = mode;
	TR0   = 0;
	ET0   = 0;
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
	
	TH0   = timer_h;
	TL0   = timer_l;	
	ET0   = 0;
	EA    = 1;
	TR0   = 0;
}

void Timer0Settime(uint16_t us)
{
	TR0 = 0;
	switch (timer_mode)
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
	TR0 = 1;
}

void Timer0Open(void)
{
	ET0   = 1;
	TR0   = 1;
}

void Timer0Close(void)
{
	TR0   = 0;
	ET0   = 0;
	TH0   = timer_h;
	TL0   = timer_l;	
}





/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* TIMER0_CONFIG */