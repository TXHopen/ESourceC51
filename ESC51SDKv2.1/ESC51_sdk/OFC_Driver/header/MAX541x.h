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
 * @file      MAX541x.h
 * 
 * @brief     片外驱动：max541x驱动头文件
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
#ifndef  _MAX541X_H
#define  _MAX541X_H


#include "user_config_prj.h"

#ifdef MAX541X_CONFIG

#include "es_sys_package.h"
/* ------------------------------------------------------------------------------------------------------------------ */
sbit    MAX541X_CLK       = P2^3;
sbit    MAX541X_DIN       = P2^4;
sbit    MAX541X_CS	      = P2^6;
/* ------------------------------------------------------------------------------------------------------------------ */
void max541x_init (void);
void max541x_send (u8 dat);
/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* MAX541X_CONFIG */

#endif /* _MAX541X_H */
