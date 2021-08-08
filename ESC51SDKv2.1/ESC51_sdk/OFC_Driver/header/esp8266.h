/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      esp8266.h
 * 
 * @brief     片外驱动：esp8266模块驱动头文件
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
#ifndef __ESP8266_H
#define __ESP8266_H


#include "user_config_prj.h"

#ifdef ESP8266_CONFIG

#include "es_sys_package.h"

/* ------------------------------------------------------------------------------------------------------------------ */
sbit ESP8266_RST_Pin=P2^4;
sbit ESP8266_CH_PD_Pin=P2^3; 

/* ------------------------------------------------------------------------------------------------------------------ */
void ESP8266_SendCmd(u8 *pbuf);
void ESP8266_SendData(u8 *pbuf);
void ESP8266_ModeInit(void);

/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* ESP8266_CONFIG */

#endif /* __ESP8266_H */
