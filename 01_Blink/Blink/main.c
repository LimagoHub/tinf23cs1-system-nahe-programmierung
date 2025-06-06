/*
 * Blink.c
 *
 * Created: 05.02.2018 18:54:38
 * Author : Joachim
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


void setup()
{
	
	// Data Direction Register
	DDRB  |= (1 << DDB5) ; // PB5 wird zum Ausgang
	
	PORTB |= 1 << PORTB5;
	
}

void loop()
{
	
	PORTB |=1 <<PORTB5;
	_delay_ms(500);
	
	
	PORTB &= ~(1 <<PORTB5);
	_delay_ms(500);
}

int main(void)
{
	
	setup();

	
	
    while (1)
    {
		loop();
	    
	    
    }
}

