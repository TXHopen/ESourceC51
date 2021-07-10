#include "hw_Gtimer.h"

#ifdef GTIMER_CONFIG


/* ------------------------------------------------------------ */

static __GTimerOBJ    *GTimer_Head = NULL;






static char GTimer_function (void *arg) 
{
	static __GTimerOBJ *head = NULL;
	head = GTimer_Head;
	while (head != NULL)
	{
		if (head->status == 2) {
			head->member_func_pointer(head->member_func_arg);
		}
		head = head->next;
	}

	return 0;
}





/* ------------------------------------------------------------ */

void GTimer_Init (void)
{
	GTimer_Head = NULL;
	Timer2Init(TIMER2_MODE_TIMING, 10000, GTimer_function);
}

void GTimer_Start (void)
{
	
}

void GTimer_Stop (void)
{
	
}





char GTimer_OBJJoin (__GTimerOBJ* GTimerobj)
{
	__GTimerOBJ* head = GTimer_Head;

	if (GTimer_Head == NULL) {
		GTimerobj->ID     = 0;
		GTimerobj->status = 1;
		GTimerobj->next   = NULL;
		GTimer_Head       = GTimerobj;
		return 0;
	}
	while (head->next != NULL)
	{
		head = head->next;
	}
	GTimerobj->ID     = head->ID + 1;
	GTimerobj->status = 1;
	GTimerobj->next   = NULL;
	head->next        = GTimerobj;

	return 0;
}



char GTimer_OBJRemove (__GTimerOBJ* GTimerobj)
{
	__GTimerOBJ* head = GTimer_Head;
	__GTimerOBJ* pre  = GTimer_Head;

	if (GTimer_Head == NULL) {
		return -1;
	} else if (GTimer_Head->ID == GTimerobj->ID) {
		GTimer_Head = GTimer_Head->next;
		return 0;
	} else {
		pre  = head;
		head = head->next;
	}
	while (head != NULL)
	{
		if (head->ID == GTimerobj->ID) {
			pre->next = head->next;
			return 0;
		}
		pre  = head;
		head = head->next;
	}

	return -1;
}


char GTimer_OBJRun (__GTimerOBJ* GTimerobj)
{
	__GTimerOBJ*  head = GTimer_Head;

	while (head != NULL)
	{
		if (head->ID == GTimerobj->ID) {
			head->status = 2;
			return 0;
		}
		head = head->next;
	}
	
	return -1;
}

char GTimer_OBJPause (__GTimerOBJ* GTimerobj)
{
	__GTimerOBJ*  head = GTimer_Head;

	while (head != NULL)
	{
		if (head->ID == GTimerobj->ID) {
			head->status = 1;
			return 0;
		}
		head = head->next;
	}
	
	return -1;
}




/* ------------------------------------------------------------ */















#endif /* GTIMER_CONFIG */