#ifndef __DHT11_H
#define __DHT11_H


#include "user_config_prj.h"

#ifdef DHT11_CONFIG

#include "es_sys_package.h"

sbit DHT11_DQ_OUT = P3^2;

void DHT11_Rst();
uint8 DHT11_Check();
uint8 DHT11_Init();
uint8 DHT11_Read_Bit(void) ;
uint8 DHT11_Read_Byte(void);
uint8 DHT11_Read_Data(uint8 *temp,uint8 *humi);


#endif /* DHT11_CONFIG */

#endif /* __DHT11_H */

