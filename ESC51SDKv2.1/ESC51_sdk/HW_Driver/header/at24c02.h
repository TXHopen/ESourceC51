#ifndef __AT24C02_H
#define __AT24C02_H


#include "user_config_prj.h"

#ifdef AT24C02_CONFIG

#include "es_sys_package.h"



void At24c02Write(unsigned char addr,unsigned char dat);
unsigned char At24c02Read(unsigned char addr);


#endif /* AT24C02_CONFIG */

#endif /* __AT24C02_H */
