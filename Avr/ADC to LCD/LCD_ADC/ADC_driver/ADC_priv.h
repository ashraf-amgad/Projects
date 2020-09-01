/*
 * ADC_priv.h
 *
 * Created: 9/27/2019 2:32:00 PM
 *  Author: Louda
 */ 


#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

#define OFF				0
#define ON				1

#define ADC_DIV2		2
#define ADC_DIV4		3
#define ADC_DIV8		4
#define ADC_DIV16		5
#define ADC_DIV32		6
#define ADC_DIV64		7
#define ADC_DIV128		8

#define ADC_CH_0		9
#define ADC_CH_1		10
#define ADC_CH_2		11
#define ADC_CH_3		12
#define ADC_CH_4		13
#define ADC_CH_5		14
#define ADC_CH_6		15
#define ADC_CH_7		16


#define ADC_EXTERNAL_AREF	17
#define ADC_INTERNAL_AVCC	18			// using AVCC pin as VREF but you should use capacitor on pin AREF  //  AVCC with external capacitor at AREF pin
#define ADC_INTENAL_AREF	19			// Internal 2.56V Voltage Reference with external capacitor at AREF pin


#define ADC_ADMUX		(*(volatile u8*)(0x27))
#define ADC_ADCSRA		(*(volatile u8*)(0x26))
#define ADC_ADCH		(*(volatile u8*)(0x25))
#define ADC_ADCL		(*(volatile u8*)(0x24))
#define ADC_SFIOR		(*(volatile u8*)(0x50))

#endif /* ADC_PRIV_H_ */