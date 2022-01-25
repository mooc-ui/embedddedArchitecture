
#include "doubleLink.h"
#include <stdio.h>
#include <time.h>

/* 定义链表根节点 */
struct xLIST List_Test;
/* 定义节点 */
struct xLIST_ITEM List_Item1;
struct xLIST_ITEM List_Item2;
struct xLIST_ITEM List_Item3;

typedef struct stEvtBuffer
{
    uint16_t	evt;//事件类型(对应一个注册函数)
    void* payload;//对应注册函数的参数
}stEvtBuffer_t;

typedef struct qSportQueue {
    struct xLIST_ITEM currentNode;
    void* buffer;//type is stEvtBuffer
}qSportQueue_t;

void delay_ms(uint32_t ms)
{
    while (ms--) {

    }
}

typedef struct tm systemTime_t;

systemTime_t getSystemTime(void)
{
    struct tm t;   //tm结构指针
    time_t now;  //声明time_t类型变量
    time(&now);      //获取系统日期和时间
    localtime_s(&t, &now);   //获取当地日期和时间
}

int main()
{
    systemTime_t mTime;

    struct tm t;   //tm结构指针
    time_t now;  //声明time_t类型变量
    time(&now);      //获取系统日期和时间
    localtime_s(&t, &now);   //获取当地日期和时间
    uint32_t lastTime = 0;

    /* 链表根节点初始化 */
    vListInitialise(&List_Test);
    /* 节点 1 初始化 */
    vListInitialiseItem(&List_Item1);
    List_Item1.xItemValue = 1;
    /* 节点 2 初始化 */
    vListInitialiseItem(&List_Item2);
    List_Item2.xItemValue = 2;
    /* 节点 3 初始化 */
    vListInitialiseItem(&List_Item3);
    List_Item3.xItemValue = 3;
    /* 将节点插入链表，按照升序排列 */
    vListInsert(&List_Test, &List_Item2);
    vListInsert(&List_Test, &List_Item1);
    vListInsert(&List_Test, &List_Item3);

    printf("秒：%d\n", t.tm_sec);
    while (1)
    {
        time(&now);      //获取系统日期和时间
        localtime_s(&t, &now);   //获取当地日期和时间
        
        if (t.tm_sec%3 == 2 && lastTime != t.tm_sec) {
            lastTime = t.tm_sec;
            printf("current time %d\n", t.tm_sec);
        }
    }
	
}
