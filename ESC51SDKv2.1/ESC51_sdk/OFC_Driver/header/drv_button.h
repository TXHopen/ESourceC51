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
 * @file      drv_button.h
 * 
 * @brief     片外驱动：独立按键驱动头文件
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
#ifndef __DRV_BUTTON_H__
#define __DRV_BUTTON_H__


#include "user_config_prj.h"

#ifdef ALONEBUTTON_CONFIG

#include "es_sys_package.h"




/* ------------------------------------------------------------------------------------------------------------------ */
sbit		BUTTON_PIN				=P3^1;


#define		BUTTON_PIN_BIT			1							

#define		BUTTON_PxM0				IO_P3M0
#define		BUTTON_PxM1				IO_P3M1


/* ------------------------------------------------------------------------------------------------------------------ */
enum
{
	BUTOTN_UP = 0,		//按键未按下
	BUTOTN_PRESS_DOWN	//按键按下
};


/* ------------------------------------------------------------------------------------------------------------------ */
void drv_button_init( void );
uint8_t drv_button_check( void );

/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* ALONEBUTTON_CONFIG */

#endif /* __DRV_BUTTON_H__ */

