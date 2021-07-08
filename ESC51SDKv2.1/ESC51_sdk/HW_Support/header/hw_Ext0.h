#ifndef __HW_EXT0_H
#define __HW_EXT0_H


#include "user_config_prj.h"

#ifdef EXT0_CONFIG

#include "es_sys_package.h"



typedef enum _EXT0_MODE
{
	EXT0_MODE_LEVEL = 0X00,
	EXT0_MODE_FEDGE
} EXT0_MODE;


void Ext0Init(EXT0_MODE mode, void *pfunc);
void Ext0Init_NoOpen(EXT0_MODE mode, void *pfunc);
void Ext0Open(void);
void Ext0Close(void);
void Ext0Pause(void);
void Ext0Start(void);



#endif /* EXT0_CONFIG */

#endif /* __HW_EXT0_H */