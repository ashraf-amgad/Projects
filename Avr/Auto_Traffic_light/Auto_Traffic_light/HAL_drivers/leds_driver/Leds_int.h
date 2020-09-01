/*
 * Leds_int.h
 *
 * Created: 9/17/2019 9:47:03 AM
 *  Author: Louda
 */ 


#ifndef LEDS_INT_H_
#define LEDS_INT_H_

#include "../CAL_drivers/DIO_driver/DIO_int.h"
#include "Leds_conf.h"


void Leds_voidinit(void);
void Leds_voidLedOn(u8 Led_num);
void Leds_voidLedOff(u8 Led_num);



#define Led_1		DIO_Pin16
#define Led_2		DIO_Pin17
#define Led_3		DIO_Pin18
#define Led_4		DIO_Pin19
#define Led_5		DIO_Pin20



#endif /* LEDS_INT_H_ */