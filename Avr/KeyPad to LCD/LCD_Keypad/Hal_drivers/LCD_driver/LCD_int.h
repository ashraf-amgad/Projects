/*
 * LCD_int.h
 *
 * Created: 9/21/2019 8:49:25 AM
 *  Author: Louda
 */ 


#ifndef LCD_INT_H_
#define LCD_INT_H_

#include "../DIO_driver/DIO_int.h"
#include "LCD_priv.h"
#include "LCD_conf.h"
#include <util/delay.h>

void LCD_voidinit(void);
void LCD_voidSendCMD(u8 COMMAND);
void LCD_voidDisChar(u8 DATA);
void LCD_voidDisStr(u8* str);
void LCD_voidGotoRC(u8 row ,u8 column);
void LCD_voidDisStrRC(u8* str ,u8 row ,u8 column);




#endif /* LCD_INT_H_ */