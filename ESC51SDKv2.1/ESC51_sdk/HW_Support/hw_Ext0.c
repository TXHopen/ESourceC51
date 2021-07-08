#include "hw_Ext0.h"

#ifdef EXT1_CONFIG





static int (*pointer_interupt_ext0)(void *arg);

static int interupt_ext0_function (void *arg) 
{
	void *ptr = arg;
	return 0;
}

/*******************************************************************************
* 函 数 名         : Ext0Init
* 函数功能		   : 1初始化
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Ext0Init(EXT0_MODE mode, void *pfunc)
{
	EX0   = 0;//关闭中断允许
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

	EX0   = 1;//关闭中断允许
	EA    = 1;//打开总中断
}


void Ext0Init_NoOpen(EXT0_MODE mode, void *pfunc)
{
	EX0   = 0;//关闭中断允许
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

	EX0   = 0;//关闭中断允许
	EA    = 1;//打开总中断
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



/*******************************************************************************
* 函 数 名         : void Ext0() interrupt 2
* 函数功能		   : 1中断函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Ext0() interrupt 2
{
	pointer_interupt_ext0(NULL);
}



#endif /* TIMER0_CONFIG */