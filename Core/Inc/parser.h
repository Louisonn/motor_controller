#ifndef __PARSER_H__
#define __PARSER_H__

#include "main.h"

typedef enum {
	NONE = 0,
	START,
	STOP,
	SET_SPEED
}order_e;

typedef struct{
	order_e order;
	int8_t value;
}command_t;

command_t parse_message(int8_t *, uint8_t);

#endif /* __PARSER_H__ */
