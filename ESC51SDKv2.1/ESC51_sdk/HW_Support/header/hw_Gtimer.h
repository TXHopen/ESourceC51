/***********************************************************************************************************************
 *                                                      ESourceOpen
 *                                           -----------------------------------
 *                                           explore and open  embedded platform
 * 
 * Contact information:
 * e-mail: 1786409879@qq.com / txh17778443952@169.com
 *                                                                                                              TXHopen
***********************************************************************************************************************/
/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      hw_Gtimer.h
 * 
 * @brief     硬件支持组件：通用定时器组件，包含通用定时器组件API
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
#ifndef __HW_GTIMER_H
#define __HW_GTIMER_H

#include "user_config_prj.h"

#ifdef GTIMER_CONFIG



#include "es_sys_package.h"




/* ------------------------------------------------------------------------------------------------------------------ */

typedef struct _GTimer_Member
{
	uchar ID;
	uchar status;
	void (*member_func_pointer)(void* arg);
	void  *member_func_arg;
	struct _GTimer_Member *next;
} __GTimerOBJ;

/* ------------------------------------------------------------------------------------------------------------------ */

void GTimer_Init (void);
void GTimer_Start (void);
void GTimer_Stop (void);

char GTimer_OBJJoin (__GTimerOBJ* GTimerobj);
char GTimer_OBJRemove (__GTimerOBJ* GTimerobj);
char GTimer_OBJRun (__GTimerOBJ* GTimerobj);
char GTimer_OBJPause (__GTimerOBJ* GTimerobj);





/* ------------------------------------------------------------------------------------------------------------------ */



#define GTIMER_OBJ_DECL(GTimer)  \
    __GTimerOBJ GTimer
	
#define GTIMER_OBJ_DECL_XDATA(GTimer)  \
    xdata __GTimerOBJ GTimer
	
#define GTIMER_OBJ_DECL_PDATA(GTimer)  \
    pdata __GTimerOBJ GTimer
	
#define GTIMER_OBJ_DECL_IDATA(GTimer)  \
    idata __GTimerOBJ GTimer

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

/* ------------------------------------------------------------------------------------------------------------------ */
#endif /* GTIMER_CONFIG */

#endif /* __HW_GTIMER_H */