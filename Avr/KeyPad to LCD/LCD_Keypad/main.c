/*
 * LCD_Keypad_driver.c
 *
 * Created: 12/16/2019 11:51:26 PM
 * Author : Louda
 */ 

#include "HAL_drivers/LCD_driver/LCD_int.h"
#include "HAL_drivers/KeyPad_driver/KeyPad_int.h"


int main(void)
{
    /* Replace with your application code */
	KeyPad_voidinit();
	LCD_voidinit();
	
	
    while (1) 
    {
		if(KeyPad_u8GetKey() == '0')
		{
			LCD_voidDisStr("Zero.");
			while(KeyPad_u8GetKey() == '0');
		}
		
    }
}

