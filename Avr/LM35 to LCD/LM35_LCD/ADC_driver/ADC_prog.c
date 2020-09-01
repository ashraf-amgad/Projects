/************************************************************************
 * ADC_prog.c															*
 *																		*
 * Created: 9/27/2019 2:31:49 PM										*
 *  Author: Louda														*
 *																		*
 ************************************************************************/

#include "ADC_int.h"
#include <avr/interrupt.h>


/***************************************************/
				
			/***********************/
				
   static volatile void (* fptr_ch0)(void) = '\0';
//   static volatile void (* fptr_ch1)(void) = '\0';
//   static volatile void (* fptr_ch2)(void) = '\0';
//   static volatile void (* fptr_ch3)(void) = '\0';
//   static volatile void (* fptr_ch4)(void) = '\0';
//   static volatile void (* fptr_ch5)(void) = '\0';
//   static volatile void (* fptr_ch6)(void) = '\0';
//   static volatile void (* fptr_ch7)(void) = '\0';

/************************************************************************
 *																		*	
 *																		*
 ************************************************************************/

void ADC_voidinit(void)
{
	Set_Port(DIO_DDRA ,0x00);
/***************************************************/
				
			/***********************/
	
	Set_Bit(ADCSRA ,ADC_ADCSRA_ADEN);
	Clr_Bit(ADCSRA ,ADC_ADCSRA_ADATE);
	Set_Bit(ADCSRA ,ADC_ADCSRA_ADIE);
	
	
/***************************************************/
				
			/***********************/

	#if   (ADC_MAX_VOLT_REF == ADC_EXTERNAL_AREF)
		Clr_Bit(ADMUX ,ADC_ADMUX_REFS0);
		Clr_Bit(ADMUX ,ADC_ADMUX_REFS1);
		
	#elif (ADC_MAX_VOLT_REF == ADC_INTERNAL_AVCC)
		Set_Bit(ADMUX ,ADC_ADMUX_REFS0);
		Clr_Bit(ADMUX ,ADC_ADMUX_REFS1);
	
	#else					//     (ADC_MAX_VOLT_REF == ADC_INTERNAL_AVCC)
		Set_Bit(ADMUX ,ADC_ADMUX_REFS0);
		Set_Bit(ADMUX ,ADC_ADMUX_REFS1);
	
	#endif
	
/***************************************************/
				
			/***********************/
	
	#if (LEFT_AJUSTED_ON == 1)
		Set_Bit(ADMUX ,ADC_ADMUX_ADLAR);
	
	#else
		Clr_Bit(ADMUX ,ADC_ADMUX_ADLAR);
		
	#endif
	
/***************************************************/
				
			/***********************/
	
	#if   (DIVISION_FACTOR == ADC_DIV2)
		Clr_Bit(ADCSRA ,ADC_ADCSRA_ADPS0);
		Clr_Bit(ADCSRA ,ADC_ADCSRA_ADPS1);
		Clr_Bit(ADCSRA ,ADC_ADCSRA_ADPS2);
	
	#elif (DIVISION_FACTOR == ADC_DIV4)
		Clr_Bit(ADCSRA ,ADC_ADCSRA_ADPS0);
		Set_Bit(ADCSRA ,ADC_ADCSRA_ADPS1);
		Clr_Bit(ADCSRA ,ADC_ADCSRA_ADPS2);
		
	#elif (DIVISION_FACTOR == ADC_DIV8)
		Set_Bit(ADCSRA ,ADC_ADCSRA_ADPS0);
		Set_Bit(ADCSRA ,ADC_ADCSRA_ADPS1);
		Clr_Bit(ADCSRA ,ADC_ADCSRA_ADPS2);

	#elif (DIVISION_FACTOR == ADC_DIV16)
		Clr_Bit(ADCSRA ,ADC_ADCSRA_ADPS0);
		Clr_Bit(ADCSRA ,ADC_ADCSRA_ADPS1);
		Set_Bit(ADCSRA ,ADC_ADCSRA_ADPS2);
	
	#elif (DIVISION_FACTOR == ADC_DIV32)
		Set_Bit(ADCSRA ,ADC_ADCSRA_ADPS0);
		Clr_Bit(ADCSRA ,ADC_ADCSRA_ADPS1);
		Set_Bit(ADCSRA ,ADC_ADCSRA_ADPS2);
	
	#elif (DIVISION_FACTOR == ADC_DIV64)
		Clr_Bit(ADCSRA ,ADC_ADCSRA_ADPS0);
		Set_Bit(ADCSRA ,ADC_ADCSRA_ADPS1);
		Set_Bit(ADCSRA ,ADC_ADCSRA_ADPS2);
	
	#else					//	 (DIVISION_FACTOR == ADC_DIV128)
		Set_Bit(ADCSRA ,ADC_ADCSRA_ADPS0);
		Set_Bit(ADCSRA ,ADC_ADCSRA_ADPS1);
		Set_Bit(ADCSRA ,ADC_ADCSRA_ADPS2);
	
	#endif	
}

/************************************************************************
 *																		*	
 *																		*
 ************************************************************************/

void ADC_voidStartConv(void)
{
	Set_Bit(ADCSRA ,ADC_ADCSRA_ADSC);
} 


/************************************************************************
 *																		*	
 *																		*
 ************************************************************************/

void ADC_voidWaitConv(void)
{
	while( ADC_ADCSRA & (1<<ADC_ADCSRA_ADSC) );
	ADC_voidStartConv();
} 

/************************************************************************
 *																		*	
 *																		*
 ************************************************************************/

void ADC_voidSetGlobalInt(void)
{
	asm ("sei");
}


/********************************************************************************************************************************
 *	 When an ADC conversion is complete, the result is found in these two registers.											*
 *   When ADCL is read, the ADC Data Register is not updated until ADCH is read. Consequently,									*
 *   if the result is left adjusted and no more than 8-bit precision is required,												*
 *    it is sufficient to read ADCH. Otherwise, ADCL must be read first, then ADCH.												*
 *   The ADLAR bit in ADMUX, and the MUXn bits in ADMUX affect the way the result is read from									*
 *   the registers. If ADLAR is set, the result is left adjusted. If ADLAR is cleared (default), the result is right adjusted.	*																	*	
 *																																*
 ********************************************************************************************************************************/

u16 ADC_u16GetData(void)
{
	u8   temp_1 = 0;
	u16  temp_2 = 0;

	temp_1 = ADC_ADCL;					// because we should read ADCL first then read ADCH.
	#if (LEFT_AJUSTED_ON == 1)
		temp_2 = ( (ADC_ADCH << 2) | (temp_1 >> 6) );
		 return ( temp_2 );
	#else
		temp_2 = ( (ADC_ADCH << 8) | (temp_1) );
		 return ( temp_2 );	
	#endif 
}
/************************************************************************/
u8 ADC_u8GetData(void)
{
	u16 temp_1 = ADC_u16GetData();
	return(temp_1 >> 2);
}

/************************************************************************
 *																		*	
 *																		*
 ************************************************************************/

void ADC_voidSetup(u8 ADC_CHANNAL ,void (*ADC_INT_FUN)() )
{
	
	Clr_Bit(ADMUX ,ADC_ADMUX_MUX3);
	Clr_Bit(ADMUX ,ADC_ADMUX_MUX4);
	
	switch (ADC_CHANNAL)
	{
		case ADC_CH_0:
		{
			Clr_Bit(ADMUX ,ADC_ADMUX_MUX0);
			Clr_Bit(ADMUX ,ADC_ADMUX_MUX1);
			Clr_Bit(ADMUX ,ADC_ADMUX_MUX2);

			fptr_ch0 = ADC_INT_FUN;
			break;
		}
		
		case ADC_CH_1:
		{
			Set_Bit(ADMUX ,ADC_ADMUX_MUX0);
			Clr_Bit(ADMUX ,ADC_ADMUX_MUX1);
			Clr_Bit(ADMUX ,ADC_ADMUX_MUX2);
			
			/*fptr_ch1 = ADC_INT_FUN;*/
			break;
		}
		
		case ADC_CH_2:
		{
			Clr_Bit(ADMUX ,ADC_ADMUX_MUX0);
			Set_Bit(ADMUX ,ADC_ADMUX_MUX1);
			Clr_Bit(ADMUX ,ADC_ADMUX_MUX2);
			
			/*fptr_ch2 = ADC_INT_FUN;*/
			break;
		}
		
		case ADC_CH_3:
		{
			Set_Bit(ADMUX ,ADC_ADMUX_MUX0);
			Set_Bit(ADMUX ,ADC_ADMUX_MUX1);
			Clr_Bit(ADMUX ,ADC_ADMUX_MUX2);
			
			/*fptr_ch3 = ADC_INT_FUN;*/
			break;
		}
		
		case ADC_CH_4:
		{
			Clr_Bit(ADMUX ,ADC_ADMUX_MUX0);
			Clr_Bit(ADMUX ,ADC_ADMUX_MUX1);
			Set_Bit(ADMUX ,ADC_ADMUX_MUX2);
			
			/*fptr_ch4 = ADC_INT_FUN;*/
			break;
		}
		
		case ADC_CH_5:
		{
			Set_Bit(ADMUX ,ADC_ADMUX_MUX0);
			Clr_Bit(ADMUX ,ADC_ADMUX_MUX1);
			Set_Bit(ADMUX ,ADC_ADMUX_MUX2);
			
			/*fptr_ch5 = ADC_INT_FUN;*/
			break;
		}
		
		case ADC_CH_6:
		{
			Clr_Bit(ADMUX ,ADC_ADMUX_MUX0);
			Set_Bit(ADMUX ,ADC_ADMUX_MUX1);
			Set_Bit(ADMUX ,ADC_ADMUX_MUX2);
			
			/*fptr_ch6 = ADC_INT_FUN;*/
			break;
		}
		
		default :				//	ADC_CH_7
		{
			Set_Bit(ADMUX ,ADC_ADMUX_MUX0);
			Set_Bit(ADMUX ,ADC_ADMUX_MUX1);
			Set_Bit(ADMUX ,ADC_ADMUX_MUX2);
			
			/*fptr_ch7 = ADC_INT_FUN;*/
			break;
		}
	}
		
}


/************************************************************************
 *																		*	
 *																		*
 ************************************************************************/

ISR (ADC_vect)
{ 
	fptr_ch0(); 
	ADC_voidWaitConv();
}
