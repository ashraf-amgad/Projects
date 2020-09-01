/*
 * Leds.c
 *
 * Created: 9/17/2019 9:46:25 AM
 *  Author: Louda
 */ 
#include "Leds.h"


void Leds_Init(void)
{
	
	SET_BITS(LEDS_DIRECTION_PORT ,LED_REC | LED_PLAY | LED_FREQ);
	CLR_BITS(LEDS_OUTPUT_PORT ,LED_REC | LED_PLAY | LED_FREQ);
	
}



void Leds_LedOn(u8 Led_MASK)
{
	
	SET_BITS(LEDS_OUTPUT_PORT , Led_MASK);
	
}



void Leds_LedOff(u8 Led_MASK)
{
	CLR_BITS(LEDS_OUTPUT_PORT , Led_MASK);
}