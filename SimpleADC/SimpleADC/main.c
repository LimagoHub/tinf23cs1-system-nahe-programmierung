/*
 * SimpleADC.c
 *
 * Created: 06.06.2025 10:16:27
 * Author : JoachimWagner
 */ 
#define F_CPU 16000000UL 
#include <util/delay.h>
#include <avr/io.h>
#include "analog.h"
#include "uart.h"

#define CHANNEL_COUNT 2




int main(void)
{
    uart_init();
	analog_init();
	
	uint16_t chanelValues[CHANNEL_COUNT];
	
    while (1) 
    {
		for(int channel = 0; channel < CHANNEL_COUNT; channel ++){
			chanelValues[channel] = analog_read(channel);
			uart_write_string("Kanal ");
			uart_write_int(channel);
			uart_write_string(": ");
			uart_write_int(chanelValues[channel]);
			uart_write_string_nl("");
		}
		_delay_ms(100);
		
    }
}

