#include "esp8266.h"

#ifdef ESP8266_CONFIG
#ifdef UART_CONFIG

static void delay_10us(u16 us)
{
	while(us--);
}

static void delay_ms(u16 ms)
{
	u16 i,j;
	for(i=ms;i>0;i--)
		for(j=114;j>0;j--);
}

void ESP8266_SendCmd(u8 *pbuf)
{
	while(*pbuf!='\0') //遇到空格跳出循环	
	{
		UART_SendByte(*pbuf);
		delay_10us(5);
		pbuf++;	
	}
	delay_10us(5);
	UART_SendByte('\r');//回车
	delay_10us(5);
	UART_SendByte('\n');//换行
	delay_ms(1000);
}

void ESP8266_SendData(u8 *pbuf)
{
	ESP8266_SendCmd("AT+CIPSEND=0,9");
	while(*pbuf!='\0') //遇到空格跳出循环	
	{
		UART_SendByte(*pbuf);
		delay_10us(5);
		pbuf++;	
	}
	delay_10us(5);
	UART_SendByte('\n');//换行	
	delay_ms(10);
}

//ESP8266-WIFI模块工作模式初始化
void ESP8266_ModeInit(void)
{
	ESP8266_RST_Pin=1;
	ESP8266_CH_PD_Pin=1;

	ESP8266_SendCmd("AT+CWMODE=3");//设置路由器模式 1 staTIon模式 2 AP点 路由器模式 3 station+AP混合模式
	ESP8266_SendCmd("AT+CWSAP=\"PRECHIN\",\"prechin168\",11,0"); //设置WIFI热点名及密码
	ESP8266_SendCmd("AT+CIPAP=\"192.168.4.2\"");//重新启动wifi模块
	ESP8266_SendCmd("AT+RST");//重新启动wifi模块
	ESP8266_SendCmd("AT+CIPMUX=1");	//开启多连接模式，允许多个各客户端接入
	ESP8266_SendCmd("AT+CIPSERVER=1,8080");	//启动TCP/IP 端口为8080 实现基于网络控制	
}


#endif /* UART_CONFIG */
#endif /* ESP8266_CONFIG */