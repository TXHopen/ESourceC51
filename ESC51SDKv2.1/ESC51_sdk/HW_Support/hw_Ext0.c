#include "hw_Ext0.h"

#ifdef EXT1_CONFIG





static int (*pointer_interupt_ext0)(void *arg);

static int interupt_ext0_function (void *arg) 
{
	return 0;
}

/*******************************************************************************
* �� �� ��         : Ext0Init
* ��������		   : 1��ʼ��
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
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



/*******************************************************************************
* �� �� ��         : void Ext0() interrupt 2
* ��������		   : 1�жϺ���
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void Ext0() interrupt 2
{
	pointer_interupt_ext0(NULL);
}



#endif /* TIMER0_CONFIG */