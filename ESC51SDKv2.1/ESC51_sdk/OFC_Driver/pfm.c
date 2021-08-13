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
 * @file      pfm.c
 * 
 * @brief     片外驱动：pfm驱动源码
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
#include "pfm.h"

#ifdef PFM_CONFIG


/* ------------------------------------------------------------------------------------------------------------------ */
static int pfm_int_function (void *arg) 
{
	PFM_OUT = ~PFM_OUT;
	return 0;
}


char PFM_Init (uint frq)
{
	uint16_t us10 = 0;
	us10 = frq   / 10;
	us10 = 50000 / us10;
	Timer0Init(TIMER0_MODE_1, us10, pfm_int_function);
	return 0;
}




char PFM_Start (void)
{
	Timer0Open();
	
	return 0;
}

char PFM_Stop (void)
{
	Timer0Close();
	
	return 0;
}


char PFM_SetFrq (uint frq)
{
	uint16_t us10 = 0;
	us10 = frq   / 10;
	us10 = 50000 / us10;
	
	Timer0Settime(us10);
	
	return 0;
}
/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* PFM_CONFIG */
