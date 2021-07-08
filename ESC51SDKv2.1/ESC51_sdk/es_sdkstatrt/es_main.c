#include "es_sys_package.h"

extern void es_main(void);

void main()
{
	bsp_init ();
	
	es_main();
}


