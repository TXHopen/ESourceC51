/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      DigitalTube6.h
 * 
 * @brief     片外驱动：6位数码管驱动头文件
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
#ifndef __DIGITALTUBE6_H
#define __DIGITALTUBE6_H


#include "user_config_prj.h"

#ifdef DIGITALTUBE6_CONFIG

#include "es_sys_package.h"
/* ------------------------------------------------------------------------------------------------------------------ */

#define SMG_WEI    P0
#define SMG_DUAN   P1


/* ------------------------------------------------------------------------------------------------------------------ */
void SMG_Show(uchar x,uchar dat);


/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* DIGITALTUBE6_CONFIG */
#endif /* __DIGITALTUBE6_H */