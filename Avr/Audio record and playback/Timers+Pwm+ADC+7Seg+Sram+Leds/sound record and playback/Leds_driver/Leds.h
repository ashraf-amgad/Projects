/*
 * Leds.h
 *
 * Created: 9/17/2019 9:47:03 AM
 *  Author: Louda
 */ 


#ifndef LEDS_H_
#define LEDS_H_

#include "../Dio_driver/Dio.h"
#include "Leds_cfg.h"


#define  LED_ON		(1U)
#define  LED_OFF	(0U)


void Leds_Init(void);
void Leds_LedOn(u8 Led_num);
void Leds_LedOff(u8 Led_num);



#endif /* LEDS_H_ */