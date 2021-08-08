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
