#ifndef _MAX1241_H
#define _MAX1241_H


#include "user_config_prj.h"

#ifdef MAX1241_CONFIG

#include "es_sys_package.h"


sbit D_OUT    = P2^2;
sbit SCLK_OUT = P2^0;
sbit CS_OUT   = P2^1;



uint AD_MAX1241(void);


#endif /* MAX1241_CONFIG */
#endif /* _MAX1241_H */