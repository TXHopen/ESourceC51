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
 * @file      bsp_config.c
 * 
 * @brief     SDK包初始化源文件
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
#include "es_sys_package.h"


static void bsp_gpio_config (void)
{
	P0=0xff;
	P1=0xff;
	P2=0xff;
	P3=0xff;
}

void bsp_init (void)
{
	bsp_gpio_config ();
	
#ifdef MEMPOOL_CONFIG
	mempool_init ();
#endif /* MEMPOOL_CONFIG */
	
#ifdef GTIMER_CONFIG
	GTimer_Init ();
	GTimer_Start ();
#endif /* GTIMER_CONFIG */
	
#ifdef SW_SOFTTIMER_CONFIG
	SOFTTimer_Init ();
	SOFTTimer_Start ();
#endif /* SW_SOFTTIMER_CONFIG */
	
#ifdef SW_PWMGROUP_CONFIG
	PWMGroup_Init ();
	PWMGroup_Start ();
#endif /* SW_PWMGROUP_CONFIG */
}
