
#ifndef STANDARTIO_H_
#define STANDARTIO_H_

#include "Serial.h"
#include <stdio.h>

#define BAUT_RATE 9600

void std_io_init(void);
int put_char(char c, FILE *stream);
int get_char(FILE *stream);


#endif /* STANDARTIO_H_ */