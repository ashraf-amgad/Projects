/*
 * LCD_driver.c
 *
 * Created: 9/21/2019 8:48:41 AM
 *  Author: Louda
 */ 


#include "LCD_int.h"

		/***************************************/
		
void LCD_voidinit(void)
{
	DIO_voidInit();
	DIO_voidSetPort(LCD_PORT_DIR ,0xff);
	DIO_voidSetPinDir(LCD_EN);
	DIO_voidSetPinDir(LCD_R_W);
	DIO_voidSetPinDir(LCD_RS);
	
	LCD_voidSendCMD(CMD_RETURN_HOME);
	
	#if (LCD_MODE == 4)
		LCD_voidSendCMD(CMD_2LINE_4BITS);
	#else	
		LCD_voidSendCMD(CMD_2LINE_8BITS);
	#endif
	
	LCD_voidSendCMD(CMD_CURRSOR_OFF);
	LCD_voidSendCMD(CMD_CLEAR_SCREEN);
		
}

		/***************************************/
		
void LCD_voidSendCMD(u8 COMMAND)
{
	DIO_voidClrPin(LCD_RS);
	DIO_voidClrPin(LCD_R_W);
	_delay_ms(1);
	
	DIO_voidSetPin(LCD_EN);
	_delay_ms(1);
	
	#if (LCD_MODE == 4)
		DIO_voidSetPort(LCD_PORT_VAL , (COMMAND & 0xF0) );	
		_delay_ms(1);
		
		DIO_voidClrPin(LCD_EN);
		_delay_ms(1);
		DIO_voidSetPin(LCD_EN);
		_delay_ms(1);
		
	
		DIO_voidSetPort(LCD_PORT_VAL , ((COMMAND << 4) & 0xF0) );	
		_delay_ms(1);
					
		DIO_voidClrPin(LCD_EN);
		_delay_ms(1);
		
				
	#else
		DIO_voidSetPort(LCD_PORT_VAL ,COMMAND);
		_delay_ms(1);
		
		DIO_voidClrPin(LCD_EN);
		_delay_ms(1);
		
	#endif
}

		/***************************************/

void LCD_voidDisChar(u8 DATA)
{
	DIO_voidSetPin(LCD_RS);
	DIO_voidClrPin(LCD_R_W);
	_delay_ms(1);
	
	DIO_voidSetPin(LCD_EN);
	_delay_ms(1);
	
	
	#if (LCD_MODE == 4)
		DIO_voidSetPort(LCD_PORT_VAL , (DATA & 0xF0) );	
		_delay_ms(1);
		
		DIO_voidClrPin(LCD_EN);
		_delay_ms(1);
		DIO_voidSetPin(LCD_EN);
		_delay_ms(1);
		
		DIO_voidSetPort(LCD_PORT_VAL , ((DATA << 4) & 0xF0) );					
		_delay_ms(1);	
		
		DIO_voidClrPin(LCD_EN);
		_delay_ms(1);
				
	#else
		DIO_voidSetPort(LCD_PORT_VAL ,DATA);
		_delay_ms(1);
		
		DIO_voidClrPin(LCD_EN);
		_delay_ms(1);
		
	#endif
}


		/***************************************/
		
void LCD_voidDisStr(u8* str)
{
	u8 i=0;
	
	while(str[i] != 0)
	{
		LCD_voidDisChar(str[i]);
		i++;
	}
	
}

		/***************************************/
		
void LCD_voidGotoRC(u8 row ,u8 column)
{
		if(row == 0)
			LCD_voidSendCMD( CMD_SET_CURRSOR_POS | (row + column) );
		
		else
			LCD_voidSendCMD( CMD_SET_CURRSOR_POS | (column + 0x40) );
		
}

		/***************************************/
		
void LCD_voidDisStrRC(u8* str ,u8 row ,u8 column)
{
	LCD_voidGotoRC(row ,column);
	LCD_voidDisStr(str);
}


