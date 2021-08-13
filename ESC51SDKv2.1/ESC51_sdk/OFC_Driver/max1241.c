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
 * @file      max1241.c
 * 
 * @brief     片外驱动：max1241驱动源码
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
#include "max1241.h"

#ifdef MAX1241_CONFIG
/* ------------------------------------------------------------------------------------------------------------------ */
uint AD_MAX1241(void)
{
	unsigned long int voltage_temp;
	uint  ucop   = 12; 
	CS_OUT   = 1;
	SCLK_OUT = 0;
	voltage_temp = 0;
	CS_OUT   = 0;
	while(D_OUT == 0);
	SCLK_OUT=1;
	_nop_();
	SCLK_OUT=0;
	while(ucop--)
	{
		voltage_temp <<= 1;
		_nop_();
		SCLK_OUT = 1;
		_nop_();
		if(D_OUT == 1)
			voltage_temp += 1;
		SCLK_OUT = 0;
	}
	CS_OUT   = 1;
	SCLK_OUT = 0;
	return voltage_temp; 
}

/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* MAX1241_CONFIG */
