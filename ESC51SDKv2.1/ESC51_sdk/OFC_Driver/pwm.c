#include "pwm.h"

#ifdef PWM_CONFIG



static uchar PWM_PosCYC = 50;
static uchar PWM_NegCYC = 50;
static uchar PWM_CURPOS = 0;


static int pwm_int_function (void *arg) 
{
	void *ptr = arg;
	
	PWM_CURPOS++;
	
	if (PWM_CURPOS == PWM_PosCYC) {
		PWM_OUT    = 0;
	} else if (PWM_CURPOS == 100) {
		PWM_OUT    = 1;
		PWM_CURPOS = 0;
	}
	
	return 0;
}


char PWM_Init (uchar duty)
{
	if (duty == 0) {
		PWM_PosCYC = 50;
		PWM_NegCYC = 50;
	} else if (duty > 100){
		PWM_PosCYC = 50;
		PWM_NegCYC = 50;
	} else {
		PWM_PosCYC = duty;
		PWM_NegCYC = 100 - PWM_PosCYC;
	}
	
	PWM_OUT    = 1;
	PWM_CURPOS = 0;
	
	GTimer_OBJJoin (pwm_int_function, NULL);
	
	return 0;
}


char PWM_Start (void)
{

	PWM_OUT    = 1;
	PWM_CURPOS = 0;
	
	GTimer_OBJRun (pwm_int_function);
	
	return 0;
}

char PWM_Stop (void)
{
	GTimer_OBJPause (pwm_int_function);
	
	PWM_OUT    = 1;
	PWM_CURPOS = 0;
	
	return 0;
}


char PWM_SetDUTY (uchar duty)
{
	PWM_Stop ();
	
	PWM_OUT    = 1;
	PWM_CURPOS = 0;
	
	if (duty == 0) {
		PWM_PosCYC = 50;
		PWM_NegCYC = 50;
	} else if (duty > 100){
		PWM_PosCYC = 50;
		PWM_NegCYC = 50;
	} else {
		PWM_PosCYC = duty;
		PWM_NegCYC = 100 - PWM_PosCYC;
	}
	
	PWM_Start ();
	
	return 0;
}

#endif /* PWM_CONFIG */