/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      hw_vartype.h
 * 
 * @brief     硬件支持组件：基础类型服务
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
#ifndef __HW_VARTYPE_H
#define __HW_VARTYPE_H

#include "reg52.h"
/*
#define uint          unsigned int
#define uchar         unsigned char
#define ulong         unsigned long
#define	u8	          unsigned char
#define u16	          unsigned int
#define u32           unsigned long int
#define float_t                float
*/

typedef unsigned char     uchar;
typedef unsigned int      uint;
typedef unsigned long     ulong;
typedef unsigned long int uint32;
typedef          float    ufloat;

typedef          char     int8;
typedef          int      int16;
typedef          long int int32;
typedef          float    float32;

typedef unsigned char     u8;
typedef unsigned int      u16;
typedef unsigned long int u32;

typedef          uchar    uint8;
typedef          uint     uint16;
typedef          float32  float_t;

typedef   signed        char    int8_t;
typedef   signed short  int     int16_t;
typedef   signed        int     int32_t;
//typedef   signed       		int64_t;

/* exact-width unsigned integer types */
typedef unsigned        char    uint8_t;
typedef unsigned short  int     uint16_t;
typedef unsigned        int     uint32_t;
//typedef unsigned              uint64_t;



/* ------------------------------------------------------------------------------------------------------------------ */

#endif /* __HW_VARTYPE_H */
