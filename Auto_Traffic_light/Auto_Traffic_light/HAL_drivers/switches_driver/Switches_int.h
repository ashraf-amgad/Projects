/*
 * Switches_int.h
 *
 * Created: 9/17/2019 7:18:47 AM
 *  Author: Louda
 */ 


#ifndef SWITCHES_INT_H_
#define SWITCHES_INT_H_


#include "../CAL_drivers/DIO_driver/DIO_int.h"
#include "Switches_conf.h"


void Switches_voidinit(void);
u8 Switches_u8GetStatus(u8 Switch_num ,u8 Status);
void Switches_voidTurnPullUp(u8 Switch_num);
void Switches_voidTurnPullDown(u8 Switch_num);


#define Switch_1      DIO_Pin23

#endif /* SWITCHES_INT_H_ */