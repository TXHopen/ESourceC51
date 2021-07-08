#ifndef __DS1302_H
#define __DS1302_H


#include "user_config_prj.h"

#ifdef DS1302_CONFIG

#include "es_sys_package.h"


/*------------------------------------------------
                  DS1302位定义
------------------------------------------------*/
sbit DS1302_Data = P3^4;
sbit DS1302_CLK  = P3^5;
sbit DS1302_RST  = P1^7;

/*------------------------------------------------
                 DS1302函数声明
------------------------------------------------*/
void DS1302_WriteByte(uchar dat);
void DS1302_Write(uchar addr,uchar dat);
uchar DS1302_Read(uchar addr);
void DS1302_Init(void);

#endif /* DS1302_CONFIG */

#endif /* __DS1302_H */
