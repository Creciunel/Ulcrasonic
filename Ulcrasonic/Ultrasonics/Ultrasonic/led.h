/*
 * led.h
 *
 * Created: 02.02.2022 12:16:42
 *  Author: Daniel
 */ 


#ifndef LED_H_
#define LED_H_

#include <stdint.h>

void led_init(volatile uint8_t*, const uint8_t);
void led_on(volatile uint8_t*, const uint8_t);
void led_off(volatile uint8_t*, const uint8_t);
void led_toogle(volatile uint8_t*, const uint8_t);


#endif /* LED_H_ */