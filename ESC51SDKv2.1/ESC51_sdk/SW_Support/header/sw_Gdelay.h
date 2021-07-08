#ifndef __SW_GDELAY_H
#define __SW_GDELAY_H


#include "user_config_prj.h"

#ifdef SW_GDELAY_CONFIG

#include "es_sys_package.h"


void es_delay_ms (uint ms);
void es_delay_10ms (uint ms10);

void es_delay_ns (uint ns);
void es_delay_10ns (uint ns10);


#endif /* SW_GDELAY_CONFIG */

#endif /* __SW_GDELAY_H */
