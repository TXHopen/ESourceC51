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
 * @file      hw_UART.h
 * 
 * @brief     硬件支持组件：串口组件
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
#ifndef __HW_UART_H
#define __HW_UART_H

#include "user_config_prj.h"

#ifdef UART_CONFIG

#include "hw_config.h"

/* ------------------------------------------------------------------------------------------------------------------ */

#define RELOAD_COUNT 0xFA //宏定义波特率发生器的载入值 9600



/* ------------------------------------------------------------------------------------------------------------------ */

void UART_Init(void *callback);
void UART_SendByte(uchar dat);
void UART_SendStr(uchar *str);
void UART_SendByteArr(uchar *byte_arr, uint arr_len);

/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* UART_CONFIG */

#endif /* __HW_UART_H */
