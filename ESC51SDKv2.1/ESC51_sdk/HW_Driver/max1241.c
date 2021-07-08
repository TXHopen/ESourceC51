#include "max1241.h"

#ifdef MAX1241_CONFIG
/*------------------------------------------------
函数名:AD_MAX1241()
功能:DA转换输出读取函数
参数：无
返回值：voltage_temp
------------------------------------------------*/
uint AD_MAX1241(void)
{
	unsigned long int voltage_temp;
	uint  ucop   = 12; 
	CS_OUT   = 1;
	SCLK_OUT = 0;
	voltage_temp = 0;
	CS_OUT   = 0;
	while(D_OUT == 0);
	SCLK_OUT=1;
	_nop_();
	SCLK_OUT=0;
	while(ucop--)
	{
		voltage_temp <<= 1;
		_nop_();
		SCLK_OUT = 1;
		_nop_();
		if(D_OUT == 1)
			voltage_temp += 1;
		SCLK_OUT = 0;
	}
	CS_OUT   = 1;
	SCLK_OUT = 0;
	return voltage_temp; 
}


#endif /* MAX1241_CONFIG */