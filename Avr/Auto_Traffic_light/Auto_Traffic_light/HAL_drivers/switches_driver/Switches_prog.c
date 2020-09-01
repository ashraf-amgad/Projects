/*
 * Switches_prog.c
 *
 * Created: 9/17/2019 7:18:27 AM
 *  Author: Louda
 */ 

#include "Switches_int.h"



void Switches_voidinit(void)
{
	DIO_voidinit();
	DIO_DDRC  = 0b01111111;
	DIO_PORTC = 0b10000000;
	
}


u8 Switches_u8GetStatus(u8 Switch_num ,u8 Status)
{
	if ( Status == Switches_Pull_down )
	{
		
		if ( DIO_u8ReadPinVal(Switch_num)  == DIO_HIGH)
			return(Switches_Pressed);
		
		else
			return(Switches_NotPressed);

	}
	
	else if ( Status == Switches_Pull_up )
	{
		
		if ( DIO_u8ReadPinVal(Switch_num)  == DIO_LOW)
			return(Switches_Pressed);
		
		else
			return(Switches_NotPressed);

	}
	
	
}


void Switches_voidTurnPullUp(u8 Switch_num)
{
		
	DIO_DDRA &= ~(1 << Switch_num); 
	DIO_u8SetPin(Switch_num);
	
}

void Switches_voidTurnPullDown(u8 Switch_num)
{
	
	DIO_DDRA &= ~(1 << Switch_num); 
	DIO_u8ClrPin(Switch_num);
	
}

