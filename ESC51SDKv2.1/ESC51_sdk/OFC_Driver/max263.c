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
 * @file      max263.c
 * 
 * @brief     片外驱动：max263驱动源码
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
#include "max263.h"

#ifdef MAX263_CONFIG


/* ------------------------------------------------------------------------------------------------------------------ */
static float_t __arr_to_float (u8* arr)
{
    float_t buf = 0.0;
	int i       = 0;
	
	for (i = 5; i > 0; i--) {
	    buf *= 10;
		buf += (float_t)(arr[i]);
	}
	buf     += ((float_t)(arr[0])) * 0.1;
	
	return buf;
}

void max263_send (para_body_t* info)
{	
	float_t max263_fh = __arr_to_float (info->max263_fh_body.fh_value_arr);
	
	ad9850_wr_serial(0x00,max263_fh*100);
}


/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* MAX263_CONFIG */
