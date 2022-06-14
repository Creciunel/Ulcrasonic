#include "StandartIO.h"

static FILE system_io = {0};
	
void std_io_init(void){
	serial_init(BAUT_RATE);
	fdev_setup_stream(&system_io, put_char, get_char, _FDEV_SETUP_RW);
	
	stdin = &system_io;
	stdout = &system_io;
}

int put_char(char c, FILE *stream){
	serial_write(c);
	return 0;
}

int get_char(FILE *stream){
	return serial_read();
}