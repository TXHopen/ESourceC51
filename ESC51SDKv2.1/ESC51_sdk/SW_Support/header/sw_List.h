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
 * @file      sw_List.h
 * 
 * @brief     软件定时器服务组件头文件，包含软件定时器子对象的结构类型、服务组件API、API宏
 * 
 * @version   V0.00.01
 * 
 * @author    HiLittlePiG (2906193044@qq.com)
 * 
 * @date      2021-08-16
 * 
 * @copyright Copyright (c) 2021
 * 
 * *****************************************************ESourceOPEN*****************************************************
 * 
 * *****************************************************ESourceOPEN*****************************************************
 **/
#ifndef __SW_LIST_H
#define __SW_LIST_H


#include "user_config_prj.h"

#ifdef SW_LIST_CONFIG

#include "es_sys_package.h"


/* ------------------------------------------------------------------------------------------------------------------ */
/* 通用链表对象 */

typedef struct _list_node
{
	struct _list_node  *prev;
	struct _list_node  *next;
} __list_node_t;



/* ------------------------------------------------------------------------------------------------------------------ */
/* API */
                                                        
void list_init(__list_node_t *ptr);
void list_add_tail(__list_node_t *src, __list_node_t *ptr);
void list_add_head(__list_node_t *src, __list_node_t *ptr);

__list_node_t* list_del_tail(__list_node_t *src);
__list_node_t* list_del_head(__list_node_t *src);
void list_del(__list_node_t *src, __list_node_t *ptr);



/* ------------------------------------------------------------------------------------------------------------------ */
/* API宏 */



/* ------------------------------------------------------------------------------------------------------------------ */





#endif /* SW_LIST_CONFIG */

#endif /* __SW_LIST_H */
