#include "dht11.h"

#ifdef DHT11_CONFIG

static void delay(uint16 i)
{
	while(i--);
}

static void delay_ms (uint ms)
{
	uint i = 0;
	while (ms > 0){
		for (i = 0; i < 110; i++);
		ms--;
	}
}

//复位DHT11
void DHT11_Rst()	   
{
    DHT11_DQ_OUT=0; 	//拉低DQ
    delay_ms(20);    	//拉低至少18ms
    DHT11_DQ_OUT=1; 	//DQ=1 
	delay(3);     	    //主机拉高20~40us
}

//等待DHT11的回应
//返回1:未检测到DHT11的存在
//返回0:存在
uint8 DHT11_Check() 	   
{   
	uint8 retry=0;	 
    while (DHT11_DQ_OUT&&retry<100)  //DHT11会拉低40~50us
	{
		retry++;
		_nop_();
	};	 
	if(retry>=100)return 1;
	else retry=0;
    while (!DHT11_DQ_OUT&&retry<100) //DHT11拉低后会再次拉高40~50us
	{
		retry++;
		_nop_();
	};
	if(retry>=100) {
		return 1;
	}
	return 0;
}


//DHT11初始化 
//返回0：初始化成功，1：失败
uint8 DHT11_Init()
{
	DHT11_Rst();	  
	return DHT11_Check();	
}


//从DHT11读取一个位
//返回值：1/0
uint8 DHT11_Read_Bit(void) 			 
{
 	uint8 retry=0;
	while(DHT11_DQ_OUT&&retry<100)    //等待变为低电平 12-14us 开始
	{
		retry++;
		_nop_();
	}
	retry=0;
	while((!DHT11_DQ_OUT)&&retry<100) //等待变高电平	 26-28us表示0,116-118us表示1
	{
		retry++;
		_nop_();
	}
	delay(1);//等待40us
	if(DHT11_DQ_OUT) {
		return 1;
	} else {
		return 0;
	}
}

//从DHT11读取一个字节
//返回值：读到的数据
uint8 DHT11_Read_Byte(void)    
{        
    uint8 i,dat=0;
	for (i=0;i<8;i++) 
	{
   		dat<<=1; 
	    dat|=DHT11_Read_Bit();
    }						    
    return dat;
}

//从DHT11读取一次数据
//temp:温度值(范围:0~50°)
//humi:湿度值(范围:20%~90%)
//返回值：0,正常;1,读取失败
uint8 DHT11_Read_Data(uint8 *temp,uint8 *humi)    
{        
 	uint8 buf[5];
	uint8 i;
	DHT11_Rst();
	if(DHT11_Check()==0)
	{
		for(i=0;i<5;i++) //读取40位数据
		{
			buf[i]=DHT11_Read_Byte();
		}
		if((buf[0]+buf[1]+buf[2]+buf[3])==buf[4])
		{
			*humi=buf[0];
			*temp=buf[2];
		}
		
	} else {
		return 1;
	}
	return 0;
}

#endif /* DHT11_CONFIG */
