/*
 * samples_adc_to_pwm.c
 *
 * Created: 3/13/2020 2:16:05 AM
 *  Author: Louda
 */ 

#include "Dio_driver/Dio.h"
#include "ADC_driver/ADC.h"
#include "Timers_driver/timer.h"
#include "Quad_7seg_driver/Quad_7seg.h"
#include "128k_Sram_driver/sram128k.h"
#include "Leds_driver/Leds.h"

#define  rec		5
#define  play		6
#define  frq_sw		7
#define else_state	8
#define REC_SW_STATE_HIGH		(0x21+SW_STATE_ALLOWABLE_TOLERANCE) /* 0.65v*/
#define REC_SW_STATE_LOW		(0x21-SW_STATE_ALLOWABLE_TOLERANCE) /* 0.65v*/
#define PLAY_SW_STATE_HIGH		(0x40+SW_STATE_ALLOWABLE_TOLERANCE) /* 1.25v*/
#define PLAY_SW_STATE_LOW		(0x40-SW_STATE_ALLOWABLE_TOLERANCE) /* 1.25v*/
#define FRQ_SW_STATE_HIGH		(0x7D+SW_STATE_ALLOWABLE_TOLERANCE) /* 2.45v*/
#define FRQ_SW_STATE_LOW		(0x7D-SW_STATE_ALLOWABLE_TOLERANCE) /* 2.45v*/

#define Sram_Play_Last_Address	((u32) 0x1ffff)
#define Sram_Rec_Last_Address	((u32) 0x1ffff)

#define SW_STATE_ALLOWABLE_TOLERANCE	(10)

volatile u16 address = 0;
volatile u8 state = 0;
volatile u32 Sram_Rec_Address = 0;
volatile u32 Sram_Play_Address = 0;
volatile u8 Sram_adc_value = 0;
volatile f32 Sram_volt_value = 0;
volatile u16 rec_adc_value = 0;
//static u16 sram_delay = 0;
static u16 switches_state_delay = 0;
u16 seg_delay = 0;
u8 ArrayOfDigits[4] = {2 , 0 , 2 , 0};
u8 Seg_Digit_Index = 0;
u8 Quad_7SEG_SEG_counter = 0;


	
void ADC_CH0_Check_Switches_Status_IRQ(void)
{
 	volatile u8 switches_state = 0;
	switches_state_delay++;
	
	
 	if (switches_state_delay == 250)
 	{
		//DIO_PORTB ^= 0x04; 	
		switches_state = ADC_GetData_8t();
		
		if ( (switches_state <= REC_SW_STATE_HIGH) && (switches_state >= REC_SW_STATE_LOW) )
		{
			state = rec;
			Leds_LedOn(LED_REC);
			Leds_LedOff(LED_PLAY | LED_FREQ);
			Quad_7seg_TurnOff();
			Timer_Disable(TIMER_0);
		}
		
		else if ( (switches_state <= PLAY_SW_STATE_HIGH) && (switches_state >= PLAY_SW_STATE_LOW) )
		{
			state = play;
			Leds_LedOn(LED_PLAY);
			Leds_LedOff(LED_REC | LED_FREQ);
			Quad_7seg_TurnOff();
		}
		
		else if ( (switches_state <= FRQ_SW_STATE_HIGH) && (switches_state >= FRQ_SW_STATE_LOW) )
		{
			state = frq_sw;
			Leds_LedOn(LED_FREQ);
			Leds_LedOff(LED_PLAY | LED_REC);
			Sram_Disable();
			Timer_Disable(TIMER_0);
		}
		
		else 
		{
			state = else_state;
			Leds_LedOff(LED_FREQ | LED_PLAY | LED_REC);
			Quad_7seg_TurnOff();
			Sram_Disable();
			Timer_Disable(TIMER_0);
		}
		
		switches_state_delay = 0;	
	 }					
	
}


void TIM2_samples_IRQ(void)
{		
	//DIO_PORTB ^= 0x04;					
	switch (state)
	{
		case (rec):
// 			sram_delay++;
// 			if (sram_delay == 1)
// 			{
				if (Sram_Rec_Address == Sram_Rec_Last_Address)
				{
					Sram_Rec_Address = 0;
				}
				//DIO_PORTB ^= 0x04;
				/* move to memory */
				Sram_Write(rec_adc_value ,Sram_Rec_Address);
				Sram_Rec_Address++;
//				sram_delay=0;
//			}							
		break;
		
		case (play):
				//DIO_PORTB ^= 0x04;
				/* play from memory */
				if (Sram_Play_Address == Sram_Play_Last_Address)
				{
					Sram_Play_Address = 0;
				}
 				Sram_adc_value = Sram_ReadData(Sram_Play_Address);
 				Sram_volt_value = ADC_Adc2Volt(Sram_adc_value ,5);
				Timer_Enable(TIMER_0);
  				Pwm_Volt2DutyCycle(TIMER_0 ,Sram_volt_value);
				//Timer_LoadOCR(TIMER_0 ,Sram_adc_value);
				Sram_Play_Address++;						
		break;
		
		case (frq_sw):			
			seg_delay++;
			if (seg_delay == 1000)
			{
				/* display freq */
				if (Seg_Digit_Index > 3)
				{
					Seg_Digit_Index=0;
				}
				
				if (Quad_7SEG_SEG_counter > 3)
				{
					Quad_7SEG_SEG_counter=0;
				}
				//DIO_PORTB ^= 0x04;
				Quad_7seg_Display(Quad_7SEG_SEG_counter , ArrayOfDigits[Seg_Digit_Index]);
				Quad_7SEG_SEG_counter++;
				Seg_Digit_Index++;
				seg_delay=0;	
			}				
		break;
		
		default:
			
		break;
	}
			
}



void ADC_CH1_recording_IRQ(void)
{
	
	
	if (state == rec)
	{
		rec_adc_value = ADC_GetData_8t();	
	}
	

}



int main(void)
{
	
	Dio_Init();
	Timer_Init();
	ADC_Init();
	Quad_7seg_Init();
	Sram_Init();
	Leds_Init();
	
	
	Timer_LoadOCR(TIMER_2 ,125);
	Timer_EnableInterrupt(TIMER_TIMSK_OCIE2);
	Timer_SetCompareMatch_ISR(TIMER_2 ,TIM2_samples_IRQ);
	
	
	ADC_SetupISR(ADC_CH_0 ,ADC_CH0_Check_Switches_Status_IRQ);
	ADC_SetupISR(ADC_CH_1 ,ADC_CH1_recording_IRQ);
	ADC_SetGlobalInt();
	ADC_StartConv();
	
    
	
	while(1);
	
}