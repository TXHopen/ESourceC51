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
 * @file      hcsr04.h
 * 
 * @brief     片外驱动：hcsr04模块驱动头文件
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
#ifndef __HCSR04_H
#define __HCSR04_H


#include "user_config_prj.h"

#ifdef HCSR04_CONFIG

#include "es_sys_package.h"

/* ------------------------------------------------------------------------------------------------------------------ */
sbit HCSR04_TRIG  =  P2^6;
sbit HCSR04_ECHO  =  P2^7;

/* ------------------------------------------------------------------------------------------------------------------ */
uint HCSR04_NoneRead (void);

#ifdef TIMER0_CONFIG

uint HCSR04_IntConfig (void);
uint HCSR04_InitReadcm (void);

#endif /* TIMER0_CONFIG */
/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* HCSR04_CONFIG */

#endif /* __HCSR04_H */
