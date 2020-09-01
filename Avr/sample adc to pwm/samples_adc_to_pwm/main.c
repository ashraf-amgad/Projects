/*
 * samples_adc_to_pwm.c
 *
 * Created: 3/13/2020 2:16:05 AM
 *  Author: Louda
 */ 

#include "Dio_driver/Dio.h"
#include "ADC_driver/ADC.h"
#include "Timers_driver/timer.h"



static volatile u16 address = 0;
static volatile u8 state = 0;
static volatile u8 sample_state = 0;

#define sample_state_stored			0
#define sample_state_not_stored		1
#define sample_state_restored		2
#define sample_state_not_restored	3
#define sample_state_default_state	4

#define  rec		5
#define  play		6
#define  frq_sw		7
#define else_state	8





static volatile u16 rec_adc_value = 0;
static volatile f32 rec_adc_to_volt = 0;
	
void ADC_CH0_Check_Switches_Status_IRQ(void)
{
 	volatile u8 temp_1 = 0;
	temp_1 = ADC_GetData_8t();
	//DIO_PORTB = temp_1;
	
	switch (temp_1)
	{
		case (0x31):
			state = rec;
		break;
		
		case (0x51):
			state = play;
		break;
		
		case (0x8E):
			state = frq_sw;
		break;
		
		default:
			state = else_state;
		break;
	}
	
}


void TIM0_samples_IRQ(void)
{
	DIO_PORTA ^= 0x80;
						
	switch (state)
	{
		case (rec):
			/* move to memory */
		break;
		
		case (play):
			/* play from memory */
			Pwm_Volt2DutyCycle(TIMER_0 ,rec_adc_to_volt);	
		break;
		
		default:
		break;
	}
			
}



void ADC_CH1_recording_IRQ(void)
{
	
	rec_adc_value = ADC_GetData_16t();
	rec_adc_to_volt = ADC_Adc2Volt(rec_adc_value ,5);	
	DIO_PORTC ^= 0x01;

}



int main(void)
{

	Dio_Init();
	Timer_Init();
	ADC_Init();
	
	Timer_LoadOCR(TIMER_2 ,125);
	Timer_EnableInterrupt(TIMER_TIMSK_OCIE2);
	Timer_SetCompareMatch_ISR(TIMER_2 ,TIM0_samples_IRQ);
	
	
	ADC_SetupISR(ADC_CH_0 ,ADC_CH0_Check_Switches_Status_IRQ);
	ADC_SetupISR(ADC_CH_1 ,ADC_CH1_recording_IRQ);
	ADC_SetGlobalInt();
	ADC_StartConv();
	
    
	
	while(1)
	{
		
		
	}
	
	
	
}