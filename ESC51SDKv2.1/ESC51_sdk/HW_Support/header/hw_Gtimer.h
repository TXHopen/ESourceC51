#ifndef __HW_GTIMER_H
#define __HW_GTIMER_H

#include "user_config_prj.h"

#ifdef GTIMER_CONFIG



#include "es_sys_package.h"






typedef struct _GTimer_Member
{
	uchar ID;
	uchar status;
	void (*member_func_pointer)(void* arg);
	void  *member_func_arg;
	struct _GTimer_Member *next;
} __GTimerOBJ;



void GTimer_Init (void);
void GTimer_Start (void);
void GTimer_Stop (void);

char GTimer_OBJJoin (__GTimerOBJ* GTimerobj);
char GTimer_OBJRemove (__GTimerOBJ* GTimerobj);
char GTimer_OBJRun (__GTimerOBJ* GTimerobj);
char GTimer_OBJPause (__GTimerOBJ* GTimerobj);









#define GTIMER_OBJ_DECL(GTimer)  \
    __GTimerOBJ GTimer

#define GTIMER_OBJ_DECL_STATIC(GTimer)  \
    static __GTimerOBJ GTimer

#define GTIMER_OBJ_INIT(GTimer, funcptr, funcarg)  \
		GTimer.ID     = 0; \
		GTimer.status = 0; \
		GTimer.member_func_pointer = funcptr; \
		GTimer.member_func_arg = funcarg; \
		GTimer.next = NULL;

#define GTIMER_OBJ_INIT_STATIC(GTimer, funcptr, funcarg)  \
		GTimer.ID     = 0; \
		GTimer.status = 0; \
		GTimer.member_func_pointer = funcptr; \
		GTimer.member_func_arg = funcarg; \
		GTimer.next = NULL;



#define GTIMER_OBJ_JOIN(GTimer) \
		GTimer_OBJJoin(&GTimer)

#define GTIMER_OBJ_REMOVE(GTimer) \
		GTimer_OBJRemove(&GTimer)

#define GTIMER_OBJ_RUN(GTimer) \
		GTimer_OBJRun(&GTimer)

#define GTIMER_OBJ_PAUSE(GTimer) \
		GTimer_OBJPause(&GTimer)


#endif /* GTIMER_CONFIG */

#endif /* __HW_GTIMER_H */