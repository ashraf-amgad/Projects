/*
 * Keypad_prog.c
 *
 * Created: 9/22/2019 9:54:28 AM
 *  Author: Louda
 */ 

#include "KeyPad_int.h"

void KeyPad_voidinit(void)
{
	DIO_voidInit();

	DIO_voidSetPort(KEYPAD_PORTDIR ,0x00);
	DIO_voidSetPort(KEYPAD_PORTVAL ,0xFF);	
}


u8 KeyPad_u8GetKey(void)
{
	u8 row = 0;
	u8 column = 0;
	u8 Key_Char = 0;
	u8 column_val = 0;
	
	for(row=0 ;row<KEYPAD_ROWNUM ;row++)
	{	
		
 		DIO_voidSetPort(KEYPAD_PORTDIR ,  (0b00010000 << row) );
 		DIO_voidSetPort(KEYPAD_PORTVAL ,  ~(0b00010000 << row));
		
 		for(column=0  ;column < KEYPAD_COLUMNNUM  ;column++)
 		{
			
 			if(KEYPAD_PORTVAL == DIO_PORTA)
 				column_val = DIO_u8ReadPinVal( DIO_PORTA_PIN0 + column );
 				
 			else if (KEYPAD_PORTVAL == DIO_PORTB)
 				column_val = DIO_u8ReadPinVal( DIO_PORTB_PIN0 + column );
 			
 			else if (KEYPAD_PORTVAL == DIO_PORTC)
 				column_val = DIO_u8ReadPinVal( DIO_PORTC_PIN0 + column );
 			
 			else //(KEYPAD_PORTVAL == DIO_PORTD)
 				column_val = DIO_u8ReadPinVal( DIO_PORTD_PIN0 + column );

			
			
 			if( column_val == LOW)
 			{
 				Key_Char = (KEYPAD_COLUMNNUM*row) + column + 1;
 				return ( KeyPad_u8GetKeychar( Key_Char ) );
 			}
						
		}
		
	}
	
	return KEYPAD_NOKEYPRESSED;
}


u8 KeyPad_u8GetKeychar(u8 num)
{
	switch (num)
	{
		case 1:
		{
			return '7';
			break;
		}
		
		case 2:
		{
			return '8';
			break;
		}
		
		case 3:
		{
			return '9';
			break;
		}
		
		case 4:
		{
			return '%';
			break;
		}
		
		case 5:
		{
			return '4';
			break;
		}
		
		case 6:
		{
			return '5';
			break;
		}
		
		case 7:
		{
			return '6';
			break;
		}
		
		case 8:
		{
			return 'x';
			break;
		}
		
		case 9:
		{
			return '1';
			break;
		}
		
		case 10:
		{
			return '2';
			break;
		}
		
		case 11:
		{
			return '3';
			break;
		}
		
		case 12:
		{
			return '-';
			break;
		}	
		
		case 13:
		{
			return '#';
			break;
		}
		
		case 14:
		{
			return '0';
			break;
		}
		
		case 15:
		{
			return '=';
			break;
		}
		
		case 16:
		{
			return '+';
			break;
		}
		
		default:
			return KEYPAD_NOKEYPRESSED;
			
	}
}