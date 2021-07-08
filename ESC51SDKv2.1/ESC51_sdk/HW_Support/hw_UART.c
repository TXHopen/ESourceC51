#include "hw_UART.h"

#ifdef UART_CONFIG





#ifndef TIMER1_CONFIG




int (*pointer_interupt_uart)(void *arg);

static int interupt_uart_function (void *arg) 
{
	void *ptr = arg;
	return 0;
}

void UART_Init(void *callback)
{
	if (callback == NULL) {
		pointer_interupt_uart = interupt_uart_function;
	} else {
		pointer_interupt_uart = callback;
	}
	
	SCON  = 0X50;			//设置为工作方式1
	TMOD &= 0X0F;			//设置计数器工作方式2
	TMOD |= 0X20;			//设置计数器工作方式2
	PCON  = 0X80;			//波特率加倍
	TH1   = RELOAD_COUNT;	//计数器初始值设置
	TL1   = TH1;
	ES  = 1;				//关闭接收中断
	EA  = 1;				//打开总中断
	TR1 = 1;				//打开计数器
}

void UART_SendByte(u8 dat)
{
	ES = 0;               //关闭串口中断
	TI = 0;               //清发送完毕中断请求标志位
	SBUF = dat;           //发送
	while(TI == 0);       //等待发送完毕
	TI = 0;               //清发送完毕中断请求标志位
	ES = 1;               //允许串口中断
}

void UART_SendStr(uchar *str)
{
    while(*str!= '\0')
	{
        UART_SendByte(*str);
        str++;
    }
}

void UART_SendByteArr(uchar *byte_arr, uint arr_len)
{
	int curt_num = 0;
	for(curt_num = 0; curt_num < arr_len; curt_num++)
	{
        UART_SendByte(byte_arr[curt_num]);
        arr_len--;
    }
}

void Usart() interrupt 4
{
	
	pointer_interupt_uart(NULL);

}



#else

#warning UART is Disable

#endif /* TIMER1_CONFIG */


#endif /* UART_CONFIG */
