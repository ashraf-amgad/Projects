/*
 * ADC_int.h
 *
 * Created: 9/27/2019 2:32:09 PM
 *  Author: Louda
 */ 


#ifndef ADC_INT_H_
#define ADC_INT_H_

#include "../DIO_driver/DIO_int.h"
#include "ADC_priv.h"
#include "../DIO_driver/types.h"
#include "ADC_confg.h"


void ADC_voidinit(void);
void ADC_voidStartConv(void);
void ADC_voidWaitConv(void);
void ADC_voidSetGlobalInt(void);
u16 ADC_u16GetData(void);
u8 ADC_u8GetData(void);
void ADC_voidSetup(u8 ADC_CHANNAL ,void (*ADC_INT_FUN)() );


#define  ADC_PORT			DIO_PORTA

#define ADC_ADMUX_MUX0		0
#define ADC_ADMUX_MUX1		1
#define ADC_ADMUX_MUX2		2
#define ADC_ADMUX_MUX3		3
#define ADC_ADMUX_MUX4		4
#define ADC_ADMUX_ADLAR		5
#define ADC_ADMUX_REFS0		6
#define ADC_ADMUX_REFS1		7


#define ADC_ADCSRA_ADPS0	0
#define ADC_ADCSRA_ADPS1	1
#define ADC_ADCSRA_ADPS2	2
#define ADC_ADCSRA_ADIE		3
#define ADC_ADCSRA_ADIF		4
#define ADC_ADCSRA_ADATE	5
#define ADC_ADCSRA_ADSC		6
#define ADC_ADCSRA_ADEN		7



#endif /* ADC_INT_H_ */