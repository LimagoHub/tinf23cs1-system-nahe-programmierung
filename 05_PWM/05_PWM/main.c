/*
 * 05_PWM.c
 *
 * Created: 10.02.2018 14:50:01
 * Author : Joachim
 */ 

// this code sets up counter0 for an 8kHz PWM wave @ 16Mhz Clock
#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "analog.h"



int main(void)
{
	uint8_t weite = 0;
	uint8_t richtung = 1;
	DDRD |= (1 << DDD6);
	OCR0A = 64;
	// set PWM for 75% duty cycle

	TCCR0A |= (1 << COM0A1);
	// set none-inverting mode
	
	TCCR0A |=  (1 << WGM01)  | (1 << WGM00);
	// set fast PWM Mode
	
	TCCR0B |= (1 << CS00) | (1 << CS02) ;
	
	while (1)
	{
		weite += richtung;
		OCR0A = weite; 
		_delay_ms(20);
		
	}
}
