#ifndef	__REGISTER_FUN__
#define __REGISTER_FUN__

#include <stdint.h>
#include <stdio.h>

typedef void (*userDefFcunc)(void * pText);//define function pointer type

typedef struct loopCallback {
	uint16_t eventId;
	userDefFcunc func;
}loopCallback_t;


enum {
	NONE_OP = 0,
	IDLE_OP,
	SYSTEM_OP,
	MAX_OPEAR_NUM,
};


#endif
