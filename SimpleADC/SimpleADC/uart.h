/*
 * uart.h
 *
 * Created: 06.06.2025 08:49:07
 *  Author: JoachimWagner
 */ 


#pragma once

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL                   // Clock Speed
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD -1

void uart_init();
uint8_t uart_read_char();
void uart_write_char(uint8_t charToSend);
void uart_write_string(uint8_t* messageToSend);
void uart_write_string_nl(uint8_t* messageToSend);
void uart_write_int(int16_t integerToSend);
void uart_write_double(double doubleToSend);