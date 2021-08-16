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
 * @file      sw_List.c
 * 
 * @brief     软件组件支持：软件定时器源码
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

#include "sw_List.h"

#ifdef SW_LIST_CONFIG




/* ------------------------------------------------------------------------------------------------------------------ */
/* 组件内部 静态部分 */





/* ------------------------------------------------------------------------------------------------------------------ */
/* 组件API */

void list_init(__list_node_t *ptr)
{
	ptr->next = NULL;
	ptr->prev = NULL;
}

void list_add_tail(__list_node_t *src, __list_node_t *ptr)
{
	if (src == NULL) {
		return ;
	}

	while (src->next != NULL) {
		src = src->next;
	}
	ptr->prev = src;
	src->next = ptr;
}

void list_add_head(__list_node_t *src, __list_node_t *ptr)
{
	if (src == NULL) {
		return ;
	}

	while (src->prev != NULL) {
		src = src->prev;
	}
	ptr->next = src;
	src->prev = ptr;
}

__list_node_t* list_del_tail(__list_node_t *src)
{
	__list_node_t *cur = src;
	if (src == NULL) {
		return NULL;
	}

	if (src->next == NULL) {
		if (src->prev == NULL){
			return NULL;
		} else {
			src = src->prev;
			cur = src->prev;
			src->prev = NULL;
			return cur;
		}
	}

	while (src->next != NULL) {
		src = src->next;
	}

	cur = src;
	src = src->prev;
	src->next = NULL;

	return cur;
}

__list_node_t* list_del_head(__list_node_t *src)
{
	__list_node_t *cur = src;
	if (src == NULL) {
		return NULL;
	}

	if (src->prev == NULL) {
		if (src->next == NULL){
			return NULL;
		} else {
			src = src->next;
			cur = src->next;
			src->prev = NULL;
			return cur;
		}
	}

	while (src->prev != NULL) {
		src = src->prev;
	}

	cur = src;
	src = src->next;
	src->prev = NULL;

	return cur;
}

void list_del(__list_node_t *src, __list_node_t *ptr)
{
	__list_node_t *cur = src;

	if ((src == NULL) || (ptr == NULL)) {
		return ;
	}
	
	while (src->next != NULL) {
		src = src->next;
		if (src == ptr) {
			cur = src;
			src = src->prev;
			src->next = cur->next;
			cur->prev = src;
			break;
		}
	}
}


/* ------------------------------------------------------------------------------------------------------------------ */

#endif /* SW_SOFTTIMER_CONFIG */