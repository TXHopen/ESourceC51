#ifndef __IIC_H
#define __IIC_H


#include "user_config_prj.h"

#ifdef IIC_CONFIG

#include "es_sys_package.h"


sbit IIC_SCL=P2^1;
sbit IIC_SDA=P2^0;

void I2cStart();
void I2cStop();
unsigned char I2cSendByte(unsigned char dat);
unsigned char I2cReadByte();


#endif /* IIC_CONFIG */

#endif /* __IIC_H */
