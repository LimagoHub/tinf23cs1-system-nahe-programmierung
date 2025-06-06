/*
 * EingabeMitPolling.c
 *
 * Created: 13.04.2020 15:53:45
 * Author : JoachimWagner
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



#define SET_BIT(BYTE,BIT) BYTE|=(1<<BIT)

int main(void)
{
    DDRD = 0b00001100;
	SET_BIT(DDRB, DDB5);
	PORTD = 0b00001100;
	PORTB &= ~(1 << PORTB5);
	volatile int8_t x;
    while (1) 
    {
				
		if(! (PIND & (1 << PIND2))) {
			PORTB |= (1 << PORTB5);
		}
		if(! (PIND & (1 << PIND3))) {
			PORTB &= ~(1 << PORTB5);
		}
		
    }
}

