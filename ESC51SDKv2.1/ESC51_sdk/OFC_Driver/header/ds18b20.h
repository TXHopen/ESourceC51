#ifndef __DS18B20_H
#define __DS18B20_H


#include "user_config_prj.h"

#ifdef DS18B20_CONFIG

#include "es_sys_package.h"



//--定义使用的IO口--//
sbit DSPORT=P3^7;

//--声明全局函数--//
void Delay1ms(uint );
uchar Ds18b20Init();
void Ds18b20WriteByte(uchar com);
uchar Ds18b20ReadByte();
void  Ds18b20ChangTemp();
void  Ds18b20ReadTempCom();
int Ds18b20ReadTemp();


#endif /* DS18B20_CONFIG */

#endif /* __DS18B20_H */
