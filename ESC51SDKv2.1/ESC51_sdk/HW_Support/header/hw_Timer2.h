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
 * @file      hw_Timer2.h
 * 
 * @brief     硬件支持组件：定时器2
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
#ifndef __HW_TIMER2_H
#define __HW_TIMER2_H


#include "user_config_prj.h"

#ifdef TIMER2_CONFIG

#include "es_sys_package.h"


/* ------------------------------------------------------------------------------------------------------------------ */


typedef enum _TIMER2_MODE
{
	TIMER2_MODE_CAPTURE = 0,
	TIMER2_MODE_TIMING
} TIMER2_MODE;


/* ------------------------------------------------------------------------------------------------------------------ */

void Timer2Init(TIMER2_MODE mode, uint us, void *callback);
void Timer2Init_NoOpen(TIMER2_MODE mode, uint us, void *callback);
void Timer2Open(void);
void Timer2Close(void);
void Timer2Pause(void);
void Timer2Start(void);


/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* TIMER2_CONFIG */

#endif /* __HW_TIMER2_H */