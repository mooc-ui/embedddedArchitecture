
#ifndef __DOUBLE_LINK_H__
#define __DOUBLE_LINK_H__


#include "stdint.h"
#include "stddef.h"
/* 数据类型重定义 */
#define portCHAR char
#define portFLOAT float
#define portDOUBLE double
#define portLONG long
#define portSHORT short
#define portSTACK_TYPE uint32_t
#define portBASE_TYPE long
typedef portSTACK_TYPE StackType_t;
typedef long BaseType_t;
typedef unsigned long UBaseType_t;
#if( configUSE_16_BIT_TICKS == 1 )
typedef uint16_t TickType_t;
#define portMAX_DELAY ( TickType_t ) 0xffff
#else
typedef uint32_t TickType_t;
#define portMAX_DELAY ( TickType_t ) 0xffffffffUL
#endif


struct xLIST_ITEM
{
	TickType_t xItemValue; /* 辅助值，用于帮助节点做顺序排列 */
	struct xLIST_ITEM* pxNext; /* 指向链表下一个节点 */
	struct xLIST_ITEM* pxPrevious; /* 指向链表前一个节点 */
	void* pvOwner; /* 指向拥有该节点的内核对象，通常是 TCB */
	void* pvContainer; /* 指向该节点所在的链表 */
};
typedef struct xLIST_ITEM ListItem_t; /* 节点数据类型重定义 */



struct xMINI_LIST_ITEM
{
	TickType_t xItemValue; /* 辅助值，用于帮助节点做升序排列 */
	struct xLIST_ITEM* pxNext; /* 指向链表下一个节点 */
	struct xLIST_ITEM* pxPrevious; /* 指向链表前一个节点 */
};
typedef struct xMINI_LIST_ITEM MiniListItem_t; /* 精简节点数据类型重定义 */

typedef struct xLIST
{
	UBaseType_t uxNumberOfItems; /* 链表节点计数器 */
	ListItem_t* pxIndex; /* 链表节点索引指针 */
	MiniListItem_t xListEnd; /* 链表最后一个节点 */
} List_t;



#endif
