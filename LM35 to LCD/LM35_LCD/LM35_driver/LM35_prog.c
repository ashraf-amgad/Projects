/*
 * LM35_prog.c
 *
 * Created: 10/18/2019 11:13:12 AM
 *  Author: Louda
 */ 

#include "LM35_int.h"


void LM35_voidinit(void)
{
	ADC_voidinit();
	
}


u16 LM35_u16Getdata(void)
{
	u16 temp1 = 0;
	u16 temp2 = 0;
	
	temp1 = ADC_u16GetData();
	temp2 = ((f32)temp1/1023) * 250;	
	
	return ( temp2 );
}


void LM35_voidSetup(u8 LM35_Num , void (*fptr)(void) )
{
	ADC_voidSetup(LM35_Num , fptr);
}


void LM35_voidStart(void)
{
	ADC_voidStartConv();
}


u8 LM35_u8IsCritical(u16 Critical_Point)
{
	u16 temp1 = 0;
	u16 temp2 = 0;
	
	temp1 = ADC_u16GetData();
	temp2 = ((f32)temp1/1023) * 250;		
	
	if(temp2 >= Critical_Point)
		return 1;
	else
		return 0;
}

