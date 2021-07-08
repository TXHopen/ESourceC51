#ifndef __HW_EXT1_H
#define __HW_EXT1_H


#include "user_config_prj.h"

#ifdef EXT1_CONFIG

#include "es_sys_package.h"




typedef enum _EXT1_MODE
{
	EXT1_MODE_LEVEL = 0X00,
	EXT1_MODE_FEDGE
} EXT1_MODE;





void Ext1Init(EXT1_MODE mode, void *pfunc);
void Ext1Init_NoOpen(EXT1_MODE mode, void *pfunc);
void Ext1Open(void);
void Ext1Close(void);
void Ext1Pause(void);
void Ext1Start(void);




#endif /* EXT1_CONFIG */

#endif /* __HW_EXT1_H */