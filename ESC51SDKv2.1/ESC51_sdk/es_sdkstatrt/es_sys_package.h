/***********************************************************************************************************************
 *                                                      ESourceOpen
 *                                           -----------------------------------
 *                                           explore and open  embedded platform
 * 
 * Contact information:
 * e-mail: 1786409879@qq.com / txh17778443952@169.com
 *                                                                                                              
 *                                                                                                              TXHopen
 *                                                                                                         encode:UTF-8
***********************************************************************************************************************/
/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      es_sys_package.h
 * 
 * @brief     sdk系统包文件依赖关系
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
#ifndef __ES_SYS_PACKAGE_H
#define __ES_SYS_PACKAGE_H


#include <stdio.h>
#include <intrins.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include <reg52.h>

#include "hw_vartype.h"
#include "hw_critical.h"
#include "hw_ioctrl.h"
#include "user_config_prj.h"

//#include "bsp_config.h"






#ifdef IOCTRL_CONFIG

#endif /* IOCTRL_CONFIG */

#ifdef TIMER0_CONFIG
//#ifndef GTIMER_CONFIG
#include "hw_Timer0.h"
//#endif /* GTIMER_CONFIG */
#endif /* TIMER0_CONFIG */

#ifdef TIMER1_CONFIG
//#ifndef GTIMER_CONFIG
#include "hw_Timer1.h"
//#endif /* GTIMER_CONFIG */
#endif /* TIMER1_CONFIG */

#ifdef TIMER2_CONFIG
#include "hw_Timer2.h"
#endif /* TIMER2_CONFIG */

#ifdef UART_CONFIG
#include "hw_UART.h"
#endif /* UART_CONFIG */

#ifdef EXT0_CONFIG
#include "hw_EXT0.h"
#endif /* EXT0_CONFIG */

#ifdef EXT1_CONFIG
#include "hw_EXT1.h"
#endif /* EXT1_CONFIG */

#ifdef MEMPOOL_CONFIG
#include "hw_MEMPool.h"
#endif /* MEMPOOL_CONFIG */

#ifdef GTIMER_CONFIG
#include "hw_Gtimer.h"
#endif /* GTIMER_CONFIG */










#ifdef SW_GDELAY_CONFIG
#include "sw_Gdelay.h"
#endif /* SW_GDELAY_CONFIG */

#ifdef SW_SOFTTIMER_CONFIG
#include "sw_SoftTimer.h"
#endif /* SW_SOFTTIMER_CONFIG */

#ifdef SW_GCAPTURE_CONFIG
#include "sw_GCapture.h"
#endif /* SW_GCAPTURE_CONFIG */

#ifdef SW_PWMGROUP_CONFIG
#include "sw_PWMGroup.h"
#endif /* SW_PWMGROUP_CONFIG */

#ifdef SW_BUTTONGP_CONFIG
#include "sw_ButtonGP.h"
#endif /* SW_BUTTONGP_CONFIG */











#ifdef LCD1602_CONFIG
#include "LCD1602.h"
#endif /* LCD1602_CONFIG */

#ifdef MAX541X_CONFIG
#include "MAX541x.h"
#endif /* MAX541X_CONFIG */

#ifdef MAX263_CONFIG
#include "max263.h"
#endif /* MAX263_CONFIG */

#ifdef KEY4X4_CONFIG
#include "button4x4.h"
#endif /* KEY4X4_CONFIG */

#ifdef AD0809_CONFIG
#include "ad0809.h"
#endif /* AD0809_CONFIG */

#ifdef AD9850_CONFIG
#include "ad9850.h"
#endif /* AD9850_CONFIG */

#ifdef PWM_CONFIG
#include "pwm.h"
#endif /* PWM_CONFIG */

#ifdef PFM_CONFIG
#include "pfm.h"
#endif /* PFM_CONFIG */

#ifdef DHT11_CONFIG
#include "dht11.h"
#endif /* DHT11_CONFIG */

#ifdef DS1302_CONFIG
#include "ds1302.h"
#endif /* DS1302_CONFIG */

#ifdef DS18B20_CONFIG
#include "ds18b20.h"
#endif /* DS18B20_CONFIG */

#ifdef ESP8266_CONFIG
#include "esp8266.h"
#endif /* ESP8266_CONFIG */

#ifdef IIC_CONFIG
#include "iic.h"
#endif /* IIC_CONFIG */

#ifdef AT24C02_CONFIG
#include "at24c02.h"
#endif /* AT24C02_CONFIG */

#ifdef DIGITALTUBE6_CONFIG
#include "DigitalTube6.h"
#endif /* DIGITALTUBE6_CONFIG */

#ifdef MAX1241_CONFIG
#include "max1241.h"
#endif /* MAX1241_CONFIG */

#ifdef AD5320_CONFIG
#include "ad5320.h"
#endif /* AD5320_CONFIG */

#ifdef LCD12864_CONFIG
#include "lcd12864.h"
#endif /* LCD12864_CONFIG */

#ifdef HX711_CONFIG
#include "hx711.h"
#endif /* HX711_CONFIG */

#ifdef HCSR04_CONFIG
#include "hcsr04.h"
#endif /* HCSR04_CONFIG */

#ifdef DRV_SPI_CONFIG
#include "drv_spi.h"
#endif /* DRV_SPI_CONFIG */

#ifdef DRV_CC1101_CONFIG
#include "drv_cc1101.h"
#endif /* DRV_CC1101_CONFIG */

#ifdef ALONEBUTTON_CONFIG
#include "drv_button.h"
#endif /* ALONEBUTTON_CONFIG */






/* ------------------------------------------------------------ */

#endif /* __ES_SYS_PACKAGE_H */
