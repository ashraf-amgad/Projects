/*
 * seg_prog.c
 *
 * Created: 9/17/2019 11:17:16 AM
 *  Author: Louda
 */ 


#include "seg_int.h"

void seg_voidinit(void)
{
	DIO_DDRA = 0xff;
	DIO_u8ClrPin(seg1_En);
	DIO_u8ClrPin(seg2_En);
}


void seg_voiddisplay(u8 seg_num ,u8 display_num)
{
	
	if (seg_num == seg_1)
	{
		DIO_u8SetPin(seg1_En);
		
		if (display_num >= 0)
		{
				DIO_PORTA &= 0xf0;					// clear first 4 pins of portD that we use and keep others as they are.  
				DIO_PORTA |= display_num;			// high nible of our display number will always be low so it won't effect on high nible of portD   
		}
			
	}		
	
	else if (seg_num == seg_2)
	{
		DIO_u8SetPin(seg2_En);
		
		if (display_num >= 0)
		{
				DIO_PORTA &= 0x0f;					// clear first 4 pins of portD that we use and keep others as they are.  
				DIO_PORTA |= (display_num <<4);			// high nible of our display number will always be low so it won't effect on high nible of portD   
	
		}
		
	}		
	
}


void seg_voidturnoff(u8 seg_num)
{
	if(seg_num == seg_1)
		DIO_u8ClrPin(seg1_En);
		
	else if(seg_num == seg_2)
		DIO_u8ClrPin(seg2_En);
	
}