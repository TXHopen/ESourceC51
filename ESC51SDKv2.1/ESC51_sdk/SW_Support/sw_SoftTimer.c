/***********************************************************************************************************************
 *                                                      ESourceOpen
 *                                           -----------------------------------
 *                                           explore and open  embedded platform
 * 
 * Contact information:
 * e-mail: 1786409879@qq.com / txh17778443952@169.com
 *                                                                                                              
 *                                                                                                              TXHopen
 *                                                                                                         encode:UTF-8
***********************************************************************************************************************/
/**
 * *****************************************************ESourceOPEN*****************************************************
 * @file      sw_SoftTimer.c
 * 
 * @brief     软件组件支持：软件定时器源码
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

#include "sw_SoftTimer.h"

#ifdef SW_SOFTTIMER_CONFIG




/* ------------------------------------------------------------------------------------------------------------------ */
/* 组件内部 静态部分 */

static __SOFTTimerOBJ   *__stimerobj_head = NULL;                     /* 软件定时器列表                                */



/**
 * @brief  软件定时器组件基础部分回调函数
 * 
 * @param  arg ：回调函数传入参数
 **/
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




/* ------------------------------------------------------------------------------------------------------------------ */
/* 组件API */

GTIMER_OBJ_DECL_STATIC(ST_GTimer);                                    /* 生成一个通用定时器对象                         */



/**
 * @brief  软件定时器组件初始化函数（已在bsp_config.c中被调用）
 * 
 **/
void SOFTTimer_Init(void)
{
	GTIMER_OBJ_INIT_STATIC(ST_GTimer, SOFTTimer_callback, NULL);
	GTIMER_OBJ_JOIN(ST_GTimer);
}

/**
 * @brief  软件定时器组件启动函数（已在bsp_config.c中被调用）
 * 
 **/
void SOFTTimer_Start(void)
{

	GTIMER_OBJ_RUN(ST_GTimer);

}

/**
 * @brief  软件定时器组件停止函数（可自行调用）
 * 
 **/
void SOFTTimer_Stop(void)
{

	GTIMER_OBJ_PAUSE(ST_GTimer);

}






/**
 * @brief  将服务对象添加至软件定时器组件
 * 
 * @param  pobj ：需要添加的服务对象的指针
 * @return char ：错误码
 **/
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

/**
 * @brief  将服务对象从软件定时器组件中移除
 * 
 * @param  pobj ：需要移除的服务对象的指针
 * @return char ：错误码
 **/
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

/**
 * @brief  暂停在软件定时器中的服务对象
 * 
 * @param  pobj ：需要暂停的服务对象指针
 * @return char ：错误码
 **/
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

/**
 * @brief  运行在软件定时器中的服务对象
 * 
 * @param  pobj ：服务对象的指针
 * @return char ：错误码
 **/
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

/**
 * @brief  设置软件定时器中服务对象的延时时间
 * 
 * @param  pobj ：服务对象的指针
 * @param  delms ：新的延时时间
 * @return char ：错误码
 **/
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


/* ------------------------------------------------------------------------------------------------------------------ */

#endif /* SW_SOFTTIMER_CONFIG */