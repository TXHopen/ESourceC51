#ifndef __AD0809_H
#define __AD0809_H


#include "user_config_prj.h"

#ifdef AD0809_CONFIG

#include "es_sys_package.h"

#define  AD_DATA P2
sbit     AD_START   = P1^0;
sbit     AD_EOC     = P1^1;
sbit     AD_OUTEN   = P1^2;
sbit     AD_CLK     = P1^3;
sbit     AD_ADDCS_A = P1^4;
sbit     AD_ADDCS_B = P1^4;
sbit     AD_ADDCS_C = P1^4;

int  ad0809_read(uchar channel, uchar *ad_data);
void ad0809_clk_init(void);


#endif /* AD0809_CONFIG */

#endif /* __AD0809_H */
