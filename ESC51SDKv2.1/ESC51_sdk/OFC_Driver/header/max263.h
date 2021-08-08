/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      max263.h
 * 
 * @brief     片外驱动：max263驱动头文件
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
#ifndef __MAX263_H
#define __MAX263_H


#include "user_config_prj.h"

#ifdef MAX263_CONFIG

#include "es_sys_package.h"

/* ------------------------------------------------------------------------------------------------------------------ */
#define SING_MODE_HPASS  1
#define SING_MODE_LPASS -1

#define MODE_M0          0
#define MODE_M1          1
#define MODE_M2          2
#define MODE_M3          3

#define MODE_M0_SET_VALUE          0
#define MODE_M1_SET_VALUE          1
#define MODE_M2_SET_VALUE          2
#define MODE_M3_SET_VALUE          3


/* ------------------------------------------------------------------------------------------------------------------ */
typedef struct
{
	uchar   mode[2];
	uchar   mode_current;
	uchar   mode_location;
	
} max263_mode_body_t;

typedef struct
{
	u8      fh_value_arr[6];
	u8      fh_bit;
	
	u8      x_start;
	u8      x_ignore;
	u8      x_end;
	
	u8      y_current;
	u8      x_current;
	
} max263_fh_body_t;

typedef struct
{
	u8      ga_value;
	u8      ga_bit;
	
	u8      x_start;
	u8      x_end;
	
	u8      y_current;
	u8      x_current;

} max541x_gain_body_t;

typedef struct
{
	max263_mode_body_t    max263_mode_body;
	max263_fh_body_t      max263_fh_body;
	max541x_gain_body_t   max541x_ga_body;
	
	u8                    now_body;
	
} para_body_t;







typedef struct 
{
    u8    max263_mode;
	u8    max263_f;
	u8    max263_q;
} max263_control_word_t;


/* ------------------------------------------------------------------------------------------------------------------ */
void max263_send (para_body_t* info);


/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* MAX263_CONFIG */

#endif /* __MAX263_H */
