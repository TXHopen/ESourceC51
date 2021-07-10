#ifndef __PFM_H
#define __PFM_H


#include "user_config_prj.h"

#ifdef PFM_CONFIG

#include "es_sys_package.h"


sbit     PFM_OUT = P2^7;





char PFM_Init (uint frq);
char PFM_Start (void);
char PFM_Stop (void);
char PFM_SetFrq (uint frq);



#endif /* PFM_CONFIG */

#endif /* __PFM_H */
