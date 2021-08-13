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
 * @file      es_main.c
 * 
 * @brief     ESource_C51开发包入口文件
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
#include "bsp_config.h"

extern void es_main(void);

void main()
{
	bsp_init ();
	
	es_main();
}


