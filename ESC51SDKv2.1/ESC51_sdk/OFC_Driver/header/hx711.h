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
 * @file      hx711.h
 * 
 * @brief     片外驱动：hx711模块驱动头文件
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
#ifndef __HX711_H
#define __HX711_H


#include "user_config_prj.h"

#ifdef HX711_CONFIG

#include "es_sys_package.h"

/* ------------------------------------------------------------------------------------------------------------------ */
sbit HX711_SK = P2^0;
sbit HX711_DO = P2^1;

/* ------------------------------------------------------------------------------------------------------------------ */
unsigned long HX711_Read(void);

/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* HX711_CONFIG */
#endif /* __HX711_H */