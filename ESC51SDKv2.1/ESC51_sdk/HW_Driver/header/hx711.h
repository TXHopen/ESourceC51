#ifndef __HX711_H
#define __HX711_H


#include "user_config_prj.h"

#ifdef HX711_CONFIG

#include "es_sys_package.h"


sbit HX711_SK = P2^0;
sbit HX711_DO = P2^1;


unsigned long HX711_Read(void);

#endif /* HX711_CONFIG */
#endif /* __HX711_H */