/*
 * KeyPad_int.h
 *
 * Created: 9/22/2019 9:55:12 AM
 *  Author: Louda
 */ 


#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

#include "../DIO_driver/DIO_int.h"
#include "KeyPad_confg.h"

void KeyPad_voidinit(void);
u8 KeyPad_u8GetKey(void);
u8 KeyPad_u8GetKeychar(u8 num);



#endif /* KEYPAD_INT_H_ */