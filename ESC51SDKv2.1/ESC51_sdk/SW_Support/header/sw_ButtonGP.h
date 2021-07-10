#ifndef __SW_BUTTONGP_H
#define __SW_BUTTONGP_H


#include "user_config_prj.h"


#ifdef SW_BUTTONGP_CONFIG


#include "es_sys_package.h"



typedef struct _BUTTON_Member
{
	uint8_t         ID;
	uint8_t         status;
	IOPort          inPort;
	IOBit           inBit;
} __BUTTON_CLASS;






static uchar __button_id = 0;


#define BUTTON_OBJ_DECL(BUTTON)  \
    __BUTTON_CLASS  BUTTON
	
#define BUTTON_OBJ_DECL_XDATA(BUTTON)  \
    xdata __BUTTON_CLASS  BUTTON
	
#define BUTTON_OBJ_DECL_PDATA(BUTTON)  \
    pdata __BUTTON_CLASS  BUTTON
	
#define BUTTON_OBJ_DECL_IDATA(BUTTON)  \
    idata __BUTTON_CLASS  BUTTON

#define BUTTON_OBJ_DECL_STATIC(BUTTON)  \
    static __BUTTON_CLASS  BUTTON


#define BUTTON_OBJ_INIT(BUTTON, Port, Bit)  \
		BUTTON.ID        = __button_id; \
		BUTTON.status    = 1; \
		BUTTON.inPort    = Port; \
		BUTTON.inBit     = Bit; \
		__button_id     += 1;

#define BUTTON_OBJ_INIT_STATIC(BUTTON, Port, Bit)  \
		BUTTON.ID        = __button_id; \
		BUTTON.status    = 1; \
		BUTTON.inPort    = Port; \
		BUTTON.inBit     = Bit; \
		__button_id     += 1



#define BUTTON_OBJ_READ(BUTTON) \
		(BUTTON.status == 1) ? io_ctrl_read (BUTTON.inPort, BUTTON.inBit) : -1;



#define BUTTON_OBJ_RUN(BUTTON) \
		BUTTON.status    = 1

#define BUTTON_OBJ_PAUSE(BUTTON) \
		BUTTON.status    = 0





#endif /* SW_BUTTONGP_CONFIG */

#endif /* __SW_BUTTONGP_H */
