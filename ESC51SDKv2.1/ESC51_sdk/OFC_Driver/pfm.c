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
