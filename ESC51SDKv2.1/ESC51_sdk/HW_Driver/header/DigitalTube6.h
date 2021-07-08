#ifndef __DIGITALTUBE6_H
#define __DIGITALTUBE6_H


#include "user_config_prj.h"

#ifdef DIGITALTUBE6_CONFIG

#include "es_sys_package.h"


#define SMG_WEI    P0
#define SMG_DUAN   P1



/*------------------------------------------------
                 数码管显示函数声明
------------------------------------------------*/
void SMG_Show(uchar x,uchar dat);



#endif /* DIGITALTUBE6_CONFIG */
#endif /* __DIGITALTUBE6_H */