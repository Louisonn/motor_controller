#include "parser.h"


command_t parse_message(int8_t * message, size_t size)
{
	command_t command = {NONE, 0};
	order_e order;

	if(size == 0) return command;


	if (message[0] == '-' || message[0] >= '0'|| message[0] <= '9'){

	}



	int8_t sign = 1;
	int8_t result = 0;
	size_t i = 0;
	if (cmd[0] == '-') {
		sign = -1;
		i++;
	}
	for (; i < size; i++) {
		result = result * 10 + (cmd[i] - '0');
	}
	return sign * result;


}


int8_t parse_command(int8_t* cmd, size_t size) {
}
