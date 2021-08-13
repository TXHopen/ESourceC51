/***********************************************************************************************************************
 *                                                      ESourceOpen
 *                                           -----------------------------------
 *                                           explore and open  embedded platform
 * 
 * Contact information:
 * e-mail: 1786409879@qq.com / txh17778443952@169.com
 *                                                                                 +-------------+---------------------+
 * ESourceOpen：                                                                   |   founder   |       TXHopen       |
 *   The ESource plan is a difficult and long-term plan. This plan                 +-------------+---------------------+
 *   does not limit the use of code, only to provide an open platform              |   encode    |    UTF-8 / utf-8    |
 *   to explore the software development of embedded platforms.                    +-------------+---------------------+
***********************************************************************************************************************/
/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      sw_PWMGroup.h
 * 
 * @brief     多路PWM组件头文件，包含子对象类型、多路PWM组件API、多路PWM组件API宏
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
#ifndef __SW_PWMGROUP_H
#define __SW_PWMGROUP_H


#include "user_config_prj.h"


#ifdef SW_PWMGROUP_CONFIG


#include "es_sys_package.h"


/* ------------------------------------------------------------------------------------------------------------------ */
/* 子对象类型 */

typedef struct _PWMGROUP_Member
{
	uint8_t         ID;
	uint8_t         status;
	IOPort          OutPort;
	IOBit           OutBit;
	uint8_t         OutPosCYC;
	uint8_t         OutCurPOS;
	struct _PWMGROUP_Member *next;
} __PWMGROUP_Member;






/* ------------------------------------------------------------------------------------------------------------------ */
/* 组件API */

char PWMGroup_Init (void);
char PWMGroup_Start (void);
char PWMGroup_Stop (void);

char PWMGroup_OBJJoin (__PWMGROUP_Member *pobj);
char PWMGroup_OBJRemove (__PWMGROUP_Member *pobj);
char PWMGroup_OBJRun (__PWMGROUP_Member *pobj);
char PWMGroup_OBJPause (__PWMGROUP_Member *pobj);
char PWMGroup_OBJSetDUTY (__PWMGROUP_Member *pobj, uint8_t duty);



/* ------------------------------------------------------------------------------------------------------------------ */
/* 组件API宏 */

#define PWMGROUP_OBJ_DECL(PWMOBJ)  \
    __PWMGROUP_Member PWMOBJ
	
#define PWMGROUP_OBJ_DECL_XDATA(PWMOBJ)  \
    xdata __PWMGROUP_Member PWMOBJ
	
#define PWMGROUP_OBJ_DECL_PDATA(PWMOBJ)  \
    pdata __PWMGROUP_Member PWMOBJ
	
#define PWMGROUP_OBJ_DECL_IDATA(PWMOBJ)  \
    idata __PWMGROUP_Member PWMOBJ

#define PWMGROUP_OBJ_DECL_STATIC(PWMOBJ)  \
    static __PWMGROUP_Member PWMOBJ

#define PWMGROUP_OBJ_INIT(PWMOBJ, Port, Bit, PosCYC)  \
		PWMOBJ.ID        = 0; \
		PWMOBJ.status    = 0; \
		PWMOBJ.OutPort   = Port; \
		PWMOBJ.OutBit    = Bit; \
		PWMOBJ.OutPosCYC = PosCYC; \
		PWMOBJ.OutCurPOS = 0; \
		PWMOBJ.next      = NULL;

#define PWMGROUP_OBJ_INIT_STATIC(PWMOBJ, Port, Bit, PosCYC)  \
		PWMOBJ.ID        = 0; \
		PWMOBJ.status    = 0; \
		PWMOBJ.OutPort   = Port; \
		PWMOBJ.OutBit    = Bit; \
		PWMOBJ.OutPosCYC = PosCYC; \
		PWMOBJ.OutCurPOS = 0; \
		PWMOBJ.next      = NULL;



#define PWMGROUP_OBJ_JOIN(PWMOBJ) \
		PWMGroup_OBJJoin(&PWMOBJ)

#define PWMGROUP_OBJ_REMOVE(PWMOBJ) \
		PWMGroup_OBJRemove(&PWMOBJ)

#define PWMGROUP_OBJ_RUN(PWMOBJ) \
		PWMGroup_OBJRun(&PWMOBJ)

#define PWMGROUP_OBJ_PAUSE(PWMOBJ) \
		PWMGroup_OBJPause(&PWMOBJ)

#define PWMGROUP_OBJ_SETDUTY(PWMOBJ, Del) \
		PWMGroup_OBJSetDUTY(&PWMOBJ, Del)


/* ------------------------------------------------------------------------------------------------------------------ */

#endif /* SW_PWMGROUP_CONFIG */

#endif /* __SW_PWMGROUP_H */
