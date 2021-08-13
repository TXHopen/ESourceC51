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
 * @file      hw_Ext0.h
 * 
 * @brief     硬件支持组件：外部中断0组件，包含外部中断API
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
#ifndef __HW_EXT0_H
#define __HW_EXT0_H


#include "user_config_prj.h"

#ifdef EXT0_CONFIG

#include "es_sys_package.h"

/* ------------------------------------------------------------------------------------------------------------------ */
/* API部分参数类型 */

typedef enum _EXT0_MODE
{
	EXT0_MODE_LEVEL = 0X00,
	EXT0_MODE_FEDGE
} EXT0_MODE;

/* ------------------------------------------------------------------------------------------------------------------ */
/* 组件API */

void Ext0Init(EXT0_MODE mode, void *pfunc);
void Ext0Init_NoOpen(EXT0_MODE mode, void *pfunc);
void Ext0Open(void);
void Ext0Close(void);
void Ext0Pause(void);
void Ext0Start(void);


/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* EXT0_CONFIG */

#endif /* __HW_EXT0_H */