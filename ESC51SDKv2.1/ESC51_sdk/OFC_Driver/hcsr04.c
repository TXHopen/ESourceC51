#include "hcsr04.h"

#ifdef HCSR04_CONFIG


static void delay_us(uint us)
{
	us /= 2;
	while (us > 0)
	{
		us--;
		_nop_();
	}
}


uint HCSR04_NoneRead (void)
{
	uint recvtime = 0;
	HCSR04_TRIG = 0;
	//HCSR04_ECHO = 0;
	delay_us(60);
	HCSR04_TRIG = 1;
	delay_us(20);
	HCSR04_TRIG = 0;
	while (HCSR04_ECHO == 0);
	while (HCSR04_ECHO == 1)
	{
		recvtime++;
	}
	
	return recvtime;
}


#ifdef TIMER0_CONFIG

static uint recvus = 0;

static int hcsr04_intcallback(void* arg)
{
	void* ptr = arg;
	recvus++;
	return 0;
}

uint HCSR04_IntConfig (void)
{
	//Timer0Init_NoOpen(TIMER0_MODE_1, 100, hcsr04_intcallback);
	
	return 0;
}

uint HCSR04_IntReadcm (void)
{
	uint recvcm = 0;
	HCSR04_TRIG = 0;
	//HCSR04_ECHO = 0;
	delay_us(60);
	HCSR04_TRIG = 1;
	delay_us(20);
	HCSR04_TRIG = 0;
	
	while (HCSR04_ECHO == 0);
	Timer0Open();
	while (HCSR04_ECHO == 1)
	{
		
	}
	Timer0Close();
	
	recvcm = recvus * 34 / 2 / 10;
	
	return recvcm;
}


#endif /* TIMER0_CONFIG */

#endif /* HCSR04_CONFIG */