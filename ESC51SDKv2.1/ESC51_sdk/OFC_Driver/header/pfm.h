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
 * @file      pfm.h
 * 
 * @brief     片外驱动：pfm驱动头文件
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
#ifndef __PFM_H
#define __PFM_H


#include "user_config_prj.h"

#ifdef PFM_CONFIG

#include "es_sys_package.h"

/* ------------------------------------------------------------------------------------------------------------------ */
sbit     PFM_OUT = P2^7;




/* ------------------------------------------------------------------------------------------------------------------ */
char PFM_Init (uint frq);
char PFM_Start (void);
char PFM_Stop (void);
char PFM_SetFrq (uint frq);


/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* PFM_CONFIG */

#endif /* __PFM_H */
