/*
 * uart.c
 *
 * Created: 06.06.2025 08:56:38
 *  Author: JoachimWagner
 */ 

#include "uart.h"
#include <stdlib.h>

void uart_init(){
	UBRR0H = (MYUBRR >> 8);
	UBRR0L = MYUBRR;
	
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);      // Enable receiver and transmitter
	
	
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);  // Set Frame 8 Datenbit 1 Stoppbit
}

uint8_t uart_read_char(){
	  while ( !(UCSR0A & (1 << RXC0)) )  ;     // Wait until data is received
	  return UDR0;
}

void uart_write_char(uint8_t charToSend){
	while ( !(UCSR0A & (1 << UDRE0)) ) {}     // Wait until buffer is empty
	UDR0 = charToSend;
}

void uart_write_string(uint8_t* messageToSend){
	while(*messageToSend)
		uart_write_char(*messageToSend++);
}
void uart_write_string_nl(uint8_t* messageToSend){
	uart_write_string(messageToSend);
	uart_write_string("\r\n");
}

void uart_write_int(int16_t integerToSend){
	char buffer[10];
	char * ptr = itoa(integerToSend, buffer, 10);
	uart_write_string(buffer);
}

void uart_write_double(double doubleToSend){
	char buffer[10];
	dtostrf(doubleToSend,5,2,buffer);
	uart_write_string(buffer);
}
