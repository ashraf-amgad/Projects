/*
 * FSM_Tank_level.c
 *
 * Created: 9/16/2019 4:43:11 PM
 *  Author: Louda
 */ 

#include "DIO_driver/DIO_int.h"
#include <util/delay.h>


int main(void)
{
	u8 counter = 0;   // counter to indicate pin_number 
	
	DIO_voidinit();

	DIO_DDRB = 0x00;
	DIO_PORTB = 0xff;
	
    while(1)
    {
		
			if (DIO_u8ReadPinVal(DIO_Pin10) == DIO_LOW)
			{
				 if(DIO_u8ReadPinVal(DIO_Pin8) == DIO_LOW )
				 {
					 DIO_u8SetPin(counter);
					 while(DIO_u8ReadPinVal(DIO_Pin8) == DIO_LOW);
			 
					 if(counter < 7)		// max pin_num that our leds connect on is 3 (pin0 ,pin1 ,pin2 ,pin3)
						counter++;
				 }
		 
				 else if(DIO_u8ReadPinVal(DIO_Pin9) == DIO_LOW)
				 {
					 DIO_u8ClrPin(counter);
					 while(DIO_u8ReadPinVal(DIO_Pin9) == DIO_LOW);
					 
					 if(counter > 0)
						counter--;
				 }
			
			}
				
			if (DIO_u8ReadPinVal(DIO_Pin2) == DIO_LOW )   // if led of level_2 is off then turn on empty_led
			 {
				DIO_u8SetPin(DIO_Pin16);
				DIO_u8ClrPin(DIO_Pin17);
			 }			
				
			 else if (DIO_PORTA == 0xff )   // if led of level_4 is on then turn on Full_led
			 {
				DIO_u8ClrPin(DIO_Pin16);
				DIO_u8SetPin(DIO_Pin17);
			 }	
		 
			 else 
			 {
				 DIO_u8ClrPin(DIO_Pin16);
				 DIO_u8ClrPin(DIO_Pin17);
			 }			 
    
	}		 
	
	return 0; 
}