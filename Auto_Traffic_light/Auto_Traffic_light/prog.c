/*
 * prog.c
 *
 * Created: 9/20/2019 1:17:54 PM
 *  Author: Louda
 */ 

#include "int.h"
#include <util/delay.h>


void turnOn_green(void)
{
	counter_down_2 = 0;
	
	Leds_voidLedOn(Led_1);
	Leds_voidLedOff(Led_2);
	Leds_voidLedOff(Led_3);
	
	Leds_voidLedOff(Led_4);
	Leds_voidLedOn(Led_5);

	
	for(counter_down_1=9 ;counter_down_1>=0 ;counter_down_1--)
	{
		seg_voiddisplay(seg_1 , counter_down_1);
		
		while(counter_down_2 >= 0)
		{
				
			if(Switches_u8GetStatus(Switch_1 ,Switches_Pull_up) == Switches_Pressed)
				return;
								
			seg_voiddisplay(seg_2 , counter_down_2);
			_delay_ms(1000);
			counter_down_2--;
		}
		counter_down_2=0x09;
	}			
	
}

/*****************************************************/
/*		  ********************************	 		 */

void turnOn_yellow(void)
{
	counter_down_2 = 5;
	
	Leds_voidLedOff(Led_1);
	Leds_voidLedOff(Led_2);
	Leds_voidLedOff(Led_3);
	
	Leds_voidLedOff(Led_4);
	Leds_voidLedOn(Led_5);
	
	for(counter_down_1=1 ;counter_down_1>=0 ;counter_down_1--)
	{
		seg_voiddisplay(seg_1 , counter_down_1);
			
		while(counter_down_2 >= 0)
		{
			DIO_u8TogPin(Led_2);
			seg_voiddisplay(seg_2 , counter_down_2);
			_delay_ms(1000);
			counter_down_2--;
		}
					
		counter_down_2=0x09;
	}			
		
}

/*****************************************************/
/*		  ********************************	 		 */

void turnOn_red(void)
{
	counter_down_2 = 0;
	
	Leds_voidLedOff(Led_1);
	Leds_voidLedOff(Led_2);
	Leds_voidLedOn(Led_3);
	
	Leds_voidLedOn(Led_4);
	Leds_voidLedOff(Led_5);
	
	for(counter_down_1=6 ;counter_down_1>=0 ;counter_down_1--)
	{
			seg_voiddisplay(seg_1 , counter_down_1);
			
			while(counter_down_2 >= 0)
			{
				seg_voiddisplay(seg_2 , counter_down_2);
				_delay_ms(1000);
				counter_down_2--;
			}
				
			counter_down_2=0x09;
	}			

}
