#include "es_sys_package.h"


static void bsp_gpio_config (void)
{
	P0=0xff;
	P1=0xff;
	P2=0xff;
	P3=0xff;
}

void bsp_init (void)
{
	bsp_gpio_config ();
	
#ifdef MEMPOOL_CONFIG
	mempool_init ();
#endif /* MEMPOOL_CONFIG */
	
#ifdef GTIMER_CONFIG
	GTimer_Init ();
	GTimer_Start ();
#endif /* GTIMER_CONFIG */
	
#ifdef SW_SOFTTIMER_CONFIG
	SOFTTimer_Init ();
	SOFTTimer_Start ();
#endif /* SW_SOFTTIMER_CONFIG */
	
#ifdef SW_PWMGROUP_CONFIG
	PWMGroup_Init ();
	PWMGroup_Start ();
#endif /* SW_PWMGROUP_CONFIG */
}
