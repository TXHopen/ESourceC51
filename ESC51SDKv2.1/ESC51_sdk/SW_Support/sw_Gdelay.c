/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      sw_Gdelay.c
 * 
 * @brief     软件组件支持：通用延时函数源码
 * 
 * @version   V0.00.01
 * 
 * @author    TXHopen (3332695529@qq.com)
 * 
 * @date      2021-08-08
 * 
 * @copyright Copyright (c) 2021
 * 
 * *****************************************************ESourceOPEN*****************************************************
 * 
 * *****************************************************ESourceOPEN*****************************************************
 **/
#include "sw_Gdelay.h"

#ifdef SW_GDELAY_CONFIG

void es_delay_ms (uint ms)
{
	uchar i = 0;
	if (ms <= 0) {
		return ;
	}
	while (ms--)
	{
		for(i=0; i<110; i++);
	}
}

void es_delay_ns (uint ns)
{
	if (ns <= 0) {
		return ;
	}
	while (ns--)
	{
		_nop_();
	}
}



void es_delay_10ms (uint ms10)
{
	uint i = 0;
	if (ms10 <= 0) {
		return ;
	}
	while (ms10--)
	{
		for(i=0; i<1100; i++);
	}
}

void es_delay_10ns (uint ns10)
{
	if (ns10 <= 0) {
		return ;
	}
	while (ns10--)
	{
		_nop_();_nop_();
		_nop_();_nop_();
		_nop_();_nop_();
		_nop_();_nop_();
	}
}




#endif /* SW_GDELAY_CONFIG */