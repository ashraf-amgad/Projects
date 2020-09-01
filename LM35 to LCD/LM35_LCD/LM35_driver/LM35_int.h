/*
 * LM35_int.h
 *
 * Created: 10/18/2019 11:13:28 AM
 *  Author: Louda
 */ 


#ifndef LM35_INT_H_
#define LM35_INT_H_


#include "../DIO_driver/DIO_int.h"
#include "../ADC_driver/ADC_int.h"
#include "LM35_confg.h"


void LM35_voidinit(void);
u16 LM35_u16Getdata(void);
void LM35_voidSetup(u8 LM35_Num , void (*fptr)(void));
void LM35_voidStart(void);
u8 LM35_u8IsCritical(u16 Critical_Point);



#endif /* LM35_INT_H_ */