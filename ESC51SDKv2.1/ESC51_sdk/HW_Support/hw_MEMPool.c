/***********************************************************************************************************************
 *                                                      ESourceOpen
 *                                           -----------------------------------
 *                                           explore and open  embedded platform
 * 
 * Contact information:
 * e-mail: 1786409879@qq.com / txh17778443952@169.com
 *                                                                                                              TXHopen
***********************************************************************************************************************/
/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      hw_MEMPool.c
 * 
 * @brief     硬件支持组件：内存池源码
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
#include "hw_MEMPool.h"

#ifdef MEMPOOL_CONFIG

/* ------------------------------------------------------------------------------------------------------------------ */
xdata char mempool[MEMPOOL_SIZE] = {0};

void mempool_init (void)
{
	
	init_mempool (mempool, MEMPOOL_SIZE);
	
}


/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* MEMPOOL_CONFIG */
