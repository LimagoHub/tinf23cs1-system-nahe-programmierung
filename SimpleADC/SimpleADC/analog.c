/*
 * analog.c
 *
 * Created: 17.09.2022 15:32:33
 *  Author: JoachimWagner
 */ 

#define F_CPU 16000000UL
#include "analog.h"
#include <util/delay.h>

void analog_init(){
	ADCSRA = (1 << ADEN);			/* Enable ADC */
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);			/* Set Prescaler */
	ADMUX = (1 << REFS0);	/*| (1 << ADLAR)* 8-bit Variante/;		/* Vref: Avcc, ADC channel: 0 */
}

uint16_t analog_read(uint8_t channel) {
	
	ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
	//single conversion mode
	ADCSRA |= (1<<ADSC);
	// wait until ADC conversion is complete
	while( ADCSRA & (1<<ADSC) );
	return ADCL |(ADCH << 8);
}




