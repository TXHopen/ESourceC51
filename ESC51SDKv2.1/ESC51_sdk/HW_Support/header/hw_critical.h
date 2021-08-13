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
 * @file      hw_critical.h
 * 
 * @brief     硬件支持组件：临界操作，包含API
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
#ifndef __HW_CRITICAL_H
#define __HW_CRITICAL_H

#include "es_sys_package.h"

/* ------------------------------------------------------------------------------------------------------------------ */
/* 组件API */

#define CRITICAL_SECTION_SET()   EA = 0;                              /* 设置代码临界区                                */
#define CRITICAL_SECTION_CLEAR() EA = 1;                              /* 取消代码临界区                                */


/* ------------------------------------------------------------------------------------------------------------------ */

#endif /* __HW_CRITICAL_H */
