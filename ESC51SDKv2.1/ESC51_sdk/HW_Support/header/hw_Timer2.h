#ifndef __HW_TIMER2_H
#define __HW_TIMER2_H


#include "user_config_prj.h"

#ifdef TIMER2_CONFIG

#include "es_sys_package.h"





typedef enum _TIMER2_MODE
{
	TIMER2_MODE_CAPTURE = 0,
	TIMER2_MODE_TIMING
} TIMER2_MODE;




void Timer2Init(TIMER2_MODE mode, uint us, void *callback);
void Timer2Init_NoOpen(TIMER2_MODE mode, uint us, void *callback);
void Timer2Open(void);
void Timer2Close(void);
void Timer2Pause(void);
void Timer2Start(void);



#endif /* TIMER2_CONFIG */

#endif /* __HW_TIMER2_H */