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
 * @file      user_config_prj.h
 * 
 * @brief     sdk开发包引入模块选定（用户自行选定所需模块）
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
#ifndef __USER_CONFIG_PRJ_H
#define __USER_CONFIG_PRJ_H


/* ------------------------------------------------------------ */
//#define IOCTRL_CONFIG
//#define TIMER0_CONFIG
//#define TIMER1_CONFIG
//#define TIMER2_CONFIG
//#define UART_CONFIG
//#define EXT0_CONFIG
//#define EXT1_CONFIG
//#define MEMPOOL_CONFIG
//#define GTIMER_CONFIG







/* ------------------------------------------------------------ */
//#define SW_GDELAY_CONFIG
//#define SW_SOFTTIMER_CONFIG
//#define SW_GCAPTURE_CONFIG
//#define SW_PWMGROUP_CONFIG
//#define SW_BUTTONGP_CONFIG




/* ------------------------------------------------------------ */
//#define LCD1602_CONFIG
//#define MAX541X_CONFIG
//#define MAX263_CONFIG
//#define KEY4X4_CONFIG
//#define AD0809_CONFIG
//#define AD9850_CONFIG
//#define PWM_CONFIG
//#define PFM_CONFIG
//#define DHT11_CONFIG
//#define DS1302_CONFIG
//#define DS18B20_CONFIG
//#define ESP8266_CONFIG
//#define IIC_CONFIG
//#define AT24C02_CONFIG
//#define DIGITALTUBE6_CONFIG
//#define MAX1241_CONFIG
//#define AD5320_CONFIG
//#define LCD12864_CONFIG
//#define HX711_CONFIG
//#define HCSR04_CONFIG
//#define DRV_SPI_CONFIG
//#define DRV_CC1101_CONFIG
//#define ALONEBUTTON_CONFIG









/* ------------------------------------------------------------ */
#ifdef   PFM_CONFIG
#ifndef  TIMER0_CONFIG
#define  TIMER0_CONFIG
#endif   /* TIMER0_CONFIG */
#endif   /* PFM_CONFIG */

#ifdef   SW_BUTTONGP_CONFIG
#ifndef  IOCTRL_CONFIG
#define  IOCTRL_CONFIG
#endif   /* IOCTRL_CONFIG */
#endif   /* SW_BUTTONGP_CONFIG */



#ifdef   SW_SOFTTIMER_CONFIG
#ifndef  GTIMER_CONFIG
#define  GTIMER_CONFIG
#endif   /* GTIMER_CONFIG */
#endif   /* SW_SOFTTIMER_CONFIG */


#ifdef   PWM_CONFIG
#ifndef  GTIMER_CONFIG
#define  GTIMER_CONFIG
#endif   /* GTIMER_CONFIG */
#endif   /* PWM_CONFIG */


#ifdef   SW_PWMGROUP_CONFIG
#ifndef  GTIMER_CONFIG
#define  GTIMER_CONFIG
#endif   /* GTIMER_CONFIG */
#ifndef  IOCTRL_CONFIG
#define  IOCTRL_CONFIG
#endif   /* IOCTRL_CONFIG */
#endif   /* SW_PWMGROUP_CONFIG */


#ifdef   GTIMER_CONFIG
#ifdef   TIMER2_CONFIG
#warning TIMER2 is Conflict
#else
#define  TIMER2_CONFIG
#endif   /* TIMER2_CONFIG */
#endif   /* GTIMER_CONFIG */


#ifdef   UART_CONFIG
#ifdef   TIMER1_CONFIG
#error   TIMER1 is Conflict
#endif   /* TIMER1_CONFIG */
#endif   /* UART_CONFIG */



/* ------------------------------------------------------------ */

#endif /* __USER_CONFIG_PRJ_H */
