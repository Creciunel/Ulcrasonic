#include <avr/io.h>
#include "led.h"
#include "Serial.h"
#include "StandartIO.h"


void T0delay()
{
	TCNT0 = 0x25;  		/* Load TCNT0*/
	TCCR0 = 0x01;  		/* Timer0, normal mode, no pre-scalar */
	
	while((TIFR&0x01)==0);  /* Wait for TOV0 to roll over */
	TCCR0 = 0;
	TIFR = 0x1;  		/* Clear TOV0 flag*/
}

int main(void)
{
    DDRB = 0xFF;		/* PORTB as output*/
    
    while(1)  		/* Repeat forever*/
    {
	    PORTB=0x55;
	    T0delay();  	/* Give some delay */
	    PORTB=0xAA;
	    T0delay();
    }
}

