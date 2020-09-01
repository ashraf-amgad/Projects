/*
 * Quad_7seg.c
 *
 * Created: 3/13/2020 2:57:25 PM
 *  Author: Louda
 */ 


#include "Quad_7seg.h"


static void Quad_7seg_Seg_Display(u8 display_Digit);

void Quad_7seg_Init(void)
{
	
	SET_BITS(Quad_7SEG_PINS_DIRECTION_REG ,Quad_7SEG_A | Quad_7SEG_B | Quad_7SEG_C | Quad_7SEG_D);
	SET_BITS(Quad_7SEG_EN_PINS_DIRECTION_REG ,Quad_7SEG_SEG_1_EN | Quad_7SEG_SEG_2_EN | Quad_7SEG_SEG_3_EN | Quad_7SEG_SEG_4_EN);
	CLR_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_SEG_1_EN | Quad_7SEG_SEG_2_EN | Quad_7SEG_SEG_3_EN | Quad_7SEG_SEG_4_EN);
		
}


void Quad_7seg_Num2ArrayOfDigits(u16 Display_num ,u8* ArrayOfDigits)
{
	static u16 reminder = 0;
	
	ArrayOfDigits[0] = (Display_num % 10);
	reminder = (Display_num / 10); 
	ArrayOfDigits[1] = (reminder % 10);
	reminder = (reminder / 10); 
	ArrayOfDigits[2] = (reminder % 10);
	reminder = (reminder / 10);
	ArrayOfDigits[3] = (reminder % 10);
	
}



void Quad_7seg_Display(u8 Seg_Num , u8 Display_Digit)
{
	static u8 seg_counter = 0;	
	
	SET_BITS(Quad_7SEG_PINS_DIRECTION_REG ,Quad_7SEG_A | Quad_7SEG_B | Quad_7SEG_C | Quad_7SEG_D);
	switch (Seg_Num)
	{
		case (Quad_7SEG_SEG_1):
			CLR_BITS(Quad_7SEG_EN_PINS_OUTPUT_REG ,Quad_7SEG_SEG_1_EN);
			SET_BITS(Quad_7SEG_EN_PINS_OUTPUT_REG ,Quad_7SEG_SEG_2_EN | Quad_7SEG_SEG_3_EN | Quad_7SEG_SEG_4_EN);
		break;
		
		case (Quad_7SEG_SEG_2):
			CLR_BITS(Quad_7SEG_EN_PINS_OUTPUT_REG ,Quad_7SEG_SEG_2_EN);
			SET_BITS(Quad_7SEG_EN_PINS_OUTPUT_REG ,Quad_7SEG_SEG_1_EN | Quad_7SEG_SEG_3_EN | Quad_7SEG_SEG_4_EN);
		break;
		
		case (Quad_7SEG_SEG_3):
			CLR_BITS(Quad_7SEG_EN_PINS_OUTPUT_REG ,Quad_7SEG_SEG_3_EN);
			SET_BITS(Quad_7SEG_EN_PINS_OUTPUT_REG ,Quad_7SEG_SEG_1_EN | Quad_7SEG_SEG_2_EN | Quad_7SEG_SEG_4_EN);
		break;
		
		case (Quad_7SEG_SEG_4):
			CLR_BITS(Quad_7SEG_EN_PINS_OUTPUT_REG ,Quad_7SEG_SEG_4_EN);
			SET_BITS(Quad_7SEG_EN_PINS_OUTPUT_REG ,Quad_7SEG_SEG_1_EN | Quad_7SEG_SEG_2_EN | Quad_7SEG_SEG_3_EN);
		break;
	}
	
	Quad_7seg_Seg_Display(Display_Digit);
	
			
}




static void Quad_7seg_Seg_Display(u8 display_Digit)
{
	switch (display_Digit)
	{
		case (0):
		{
			CLR_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_A | Quad_7SEG_B | Quad_7SEG_C | Quad_7SEG_D);
			break;
		}
			
		case (1):
		{
			SET_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_A);
			CLR_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_B | Quad_7SEG_C | Quad_7SEG_D);
			break;
		}
		
		case (2):
		{
			SET_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_B);
			CLR_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_A | Quad_7SEG_C | Quad_7SEG_D);
			break;
		}
		
		case (3):
		{
			SET_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_A | Quad_7SEG_B);
			CLR_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_C | Quad_7SEG_D);
			break;
		}
		
		case (4):
		{
			SET_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_C);
			CLR_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_A | Quad_7SEG_B | Quad_7SEG_D);
			break;
		}
		
		case (5):
		{
			SET_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_A | Quad_7SEG_C);
			CLR_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_B | Quad_7SEG_D);
			break;
		}
		
		case (6):
		{
			SET_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_B | Quad_7SEG_C);
			CLR_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_A | Quad_7SEG_D);
			break;
		}
		
		case (7):
		{
			SET_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_A | Quad_7SEG_B | Quad_7SEG_C);
			CLR_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_D);
			break;
		}
		
		case (8):
		{
			SET_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_D);
			CLR_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_A | Quad_7SEG_B | Quad_7SEG_C);
			break;
		}
		
		case (9):
		{
			SET_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_A | Quad_7SEG_D);
			CLR_BITS(Quad_7SEG_PINS_OUTPUT_REG ,Quad_7SEG_B | Quad_7SEG_C);	
			break;
		}
		
		default :
			/* do no thing */
		break;
	}
	
}



void Quad_7seg_TurnOff(void)
{
	SET_BITS(Quad_7SEG_EN_PINS_OUTPUT_REG ,Quad_7SEG_SEG_1_EN | Quad_7SEG_SEG_2_EN | Quad_7SEG_SEG_3_EN | Quad_7SEG_SEG_4_EN);		
}