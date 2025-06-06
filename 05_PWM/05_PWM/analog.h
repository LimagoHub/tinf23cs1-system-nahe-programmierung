/*
 * analog.h
 *
 * Created: 30.05.2024 16:03:15
 *  Author: JoachimWagner
 */ 



#pragma once
#include <avr/io.h>

void analog_init();
uint16_t analog_read(uint8_t channel);