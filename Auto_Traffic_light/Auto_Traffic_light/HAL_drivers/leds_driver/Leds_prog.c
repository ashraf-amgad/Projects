/*
 * Leds_prog.c
 *
 * Created: 9/17/2019 9:46:25 AM
 *  Author: Louda
 */ 
#include "Leds_int.h"

void Leds_voidinit(void)
{
	DIO_voidinit();
	DIO_DDRC  = 0b00011111;
	DIO_PORTC = 0x00;
}


void Leds_voidLedOn(u8 Led_num)
{
	DIO_u8SetPin(Led_num);
}

void Leds_voidLedOff(u8 Led_num)
{
	DIO_u8ClrPin(Led_num);
}