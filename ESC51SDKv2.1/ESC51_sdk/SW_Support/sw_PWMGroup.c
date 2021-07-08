#include "sw_PWMGroup.h"

#ifdef SW_PWMGROUP_CONFIG





/* ------------------------------------------------------------ */



static __PWMGROUP_Member    *__PWMGroup_OBJ = NULL;



/* ------------------------------------------------------------ */
static void PWMGroup_function (void *arg) 
{
	void *ptr = arg;

	static __PWMGROUP_Member  *head = NULL;
	head = __PWMGroup_OBJ;

	while (head != NULL)
	{
		if (head->status == 2) {
			head->OutCurPOS++;
			if (head->OutCurPOS == head->OutPosCYC) {
				io_ctrl_set_low (head->OutPort, head->OutBit);
			} else if (head->OutCurPOS == 100) {
				io_ctrl_set_high (head->OutPort, head->OutBit);
				head->OutCurPOS = 0;
			}
		}
		head = head->next;
	}
}





/* ------------------------------------------------------------ */
GTIMER_OBJ_DECL_STATIC(PWMGROUP);



char PWMGroup_Init (void)
{
	GTIMER_OBJ_INIT_STATIC(PWMGROUP, PWMGroup_function, NULL);
	
	GTIMER_OBJ_JOIN(PWMGROUP);
	
	return 0;
}


char PWMGroup_Start (void)
{
	
	GTIMER_OBJ_RUN(PWMGROUP);
	
	return 0;
}

char PWMGroup_Stop (void)
{

	GTIMER_OBJ_PAUSE(PWMGROUP);
	
	return 0;
}



/* ------------------------------------------------------------ */

char PWMGroup_OBJJoin (__PWMGROUP_Member *pobj)
{
	__PWMGROUP_Member  *head = __PWMGroup_OBJ;

	if (__PWMGroup_OBJ == NULL) {
		pobj->ID         = 0;
		pobj->status     = 1;
		pobj->next       = NULL;
		__PWMGroup_OBJ   = pobj;
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

char PWMGroup_OBJRemove (__PWMGROUP_Member *pobj)
{

	__PWMGROUP_Member  *head = __PWMGroup_OBJ;
	__PWMGROUP_Member  *pre  = __PWMGroup_OBJ;

	if (__PWMGroup_OBJ == NULL) {
		return -1;
	} else if (__PWMGroup_OBJ->ID == pobj->ID) {
		__PWMGroup_OBJ = __PWMGroup_OBJ->next;
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
	
	return 0;
}

char PWMGroup_OBJRun (__PWMGROUP_Member *pobj)
{

	__PWMGROUP_Member*  head = __PWMGroup_OBJ;

	while (head != NULL)
	{
		if (head->ID == pobj->ID) {
			head->status = 2;
			return 0;
		}
		head = head->next;
	}
	
	return 0;
}

char PWMGroup_OBJPause (__PWMGROUP_Member *pobj)
{
	__PWMGROUP_Member*  head = __PWMGroup_OBJ;

	while (head != NULL)
	{
		if (head->ID == pobj->ID) {
			head->status = 1;
			return 0;
		}
		head = head->next;
	}
	
	return 0;
}

char PWMGroup_OBJSetDUTY (__PWMGROUP_Member *pobj, uint8_t duty)
{
	__PWMGROUP_Member*  head = __PWMGroup_OBJ;

	while (head != NULL)
	{
		if (head->ID == pobj->ID) {
			head->OutPosCYC = duty;
			head->OutCurPOS = 0;
			return 0;
		}
		head = head->next;
	}
	
	return 0;
}




/* ------------------------------------------------------------ */












#endif /* SW_PWMGROUP_CONFIG */