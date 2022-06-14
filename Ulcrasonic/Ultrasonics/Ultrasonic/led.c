/*
 * led.c
 *
 * Created: 02.02.2022 12:17:04
 *  Author: Daniel
 */ 

#include "led.h"

void led_init(volatile uint8_t* ddr, const uint8_t led_number)
{
	*ddr |= (1 << led_number); // declararea ca iesire shiftare l astanga de led_number ori umlimentand 1
}

void led_on(volatile uint8_t* port, const uint8_t led_number)
{
	*port |= (1 << led_number);
}

void led_off(volatile uint8_t* port, const uint8_t led_number)
{
	*port &= ~(1 << led_number);
}

void led_toogle(volatile uint8_t* port, const uint8_t led_number)
{
	*port ^= (1 << led_number);
}
