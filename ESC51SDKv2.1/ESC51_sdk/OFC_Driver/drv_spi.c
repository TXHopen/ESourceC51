#include "drv_spi.h"


#ifdef DRV_SPI_CONFIG

/**
  * @brief :SPI初始化(软件)
  * @param :无
  * @note  :无
  * @retval:无
  */
void drv_spi_init( void )
{
	//引脚配置 部分51单片机不需要
	//SCK MOSI NSS 配置为推挽输出
	SPI_SCK_PxM0 = IO_OUT_PUT_PP_M0 << SPI_SCK_PIN_BIT;
	SPI_SCK_PxM1 = IO_OUT_PUT_PP_M1 << SPI_SCK_PIN_BIT;
	
	SPI_MOSI_PxM0 = IO_OUT_PUT_PP_M0 << SPI_MOSI_PIN_BIT;
	SPI_MOSI_PxM1 = IO_OUT_PUT_PP_M1 << SPI_MOSI_PIN_BIT;
	
	SPI_NSS_PxM0 = IO_OUT_PUT_PP_M0 << SPI_NSS_PIN_BIT;
	SPI_NSS_PxM1 = IO_OUT_PUT_PP_M1 << SPI_NSS_PIN_BIT;
	
	//MISO 配置为输入
	SPI_MISO_PxM0 = IO_IN_PUT_ONLY_M0 << SPI_MISO_PIN_BIT;
	SPI_MISO_PxM1 = IO_IN_PUT_ONLY_M1 << SPI_MISO_PIN_BIT;
	
	//时钟置低
	SPI_SCK = 0;	
	//MOSI MISO NSS置高
	SPI_MOSI = 1;		
	SPI_MISO = 1;
	SPI_NSS = 1;	
}

/**
  * @brief :SPI收发一个字节
  * @param :
  *			@TxByte: 发送的数据字节
  * @note  :非堵塞式，一旦等待超时，函数会自动退出
  * @retval:接收到的字节
  */
uint8_t drv_spi_read_write_byte( uint8_t TxByte )
{
	uint8_t i = 0, Data = 0;
	
	spi_set_clk_low( );
	
	for( i = 0; i < 8; i++ )			//一个字节8byte需要循环8次
	{
		/** 发送 */
		if( 0x80 == ( TxByte & 0x80 ))
		{
			spi_set_mosi_hight( );		//如果即将要发送的位为 1 则置高IO引脚
		}
		else
		{
			spi_set_mosi_low( );		//如果即将要发送的位为 0 则置低IO引脚
		}
		TxByte <<= 1;					//数据左移一位，先发送的是最高位
		spi_set_clk_high( );			//时钟线置高
		_nop_( );
	
		/** 接收 */
		Data <<= 1;						//接收数据左移一位，先接收到的是最高位
		if( 1 == spi_get_miso( ))
		{
			Data |= 0x01;				//如果接收时IO引脚为高则认为接收到 1
		}
		
		spi_set_clk_low( );				//时钟线置低
		_nop_( );
	}
	
	return Data;		//返回接收到的字节
}

/**
  * @brief :SPI收发字符串
  * @param :
  *			@ReadBuffer: 接收数据缓冲区地址
  *			@WriteBuffer:发送字节缓冲区地址
  *			@Length:字节长度
  * @note  :非堵塞式，一旦等待超时，函数会自动退出
  * @retval:无
  */
void drv_spi_read_write_string( uint8_t* ReadBuffer, uint8_t* WriteBuffer, uint16_t Length )
{
	spi_set_nss_low( );			//片选拉低
	
	while( Length-- )
	{
		*ReadBuffer = drv_spi_read_write_byte( *WriteBuffer );		//收发数据
		ReadBuffer++;
		WriteBuffer++;			//读写地址加1
	}
	
	spi_set_nss_high( );		//片选拉高
}



#endif /* DRV_SPI_CONFIG */

