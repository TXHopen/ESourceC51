#include "max263.h"

#ifdef MAX263_CONFIG



static float_t __arr_to_float (u8* arr)
{
    float_t buf = 0.0;
	int i       = 0;
	
	for (i = 5; i > 0; i--) {
	    buf *= 10;
		buf += (float_t)(arr[i]);
	}
	buf     += ((float_t)(arr[0])) * 0.1;
	
	return buf;
}

void max263_send (para_body_t* info)
{	
	float_t max263_fh = __arr_to_float (info->max263_fh_body.fh_value_arr);
	
	ad9850_wr_serial(0x00,max263_fh*100);
}

#endif /* MAX263_CONFIG */
