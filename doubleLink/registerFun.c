#include "registerFun.h"
#include "doubleLink.h"


typedef struct _stEvtBuffer
{
	uint16_t	evt;//event ID
	void* payload;//callback function parameter
}stEvtBuffer;

typedef struct funcQueue {
	struct xLIST_ITEM queueElement;
	uint8_t priority;
	void* buffer;//store stEvtBuffer data struct[buffer = (stEvtBuffer *)&variable]
}funcQueue_t;

loopCallback_t lpcb[MAX_OPEAR_NUM];

static struct xLIST rootNode;
static struct xLIST_ITEM sysQueue;

void qsportQueueInit(void)
{
	vListInitialise(&rootNode);//root node init
	//
}

void qsportSendToQueue(funcQueue_t readyQueue)
{
	
	vListInitialiseItem(&readyQueue.queueElement);
}

void qsportReceiveFromQueue(void)
{
	//
}