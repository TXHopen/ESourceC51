/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      hw_Ext1.c
 * 
 * @brief     硬件支持组件：外部中断1源码
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
#include "hw_Ext1.h"

#ifdef EXT1_CONFIG


/* ------------------------------------------------------------------------------------------------------------------ */


static int (*pointer_interupt_ext1)(void *arg);

static int interupt_ext1_function (void *arg) 
{
	return 0;
}




void Ext1() interrupt 2
{
	pointer_interupt_ext1(NULL);
}

/* ------------------------------------------------------------------------------------------------------------------ */


void Ext1Init(EXT1_MODE mode, void *pfunc)
{
	EX0   = 0;//�ر��ж�����
	switch (mode)
	{
		case EXT1_MODE_LEVEL:IT0 = 0;
		                     break;
		case EXT1_MODE_FEDGE:IT0 = 1;
		                     break;
		default:return ;     break;
	}
	
	if (pfunc == NULL) {
		pointer_interupt_ext1 = interupt_ext1_function;
	} else {
		pointer_interupt_ext1 = pfunc;
	}

	EX0   = 1;
	EA    = 1;
}


void Ext1Init_NoOpen(EXT1_MODE mode, void *pfunc)
{
	EX0   = 0;
	switch (mode)
	{
		case EXT1_MODE_LEVEL:IT0 = 0;
		                     break;
		case EXT1_MODE_FEDGE:IT0 = 1;
		                     break;
		default:return ;     break;
	}
	
	if (pfunc == NULL) {
		pointer_interupt_ext1 = interupt_ext1_function;
	} else {
		pointer_interupt_ext1 = pfunc;
	}

	EX0   = 0;
	EA    = 1;
}

void Ext1Open(void)
{
	EX0 = 1;
}
void Ext1Close(void)
{
	EX0 = 0;
}
void Ext1Pause(void)
{
	
}
void Ext1Start(void)
{
	
}





/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* TIMER0_CONFIG */