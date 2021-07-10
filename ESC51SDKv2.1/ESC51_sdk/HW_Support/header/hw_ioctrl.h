#ifndef __HW_IOCTRL_H
#define __HW_IOCTRL_H



#include "user_config_prj.h"




sfr IO_P0M0			= 0x93;
sfr IO_P0M1			= 0x94;
sfr IO_P1M0			= 0x91;
sfr IO_P1M1			= 0x92;
sfr IO_P2M0			= 0x95;
sfr IO_P2M1			= 0x96;
sfr IO_P3M0			= 0xB1;
sfr IO_P3M1			= 0xB2;

/** IO属性定�? */
//准双向口
#define IO_IN_OUT_PUT_M0			((uint8_t)0x00)
#define IO_IN_OUT_PUT_M1			((uint8_t)0x00)
//推挽输出
#define IO_OUT_PUT_PP_M0			((uint8_t)0x00)
#define IO_OUT_PUT_PP_M1			((uint8_t)0x01)
//仅为输入(高阻)
#define IO_IN_PUT_ONLY_M0			((uint8_t)0x01)
#define IO_IN_PUT_ONLY_M1			((uint8_t)0x00)
//开�?
#define IO_OPEN_DRAIN_M0			((uint8_t)0x01)
#define IO_OPEN_DRAIN_M1			((uint8_t)0x01)



typedef enum _IO_Port
{ 
	IO_P0 = 0, 
	IO_P1,
    IO_P2,
    IO_P3
} IOPort;




typedef enum _IO_Bit
{
    IO_Bit0 = 0,
    IO_Bit1,
    IO_Bit2,
    IO_Bit3,
    IO_Bit4,
    IO_Bit5,
    IO_Bit6,
    IO_Bit7
} IOBit;


typedef enum
{
    IO_IN_OUT_PUT = 0,
    IO_OUT_PUT_PP,
    IO_IN_PUT_ONLY,
    IO_OPEN_DRAIN,
} IOMode;




#define ES_GPIO_SET_HIGH(GPIO)             GPIO = 1;
#define ES_GPIO_SET_LOW(GPIO)              GPIO = 0;
#define ES_GPIO_SET_TOGGLE(GPIO)           GPIO = ~GPIO;
#define ES_GPIO_PORT_SET_DATA(PORT, DATA)  PORT  =  DATA;
#define ES_GPIO_READ_PORT(PORT)            PORT;
#define ES_GPIO_READ_BIT(PORT)             PORT;

#define ES_IO_CTRL_SET_HIGH(PORT, BIT)     PORT |=  (0x01 << BIT);
#define ES_IO_CTRL_SET_LOW(PORT, BIT)      PORT &= ~(0x01 << BIT);
//#define ES_IO_CTRL_READ_PORT(PORT, BIT)    PORT &= ~(0x01 << BIT);
//#define ES_IO_CTRL_READ_BIT(PORT, BIT)     PORT &= ~(0x01 << BIT);







#ifdef IOCTRL_CONFIG

#include "es_sys_package.h"

char io_ctrl_set_mode (IOPort Port, IOBit Bit, IOMode mode);
char io_ctrl_set_high (IOPort Port, IOBit Bit);
char io_ctrl_set_low (IOPort Port, IOBit Bit);
char io_ctrl_read (IOPort Port, IOBit Bit);




#endif /* IOCTRL_CONFIG */

#endif /* __HW_IOCTRL_H */