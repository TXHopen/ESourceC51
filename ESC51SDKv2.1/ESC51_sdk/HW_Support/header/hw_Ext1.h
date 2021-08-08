/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      hw_Ext1.h
 * 
 * @brief     硬件支持组件：外部中断1组件，包含外部中断1的API
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
#ifndef __HW_EXT1_H
#define __HW_EXT1_H


#include "user_config_prj.h"

#ifdef EXT1_CONFIG

#include "es_sys_package.h"

/* ------------------------------------------------------------------------------------------------------------------ */
/* API部分参数类型 */

typedef enum _EXT1_MODE
{
	EXT1_MODE_LEVEL = 0X00,
	EXT1_MODE_FEDGE
} EXT1_MODE;


/* ------------------------------------------------------------------------------------------------------------------ */
/* 组件API */

void Ext1Init(EXT1_MODE mode, void *pfunc);
void Ext1Init_NoOpen(EXT1_MODE mode, void *pfunc);
void Ext1Open(void);
void Ext1Close(void);
void Ext1Pause(void);
void Ext1Start(void);



/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* EXT1_CONFIG */

#endif /* __HW_EXT1_H */