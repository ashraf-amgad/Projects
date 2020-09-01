/*
 * LM35_driver.c
 *
 * Created: 1/18/2020 4:32:55 PM
 *  Author: Louda
 */ 

#include "ADC_driver/ADC_int.h"
#include "LCD_driver/LCD_int.h"



void ADC_CH0_func (void)
{
	LCD_voidGotoRC(0,0);
	LCD_voidSendCMD(CMD_CLEAR_SCREEN);
	
	u8 temp_2[4] = {0};
 	u16 temp_1 = ADC_u16GetData();
	 
 	LCD_u8Int2Str(temp_1 ,temp_2);
	LCD_voidDisStr(temp_2);
}


int main(void)
{
	LCD_voidinit();
	ADC_voidinit();
	
	ADC_voidSetup(ADC_CH_0 ,ADC_CH0_func);
	ADC_voidSetGlobalInt();
	ADC_voidStartConv();
	
	while(1);
	
}