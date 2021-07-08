#ifndef __ESP8266_H
#define __ESP8266_H


#include "user_config_prj.h"

#ifdef ESP8266_CONFIG

#include "es_sys_package.h"


sbit ESP8266_RST_Pin=P2^4;
sbit ESP8266_CH_PD_Pin=P2^3; 

void ESP8266_SendCmd(u8 *pbuf);
void ESP8266_SendData(u8 *pbuf);
void ESP8266_ModeInit(void);

#endif /* ESP8266_CONFIG */

#endif /* __ESP8266_H */
