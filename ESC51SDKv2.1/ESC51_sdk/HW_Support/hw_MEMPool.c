#include "hw_MEMPool.h"

#ifdef MEMPOOL_CONFIG

xdata char mempool[MEMPOOL_SIZE] = {0};

void mempool_init (void)
{
	
	init_mempool (mempool, MEMPOOL_SIZE);
	
}



#endif /* MEMPOOL_CONFIG */
