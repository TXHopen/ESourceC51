#ifndef __PWM_H
#define __PWM_H


#include "user_config_prj.h"

#ifdef PWM_CONFIG

#include "es_sys_package.h"


sbit     PWM_OUT = P3^7;





char PWM_Init (uchar duty);
char PWM_Start (void);
char PWM_Stop (void);
char PWM_SetDUTY (uchar duty);


#endif /* PWM_CONFIG */

#endif /* __PWM_H */
