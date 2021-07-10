#include "es_sys_package.h"

int mm = 0;
int nn = 0;
int jj = 0;

sbit LED1 = P1^0;
sbit LED2 = P1^1;
sbit LED3 = P1^2;
sbit LED4 = P1^3;
sbit LED5 = P1^4;
sbit LED6 = P1^5;
sbit LED7 = P1^6;
sbit LED8 = P1^7;

static void test (void* arg)
{
	mm++;
	if (mm == 60) {
		P2 = ~P2;
		mm = 0;
	}
	
}


void test1 (void* arg)
{
	P0 = ~P0;
}


void test2 (void* arg)
{
	nn++;
	if (nn == 100) {
		P2 = ~P2;
		nn = 0;
	}
}

void test3 (void* arg)
{
	jj++;
	if (jj == 40) {
		P3 = ~P3;
		jj = 0;
	}
}


void led1(void* arg)
{
	LED1 = ~LED1;
}

void led2(void* arg)
{
	LED2 = ~LED2;
}

void led3(void* arg)
{
	LED3 = ~LED3;
}

void led4(void* arg)
{
	LED4 = ~LED4;
}

void led5(void* arg)
{
	LED5 = ~LED5;
}

void led6(void* arg)
{
	LED6 = ~LED6;
}


//SOFTTIMER_OBJ_DECL(LD1);
//SOFTTIMER_OBJ_DECL(LD2);
//SOFTTIMER_OBJ_DECL(LD3);
//SOFTTIMER_OBJ_DECL(LD4);
//PWMGROUP_OBJ_DECL(PWM1);
//PWMGROUP_OBJ_DECL(PWM2);
//PWMGROUP_OBJ_DECL(PWM3);
//PWMGROUP_OBJ_DECL(PWM4);

void es_main(void)
{

//	GTIMER_OBJ_DECL_STATIC(GTimer2);
//	GTIMER_OBJ_DECL_STATIC(GTimer3);
//	GTIMER_OBJ_DECL_STATIC(GTimer1);
//	GTIMER_OBJ_DECL_STATIC(GTimer4);
//	
//	
//	
//	
//	GTIMER_OBJ_INIT_STATIC(GTimer2, test, NULL);
//	GTIMER_OBJ_JOIN(GTimer2);
//	GTIMER_OBJ_RUN(GTimer2);
//	
//	GTIMER_OBJ_INIT_STATIC(GTimer3, test2, NULL);
//	GTIMER_OBJ_JOIN(GTimer3);
//	GTIMER_OBJ_RUN(GTimer3);

//	GTIMER_OBJ_INIT_STATIC(GTimer1, test3, NULL);
//	GTIMER_OBJ_JOIN(GTimer1);
//	GTIMER_OBJ_RUN(GTimer1);
//	
//	GTIMER_OBJ_INIT_STATIC(GTimer4, test1, NULL);
//	GTIMER_OBJ_JOIN(GTimer4);
//	GTIMER_OBJ_RUN(GTimer4);
//	
//	SOFTTIMER_OBJ_INIT(LD1, led1, NULL, 500);
//	SOFTTIMER_OBJ_INIT(LD2, led2, NULL, 500);
//	SOFTTIMER_OBJ_INIT(LD3, led3, NULL, 500);
//	SOFTTIMER_OBJ_INIT(LD4, led4, NULL, 500);
//	
//	SOFTTIMER_OBJ_JOIN(LD1);
//	SOFTTIMER_OBJ_JOIN(LD2);
//	SOFTTIMER_OBJ_JOIN(LD3);
//	SOFTTIMER_OBJ_JOIN(LD4);
//	
//	SOFTTIMER_OBJ_RUN(LD1);
//	SOFTTIMER_OBJ_RUN(LD2);
//	SOFTTIMER_OBJ_RUN(LD3);
//	SOFTTIMER_OBJ_RUN(LD4);
	
	
	
//	PWMGROUP_OBJ_INIT(PWM1, IO_P1, IO_Bit4, 50);
//	PWMGROUP_OBJ_INIT(PWM2, IO_P1, IO_Bit5, 90);
//	PWMGROUP_OBJ_INIT(PWM3, IO_P1, IO_Bit6, 50);
//	PWMGROUP_OBJ_INIT(PWM4, IO_P1, IO_Bit7, 10);
//	
//	PWMGROUP_OBJ_JOIN(PWM1);
//	PWMGROUP_OBJ_JOIN(PWM2);
//	PWMGROUP_OBJ_JOIN(PWM3);
//	PWMGROUP_OBJ_JOIN(PWM4);
//
//	PWMGROUP_OBJ_RUN(PWM1);
//	PWMGROUP_OBJ_RUN(PWM4);
//	PWMGROUP_OBJ_RUN(PWM2);
//	PWMGROUP_OBJ_RUN(PWM3);
	
	PFM_Init(100);
	PFM_Start();
	PFM_SetFrq(2000);


	while (1)
	{
		
		
	}
}