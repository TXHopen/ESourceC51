/***********************************************************************************************************************
 *                                                      ESourceOpen
 *                                           -----------------------------------
 *                                           explore and open  embedded platform
 * 
 * Contact information:
 * e-mail: 1786409879@qq.com / txh17778443952@169.com
 *                                                                                                              TXHopen
***********************************************************************************************************************/
/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      hw_UART.c
 * 
 * @brief     硬件支持
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
#include "hw_UART.h"

#ifdef UART_CONFIG





#ifndef TIMER1_CONFIG

/* ------------------------------------------------------------------------------------------------------------------ */


int (*pointer_interupt_uart)(void *arg);

static int interupt_uart_function (void *arg) 
{
	return 0;
}

void Usart() interrupt 4
{
	
	pointer_interupt_uart(NULL);

}

/* ------------------------------------------------------------------------------------------------------------------ */
void UART_Init(void *callback)
{
	if (callback == NULL) {
		pointer_interupt_uart = interupt_uart_function;
	} else {
		pointer_interupt_uart = callback;
	}
	
	SCON  = 0X50;
	TMOD &= 0X0F;
	TMOD |= 0X20;
	PCON  = 0X80;
	TH1   = RELOAD_COUNT;
	TL1   = TH1;
	ES  = 1;
	EA  = 1;
	TR1 = 1;
}

void UART_SendByte(u8 dat)
{
	ES = 0;
	TI = 0;
	SBUF = dat;
	while(TI == 0);
	TI = 0;
	ES = 1;
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




/* ------------------------------------------------------------------------------------------------------------------ */
#else

#warning UART is Disable

#endif /* TIMER1_CONFIG */


#endif /* UART_CONFIG */
