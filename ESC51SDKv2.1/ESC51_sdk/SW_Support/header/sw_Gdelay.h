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
 * @file      sw_Gdelay.h
 * 
 * @brief     通用延时函数组件头文件，包含延时函数API
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
#ifndef __SW_GDELAY_H
#define __SW_GDELAY_H


#include "user_config_prj.h"

#ifdef SW_GDELAY_CONFIG

#include "es_sys_package.h"

/* ------------------------------------------------------------------------------------------------------------------ */
/* 组件API */

void es_delay_ms (uint ms);
void es_delay_10ms (uint ms10);

void es_delay_ns (uint ns);
void es_delay_10ns (uint ns10);

/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* SW_GDELAY_CONFIG */

#endif /* __SW_GDELAY_H */
