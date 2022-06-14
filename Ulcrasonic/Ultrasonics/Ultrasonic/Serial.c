#include "Serial.h"
#define F_CPU		8000000UL

void serial_init(uint32_t baud_rate){
	baud_rate = (uint16_t)((F_CPU / (16 * baud_rate))-1);//calcul viteza
	UBRRL = (uint8_t) baud_rate; //primii 8biti
	UBRRH = (baud_rate >> 8); //ultimii 8biti
	
	UCSRB |= (1<< RXEN) | (1<< TXEN);//setez TX si RX enable
	UCSRC |= (1<< URSEL) | (1 <<UCSZ1) |(1 <<UCSZ0);  //marimea caracter
}
void serial_write(const uint8_t data){
	//verificam daca sunt date, daca nu asteptam
	while(!(UCSRA&(1<<UDRE)));
	UDR = data;
}
uint8_t serial_read(void){
	//cand primim datele le returnam
	while(!(UCSRA&(1<<RXC)));
	return UDR;
}