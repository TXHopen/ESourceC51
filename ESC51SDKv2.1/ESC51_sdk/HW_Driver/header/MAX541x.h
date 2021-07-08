#ifndef  _MAX541X_H
#define  _MAX541X_H


#include "user_config_prj.h"

#ifdef MAX541X_CONFIG

#include "es_sys_package.h"

sbit    MAX541X_CLK       = P2^3;
sbit    MAX541X_DIN       = P2^4;
sbit    MAX541X_CS	      = P2^6;

void max541x_init (void);
void max541x_send (u8 dat);

#endif /* MAX541X_CONFIG */

#endif /* _MAX541X_H */
