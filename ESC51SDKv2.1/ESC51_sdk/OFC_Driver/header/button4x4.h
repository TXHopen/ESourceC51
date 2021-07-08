#ifndef __BUTTON4X4_H
#define __BUTTON4X4_H


#include "user_config_prj.h"

#ifdef KEY4X4_CONFIG

#include "es_sys_package.h"

#define GPIO_KEY            P0

u8 KeyDown(void);


#endif /* KEY4X4_CONFIG */

#endif /* __BUTTON4X4_H */
