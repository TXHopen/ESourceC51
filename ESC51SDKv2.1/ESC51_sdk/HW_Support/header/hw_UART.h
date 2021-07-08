#ifndef __HW_UART_H
#define __HW_UART_H

#include "user_config_prj.h"

#ifdef UART_CONFIG

#include "hw_config.h"


#define RELOAD_COUNT 0xFA //宏定义波特率发生器的载入值 9600





void UART_Init(void *callback);
void UART_SendByte(uchar dat);
void UART_SendStr(uchar *str);
void UART_SendByteArr(uchar *byte_arr, uint arr_len);

#endif /* UART_CONFIG */

#endif /* __HW_UART_H */
