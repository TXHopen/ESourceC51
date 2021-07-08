#ifndef __AD5320_H
#define __AD5320_H


#include "user_config_prj.h"

#ifdef AD5320_CONFIG

#include "es_sys_package.h"


sbit SYNC_IN = P2^3;
sbit SCLK_IN = P2^4;
sbit D_IN    = P2^5;


void DA_AD5320(uint dat);

#endif /* AD5320_CONFIG */
#endif /* __AD5320_H */
