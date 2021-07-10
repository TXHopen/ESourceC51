#include "sw_SoftTimer.h"

#ifdef SW_SOFTTIMER_CONFIG






/* ------------------------------------------------------------ */



static __SOFTTimerOBJ   *__stimerobj_head = NULL;


/* ------------------------------------------------------------ */


static void SOFTTimer_callback (void *arg)
{
	static __SOFTTimerOBJ *head = NULL;
	head = __stimerobj_head;

	while (head != NULL)
	{
		if (head->status == 2) {
			head->SoftTimer_obj_remain_ms--;
			if (head->SoftTimer_obj_remain_ms == 0) {
				head->SoftTimer_obj_remain_ms = head->SoftTimer_obj_ms;
				head->SoftTimer_obj_func(head->SoftTimer_obj_arg);
			}
		}
		head = head->next;
	}

}





/* ------------------------------------------------------------ */
GTIMER_OBJ_DECL_STATIC(ST_GTimer);


void SOFTTimer_Init(void)
{
	GTIMER_OBJ_INIT_STATIC(ST_GTimer, SOFTTimer_callback, NULL);
	GTIMER_OBJ_JOIN(ST_GTimer);
}

void SOFTTimer_Start(void)
{

	GTIMER_OBJ_RUN(ST_GTimer);

}

void SOFTTimer_Stop(void)
{

	GTIMER_OBJ_PAUSE(ST_GTimer);

}




/* ------------------------------------------------------------ */






char SOFTTimer_OBJJoin(__SOFTTimerOBJ* pobj)
{
	__SOFTTimerOBJ *head = __stimerobj_head;
	
	if (__stimerobj_head == NULL) {
		pobj->ID         = 0;
		pobj->status     = 1;
		pobj->next       = NULL;
		__stimerobj_head = pobj;
		return 0;
	}
	while (head->next != NULL)
	{
		head = head->next;
	}
	pobj->ID      = head->ID + 1;
	pobj->status  = 1;
	pobj->next    = NULL;
	head->next    = pobj;

	return 0;
}

char SOFTTimer_OBJRemove(__SOFTTimerOBJ* pobj)
{
	
	__SOFTTimerOBJ *head = __stimerobj_head;
	__SOFTTimerOBJ *pre  = __stimerobj_head;

	if (__stimerobj_head == NULL) {
		return -1;
	} else if (__stimerobj_head->ID == pobj->ID) {
		__stimerobj_head = __stimerobj_head->next;
		return 0;
	} else {
		pre  = head;
		head = head->next;
	}
	while (head != NULL)
	{
		if (head->ID == pobj->ID) {
			pre->next = head->next;
			return 0;
		}
		pre  = head;
		head = head->next;
	}

	return -1;
}

char SOFTTimer_OBJPause(__SOFTTimerOBJ* pobj)
{
	__SOFTTimerOBJ*  head = __stimerobj_head;

	while (head != NULL)
	{
		if (head->ID == pobj->ID) {
			head->status = 1;
			return 0;
		}
		head = head->next;
	}
	
	return -1;
}

char SOFTTimer_OBJRun(__SOFTTimerOBJ* pobj)
{
	__SOFTTimerOBJ*  head = __stimerobj_head;

	while (head != NULL)
	{
		if (head->ID == pobj->ID) {
			head->status = 2;
			return 0;
		}
		head = head->next;
	}
	
	return -1;
}


char SOFTTimer_OBJSet(__SOFTTimerOBJ* pobj, int delms)
{
	__SOFTTimerOBJ*  head = __stimerobj_head;

	while (head != NULL)
	{
		if (head->ID == pobj->ID) {
			head->SoftTimer_obj_ms        = delms/10;
			head->SoftTimer_obj_remain_ms = delms/10;
			return 0;
		}
		head = head->next;
	}

	return -1;
}


/* ------------------------------------------------------------ */

#endif /* SW_SOFTTIMER_CONFIG */