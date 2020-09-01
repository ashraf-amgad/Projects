/*
 * LM35_driver.c
 *
 * Created: 1/18/2020 6:31:11 PM
 *  Author: Louda
 */ 

#include "LM35_driver/LM35_int.h"
#include "LCD_driver/LCD_int.h"


void LM35_0_func (void)
{
	LCD_voidGotoRC(0,0);
	LCD_voidSendCMD(CMD_CLEAR_SCREEN);
	
	u8 temp_2[4] = {0};
 	u16 temp_1 = LM35_u16Getdata();
	 
 	LCD_u8Int2Str(temp_1 ,temp_2);
	LCD_voidDisStr(temp_2);
}



int main(void)
{
	LCD_voidinit();
	LM35_voidinit();
	
	LM35_voidSetup(ADC_CH_0 ,LM35_0_func);
	ADC_voidSetGlobalInt();
	LM35_voidStart();
	
	
    while(1);
}