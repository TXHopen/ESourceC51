#ifndef __LCD12864_H
#define __LCD12864_H


#include "user_config_prj.h"

#ifdef LCD12864_CONFIG

#include "es_sys_package.h"


/*------------------------------------------------
                    LCDŒª∂®“Â
------------------------------------------------*/
#define LCD12864_Data   P1
sbit    LCD12864_EN   = P3^0;
sbit    LCD12864_RS   = P3^2;
sbit    LCD12864_RW   = P3^1;
sbit    LCD12864_PSB  = P3^3;





bit LCD12864_Busy();
void LCD12864_Write_Data(uchar dat);
void LCD12864_Write_Command(uchar com);
void LCD12864_Init();
void LCD12864_Display_Char(uchar x,uchar y,uchar dat);
void LCD12864_Display_Str(uchar x,uchar y,uchar *dat);

#endif /* LCD12864_CONFIG */
#endif /* __LCD12864_H */