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
 * @file      hx711.c
 * 
 * @brief     片外驱动：hx711驱动源码
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
#include "hx711.h"


#ifdef HX711_CONFIG

/* ------------------------------------------------------------------------------------------------------------------ */
unsigned long HX711_Read(void)
{   
	ulong Count;   
	uchar i; 
	HX711_DO = 1;             
	HX711_SK = 0;   
	Count    = 0;   
	while(HX711_DO);   
	for (i=0;i<24;i++)
	{     
		HX711_SK = 1;     
		Count = Count<<1;    
		HX711_SK = 0;    
		if(HX711_DO) {
			Count++;
		}
	}   
	HX711_SK = 1;   
	Count    = Count^0x800000;   
	HX711_SK = 0; 
	
	return Count;
} 


/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* HX711_CONFIG */
