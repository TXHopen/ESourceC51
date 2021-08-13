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
 * @file      lcd12864.h
 * 
 * @brief     片外驱动：lcd12864驱动头文件
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
#ifndef __LCD12864_H
#define __LCD12864_H


#include "user_config_prj.h"

#ifdef LCD12864_CONFIG

#include "es_sys_package.h"


/* ------------------------------------------------------------------------------------------------------------------ */
#define LCD12864_Data   P1
sbit    LCD12864_EN   = P3^0;
sbit    LCD12864_RS   = P3^2;
sbit    LCD12864_RW   = P3^1;
sbit    LCD12864_PSB  = P3^3;




/* ------------------------------------------------------------------------------------------------------------------ */
bit LCD12864_Busy();
void LCD12864_Write_Data(uchar dat);
void LCD12864_Write_Command(uchar com);
void LCD12864_Init();
void LCD12864_Display_Char(uchar x,uchar y,uchar dat);
void LCD12864_Display_Str(uchar x,uchar y,uchar *dat);


/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* LCD12864_CONFIG */

#endif /* __LCD12864_H */