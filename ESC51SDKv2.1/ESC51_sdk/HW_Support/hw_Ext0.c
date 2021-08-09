/***********************************************************************************************************************
 *                                                      ESourceOpen
 *                                           -----------------------------------
 *                                           explore and open  embedded platform
 * 
 * Contact information:
 * e-mail: 1786409879@qq.com / txh17778443952@169.com
 *                                                                                                              
 *                                                                                                              TXHopen
 *                                                                                                         encode:UTF-8
***********************************************************************************************************************/
/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      hw_Ext0.c
 * 
 * @brief     硬件支持组件：外部中断0源码
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
#include "hw_Ext0.h"

#ifdef EXT1_CONFIG



/* ------------------------------------------------------------------------------------------------------------------ */

static int (*pointer_interupt_ext0)(void *arg);

static int interupt_ext0_function (void *arg) 
{
	return 0;
}



void Ext0() interrupt 2
{
	pointer_interupt_ext0(NULL);
}
/* ------------------------------------------------------------------------------------------------------------------ */

void Ext0Init(EXT0_MODE mode, void *pfunc)
{
	EX0   = 0;                         //关闭外部中断0使能
	switch (mode)
	{
		case EXT0_MODE_LEVEL:IT0 = 0;
		                     break;
		case EXT0_MODE_FEDGE:IT0 = 1;
		                     break;
		default:return ;     break;
	}
	
	if (pfunc == NULL) {
		pointer_interupt_ext0 = interupt_ext0_function;
	} else {
		pointer_interupt_ext0 = pfunc;
	}

	EX0   = 1;                         //打开外部中断0使能
	EA    = 1;                         //打开总中断使能
}


void Ext0Init_NoOpen(EXT0_MODE mode, void *pfunc)
{
	EX0   = 0;                         //关闭外部中断0使能
	switch (mode)
	{
		case EXT0_MODE_LEVEL:IT0 = 0;
		                     break;
		case EXT0_MODE_FEDGE:IT0 = 1;
		                     break;
		default:return ;     break;
	}
	
	if (pfunc == NULL) {
		pointer_interupt_ext0 = interupt_ext0_function;
	} else {
		pointer_interupt_ext0 = pfunc;
	}

	EX0   = 0;                         //关闭外部中断0使能
	EA    = 1;                         //打开总中断使能
}

void Ext0Open(void)
{
	EX0 = 1;
}
void Ext0Close(void)
{
	EX0 = 0;
}
void Ext0Pause(void)
{
	
}
void Ext0Start(void)
{
	
}




/* ------------------------------------------------------------------------------------------------------------------ */

#endif /* TIMER0_CONFIG */