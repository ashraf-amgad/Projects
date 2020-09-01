/*
 * drivers_int.h
 *
 * Created: 9/20/2019 6:09:12 AM
 *  Author: Louda
 */ 


#ifndef DRIVERS_INT_H_
#define DRIVERS_INT_H_


#include "HAL_drivers/leds_driver/Leds_int.h"
#include "HAL_drivers/seg_driver/seg_int.h"
#include "HAL_drivers/switches_driver/Switches_int.h"


extern s8 counter_down_1;
extern s8 counter_down_2;

void turnOn_green(void);
void turnOn_yellow(void);
void turnOn_red(void);


#endif /* DRIVERS_INT_H_ */