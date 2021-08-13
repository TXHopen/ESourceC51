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
 * @file      ds1302.h
 * 
 * @brief     片外驱动：ds1302驱动头文件
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
#ifndef __DS1302_H
#define __DS1302_H


#include "user_config_prj.h"

#ifdef DS1302_CONFIG

#include "es_sys_package.h"


/* ------------------------------------------------------------------------------------------------------------------ */
sbit DS1302_Data = P3^4;
sbit DS1302_CLK  = P3^5;
sbit DS1302_RST  = P1^7;

/* ------------------------------------------------------------------------------------------------------------------ */
void DS1302_WriteByte(uchar dat);
void DS1302_Write(uchar addr,uchar dat);
uchar DS1302_Read(uchar addr);
void DS1302_Init(void);



/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* DS1302_CONFIG */

#endif /* __DS1302_H */
