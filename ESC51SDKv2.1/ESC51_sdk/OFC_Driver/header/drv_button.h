#ifndef __DRV_BUTTON_H__
#define __DRV_BUTTON_H__


#include "user_config_prj.h"

#ifdef ALONEBUTTON_CONFIG

#include "es_sys_package.h"




//按键接口定义
sbit		BUTTON_PIN				=P3^1;

//BUTTON引脚在端口的Bit位置
#define		BUTTON_PIN_BIT			1							

#define		BUTTON_PxM0				IO_P3M0
#define		BUTTON_PxM1				IO_P3M1


/** 按键状态定义 */
enum
{
	BUTOTN_UP = 0,		//按键未按下
	BUTOTN_PRESS_DOWN	//按键按下
};



void drv_button_init( void );
uint8_t drv_button_check( void );


#endif /* ALONEBUTTON_CONFIG */

#endif /* __DRV_BUTTON_H__ */

