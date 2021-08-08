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
 * @file      hw_Timer0.h
 * 
 * @brief     硬件支持组件：定时器0组件
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
#ifndef __HW_TIMER0_H
#define __HW_TIMER0_H


#include "user_config_prj.h"

#ifdef TIMER0_CONFIG

#include "es_sys_package.h"


/* ------------------------------------------------------------------------------------------------------------------ */
typedef enum _TIMER0_MODE
{
	TIMER0_MODE_0 = 0x00,
	TIMER0_MODE_1,
	TIMER0_MODE_2,
	TIMER0_MODE_3
} TIMER0_MODE;



/* ------------------------------------------------------------------------------------------------------------------ */

void Timer0Init(TIMER0_MODE mode, uint16_t us, void *callback);

void Timer0Settime(uint16_t us);

void Timer0Init_NoOpen(TIMER0_MODE mode, uint16_t us, void *callback);
void Timer0Open(void);
void Timer0Close(void);




/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* TIMER0_CONFIG */

#endif /* __HW_TIMER0_H */