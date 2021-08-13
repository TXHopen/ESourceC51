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
 * @file      drv_button.c
 * 
 * @brief     片外驱动：独立按键驱动源码
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
#include "drv_button.h"


#ifdef ALONEBUTTON_CONFIG


/* ------------------------------------------------------------------------------------------------------------------ */
static void drv_delay_1ms( )
{
	uint16_t Ms = 1;
	uint32_t j = 80;
	
	while( Ms-- )
	{
		while( j-- );
	}
}


static void drv_delay_ms( uint16_t Ms )
{
	while( Ms-- )
	{
		drv_delay_1ms( );
	}
}



/* ------------------------------------------------------------------------------------------------------------------ */
void drv_button_init( void )
{
	//引脚配置 部分51单片机不需要
	//BUTTON引脚配置为输入
	BUTTON_PxM0 = IO_IN_PUT_ONLY_M0 << BUTTON_PIN_BIT;
	BUTTON_PxM1 = IO_IN_PUT_ONLY_M1 << BUTTON_PIN_BIT;
	
	BUTTON_PIN = 1;		//默认状态置高
}

/**
  * @brief :按键查询
  * @param :无
  * @note  :无
  * @retval:
  *			0:按键没有按下
  *			1:检测到按键动作
  */
uint8_t drv_button_check( void )
{
	if( 1 != BUTTON_PIN )		//检测按键输入状态
	{
		drv_delay_ms( 45 );		//消抖
		if( 1 != BUTTON_PIN )
		{
			while (1 != BUTTON_PIN);
			return 1;			//按键按下，返回按键状态
		}
	}
	
	return 0;
}


/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* ALONEBUTTON_CONFIG */
