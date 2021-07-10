#ifndef __HW_TIMER0_H
#define __HW_TIMER0_H


#include "user_config_prj.h"

#ifdef TIMER0_CONFIG

#include "es_sys_package.h"



typedef enum _TIMER0_MODE
{
	TIMER0_MODE_0 = 0x00,
	TIMER0_MODE_1,
	TIMER0_MODE_2,
	TIMER0_MODE_3
} TIMER0_MODE;





void Timer0Init(TIMER0_MODE mode, uint16_t us, void *callback);

void Timer0Settime(uint16_t us);

void Timer0Init_NoOpen(TIMER0_MODE mode, uint16_t us, void *callback);
void Timer0Open(void);
void Timer0Close(void);





#endif /* TIMER0_CONFIG */

#endif /* __HW_TIMER0_H */