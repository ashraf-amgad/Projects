/*
 * DIO_prog.c
 *
 * Created: 9/11/2019 8:57:53 AM
 *  Author: Louda
 */ 

#include "DIO_priv.h"
#include "DIO_types.h"
#include "DIO_utils.h"
#include "DIO_int.h"


void DIO_voidinit(void)
{
	DIO_DDRA = DIO_u8PORTADIR;
	DIO_DDRB = DIO_u8PORTBDIR;
	DIO_DDRC = DIO_u8PORTCDIR;
	DIO_DDRD = DIO_u8PORTDDIR;	
}



u8 DIO_u8ReadPinVal(u8 pin_num)
{
	if(pin_num < 8)
		return ( Get_Bit(DIO_PINA ,pin_num) ); 
	else if (pin_num < 16)
		return ( Get_Bit(DIO_PINB ,pin_num-8) );
	else if (pin_num < 24)
		return ( Get_Bit (DIO_PINC ,pin_num-16) );
	else if (pin_num < 32)
		return ( Get_Bit (DIO_PIND , pin_num-24) );
}

u8 DIO_u8ReadPinDir(u8 pin_num)
{
	if(pin_num < 8)
		return ( Get_Bit(DIO_DDRA ,pin_num) ); 
	else if (pin_num < 16)
		return ( Get_Bit(DIO_DDRB ,pin_num-8) );
	else if (pin_num < 24)
		return ( Get_Bit(DIO_DDRC ,pin_num-16) );
	else if (pin_num < 32)
		return ( Get_Bit(DIO_DDRD , pin_num-24) );	
}

u8 DIO_u8SetPin(u8 pin_num)
{
	if(pin_num < 8)
		return ( Set_Bit(DIO_PORTA ,pin_num) ); 
	else if (pin_num < 16)
		return ( Set_Bit(DIO_PORTB ,pin_num-8) );
	else if (pin_num < 24)
		return ( Set_Bit(DIO_PORTC ,pin_num-16) );
	else if (pin_num < 32)
		return ( Set_Bit(DIO_PORTD ,pin_num-24) );	
}

u8 DIO_u8ClrPin(u8 pin_num)
{
	if(pin_num < 8)
		return ( Clr_Bit(DIO_PORTA ,pin_num) ); 
	else if (pin_num < 16)
		return ( Clr_Bit(DIO_PORTB ,pin_num-8) );
	else if (pin_num < 24)
		return ( Clr_Bit(DIO_PORTC ,pin_num-16) );
	else if (pin_num < 32)
		return ( Clr_Bit(DIO_PORTD , pin_num-24));
}

u8 DIO_u8TogPin(u8 pin_num)
{
	if(pin_num < 8)
		return ( Tog_Bit(DIO_PORTA ,pin_num) ); 
	else if (pin_num < 16)
		return ( Tog_Bit(DIO_PORTB ,pin_num-8) );
	else if (pin_num < 24)
		return ( Tog_Bit(DIO_PORTC ,pin_num-16) );
	else if (pin_num < 32)
		return ( Tog_Bit(DIO_PORTD , pin_num-24));
}

u8 DIO_u8GetPortlownible(u8 reg)
{
		return(Get_Low_nible(reg));
}


u8 DIO_u8GetPorthighnible(u8 reg)
{
		return(Get_High_nible(reg));
}

void DIO_voidSetPort(u8* reg)
{
	return ( *reg |=0xff );
}

void DIO_voidClrPort(u8* reg)
{
	return ( *reg &=0x00 );
}


