#ifndef __HCSR04_H
#define __HCSR04_H


#include "user_config_prj.h"

#ifdef HCSR04_CONFIG

#include "es_sys_package.h"


sbit HCSR04_TRIG  =  P2^6;
sbit HCSR04_ECHO  =  P2^7;


uint HCSR04_NoneRead (void);

#ifdef TIMER0_CONFIG

uint HCSR04_IntConfig (void);
uint HCSR04_InitReadcm (void);

#endif /* TIMER0_CONFIG */

#endif /* HCSR04_CONFIG */

#endif /* __HCSR04_H */
