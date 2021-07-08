#ifndef __AD9850_H
#define __AD9850_H


#include "user_config_prj.h"

#ifdef AD9850_CONFIG

#include "es_sys_package.h"

sbit    AD9850_DATA       = P3^1;
sbit    AD9850_UD         = P3^2;
sbit    AD9850_CLK        = P3^3;
sbit    AD9850_REST       = P3^0;

void ad9850_reset_serial();
void ad9850_wr_serial(unsigned char w0,double frequence);


#endif /* AD9850_CONFIG */

#endif /* __AD9850_H */

