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
 * @file      hw_Timer1.h
 * 
 * @brief     硬件支持组件：定时器1组件
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
#ifndef __HW_TIMER1_H
#define __HW_TIMER1_H


#include "user_config_prj.h"

#ifdef TIMER1_CONFIG

#include "hw_config.h"


/* ------------------------------------------------------------------------------------------------------------------ */

typedef enum _TIMER1_MODE
{
	TIMER1_MODE_0 = 0X00,
	TIMER1_MODE_1,
	TIMER1_MODE_2
} TIMER1_MODE;


/* ------------------------------------------------------------------------------------------------------------------ */


void Timer1Init(TIMER1_MODE mode, uint us, void *callback);
void Timer1Init_NoOpen(TIMER1_MODE mode, uint us, void *callback);
void Timer1Open(void);
void Timer1Close(void);
void Timer1Pause(void);
void Timer1Start(void);


/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* TIMER1_CONFIG */

#endif /* __HW_TIMER1_H */