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
 * @file      ad0809.h
 * 
 * @brief     片外驱动：ad0809驱动头文件，包含引脚定义与API
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
#ifndef __AD0809_H
#define __AD0809_H


#include "user_config_prj.h"

#ifdef AD0809_CONFIG

#include "es_sys_package.h"

/* ------------------------------------------------------------------------------------------------------------------ */

#define  AD_DATA P2
sbit     AD_START   = P1^0;
sbit     AD_EOC     = P1^1;
sbit     AD_OUTEN   = P1^2;
sbit     AD_CLK     = P1^3;
sbit     AD_ADDCS_A = P1^4;
sbit     AD_ADDCS_B = P1^4;
sbit     AD_ADDCS_C = P1^4;


/* ------------------------------------------------------------------------------------------------------------------ */
int  ad0809_read(uchar channel, uchar *ad_data);
void ad0809_clk_init(void);

/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* AD0809_CONFIG */

#endif /* __AD0809_H */
