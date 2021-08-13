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
 * @file      dht11.h
 * 
 * @brief     片外驱动：dth11驱动头文件
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
#ifndef __DHT11_H
#define __DHT11_H


#include "user_config_prj.h"

#ifdef DHT11_CONFIG

#include "es_sys_package.h"
/* ------------------------------------------------------------------------------------------------------------------ */


sbit DHT11_DQ_OUT = P3^2;


/* ------------------------------------------------------------------------------------------------------------------ */
void DHT11_Rst();
uint8 DHT11_Check();
uint8 DHT11_Init();
uint8 DHT11_Read_Bit(void) ;
uint8 DHT11_Read_Byte(void);
uint8 DHT11_Read_Data(uint8 *temp,uint8 *humi);

/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* DHT11_CONFIG */

#endif /* __DHT11_H */

