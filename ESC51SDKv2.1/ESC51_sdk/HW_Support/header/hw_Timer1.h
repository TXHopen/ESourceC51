#ifndef __HW_TIMER1_H
#define __HW_TIMER1_H


#include "user_config_prj.h"

#ifdef TIMER1_CONFIG
//#ifndef GTIMER_CONFIG

#include "hw_config.h"




typedef enum _TIMER1_MODE
{
	TIMER1_MODE_0 = 0X00,
	TIMER1_MODE_1,
	TIMER1_MODE_2
} TIMER1_MODE;





void Timer1Init(TIMER1_MODE mode, uint us, void *callback);
void Timer1Init_NoOpen(TIMER1_MODE mode, uint us, void *callback);
void Timer1Open(void);
void Timer1Close(void);
void Timer1Pause(void);
void Timer1Start(void);


//#endif /* GTIMER_CONFIG */

#endif /* TIMER1_CONFIG */

#endif /* __HW_TIMER1_H */