/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      MAX541x.c
 * 
 * @brief     片外驱动：max541x驱动源码
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
#include "MAX541x.h"

#ifdef MAX541X_CONFIG


/* ------------------------------------------------------------------------------------------------------------------ */
void max541x_init (void)
{
	MAX541X_DIN = 0;
	MAX541X_CLK = 1;
	MAX541X_CS  = 1;
}

void __delay_nop (void)
{
	unsigned char i = 0;
	for (i = 0; i < 255; i++);
}

void max541x_send (u8 dat)
{
	u8 i= 8;
	MAX541X_CLK = 0;
	__delay_nop();
	MAX541X_CLK	= 1;
	__delay_nop();
	MAX541X_CLK = 0;
	
	__delay_nop();
	MAX541X_CS 	= 0;
	MAX541X_DIN	= 0;
	__delay_nop();
	MAX541X_CLK	= 1;
	__delay_nop();

	while (i--)
	{
		if (dat & 0x80){
		  MAX541X_DIN = 1;
		}else{
		  MAX541X_DIN = 0;
		}
		MAX541X_CLK 	= 0;
		__delay_nop();
		MAX541X_CLK		= 1;
		__delay_nop();
		//MAX541X_CLK		=0;
		dat   <<= 1;
	}
	MAX541X_CLK		= 0;
	__delay_nop();
	MAX541X_CS	  = 1;
	__delay_nop();
	MAX541X_CLK 	=1;
}


/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* MAX541X_CONFIG */
