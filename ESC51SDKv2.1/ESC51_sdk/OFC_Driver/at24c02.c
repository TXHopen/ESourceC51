/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      at24c02.c
 * 
 * @brief     片外驱动：at24c02驱动源码
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
#include "at24c02.h"

#ifdef AT24C02_CONFIG
#ifdef IIC_CONFIG

/* ------------------------------------------------------------------------------------------------------------------ */


void At24c02Write(unsigned char addr,unsigned char dat)
{
	I2cStart();
	I2cSendByte(0xa0);//发送写器件地址
	I2cSendByte(addr);//发送要写入内存地址
	I2cSendByte(dat);	//发送数据
	I2cStop();
}




unsigned char At24c02Read(unsigned char addr)
{
	unsigned char num;
	I2cStart();
	I2cSendByte(0xa0); //发送写器件地址
	I2cSendByte(addr); //发送要读取的地址
	I2cStart();
	I2cSendByte(0xa1); //发送读器件地址
	num=I2cReadByte(); //读取数据
	I2cStop();
	return num;	
}

/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* IIC_CONFIG */

#endif /* AT24C02_CONFIG */