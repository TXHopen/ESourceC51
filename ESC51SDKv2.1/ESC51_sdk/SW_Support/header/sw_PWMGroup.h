#ifndef __SW_PWMGROUP_H
#define __SW_PWMGROUP_H


#include "user_config_prj.h"


#ifdef SW_PWMGROUP_CONFIG


#include "es_sys_package.h"



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









char PWMGroup_Init (void);
char PWMGroup_Start (void);
char PWMGroup_Stop (void);

char PWMGroup_OBJJoin (__PWMGROUP_Member *pobj);
char PWMGroup_OBJRemove (__PWMGROUP_Member *pobj);
char PWMGroup_OBJRun (__PWMGROUP_Member *pobj);
char PWMGroup_OBJPause (__PWMGROUP_Member *pobj);
char PWMGroup_OBJSetDUTY (__PWMGROUP_Member *pobj, uint8_t duty);





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




#endif /* SW_PWMGROUP_CONFIG */

#endif /* __SW_PWMGROUP_H */
