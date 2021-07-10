#include "hw_Ext1.h"

#ifdef EXT1_CONFIG





static int (*pointer_interupt_ext1)(void *arg);

static int interupt_ext1_function (void *arg) 
{
	return 0;
}

/*******************************************************************************
* 函 数 名         : Ext1Init
* 函数功能		   : 1初始化
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Ext1Init(EXT1_MODE mode, void *pfunc)
{
	EX0   = 0;//关闭中断允许
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

	EX0   = 1;//关闭中断允许
	EA    = 1;//打开总中断
}


void Ext1Init_NoOpen(EXT1_MODE mode, void *pfunc)
{
	EX0   = 0;//关闭中断允许
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

	EX0   = 0;//关闭中断允许
	EA    = 1;//打开总中断
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



/*******************************************************************************
* 函 数 名         : void Ext1() interrupt 2
* 函数功能		   : 1中断函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Ext1() interrupt 2
{
	pointer_interupt_ext1(NULL);
}



#endif /* TIMER0_CONFIG */