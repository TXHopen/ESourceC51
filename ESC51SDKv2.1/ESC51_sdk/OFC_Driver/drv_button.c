#include "drv_button.h"


#ifdef ALONEBUTTON_CONFIG


/**
  * @brief :1MS延时函数
  * @param :
  * @note  :12MHz 下1MS延时
  * @retval:无
  */
static void drv_delay_1ms( )
{
	uint16_t Ms = 1;
	uint32_t j = 80;
	
	while( Ms-- )
	{
		while( j-- );
	}
}

/**
  * @brief :MS延时函数
  * @param :
  *			@Ms:延时的MS数
  * @note  :无
  * @retval:无
  */
static void drv_delay_ms( uint16_t Ms )
{
	while( Ms-- )
	{
		drv_delay_1ms( );
	}
}



/**
  * @brief :按键初始化
  * @param :无
  * @note  :无
  * @retval:无
  */ 
void drv_button_init( void )
{
	//引脚配置 部分51单片机不需要
	//BUTTON引脚配置为输入
	BUTTON_PxM0 = IO_IN_PUT_ONLY_M0 << BUTTON_PIN_BIT;
	BUTTON_PxM1 = IO_IN_PUT_ONLY_M1 << BUTTON_PIN_BIT;
	
	BUTTON_PIN = 1;		//默认状态置高
}

/**
  * @brief :按键查询
  * @param :无
  * @note  :无
  * @retval:
  *			0:按键没有按下
  *			1:检测到按键动作
  */
uint8_t drv_button_check( void )
{
	if( 1 != BUTTON_PIN )		//检测按键输入状态
	{
		drv_delay_ms( 45 );		//消抖
		if( 1 != BUTTON_PIN )
		{
			while (1 != BUTTON_PIN);
			return 1;			//按键按下，返回按键状态
		}
	}
	
	return 0;
}



#endif /* ALONEBUTTON_CONFIG */
