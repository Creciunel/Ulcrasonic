#ifndef SERIAL_H_
#define SERIAL_H_

#include <avr/io.h>

void serial_init(uint32_t);
uint8_t serial_read(void);
void serial_write(const uint8_t);

#endif /* SERIAL_H_ */