/*
 * LCD_priv.h
 *
 * Created: 9/21/2019 8:49:12 AM
 *  Author: Louda
 */ 


#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_

#define CMD_CLEAR_SCREEN			(0x01)
#define CMD_RETURN_HOME				(0x02)
#define CMD_SHIFT_DISPLAY_LEFT		(0x05)
#define CMD_SHIFT_DISPLAY_RIGHT		(0x07)
//#define CMD_SET_DICTION_LEFT		(0x04)
//#define CMD_SET_DICTION_RIGHT		(0x06)
#define CMD_CURRSOR_OFF				(0x0C)
#define CMD_CURRSOR_ON				(0x0E)
#define CMD_2LINE_4BITS				(0x28)
#define CMD_2LINE_8BITS				(0x38)
#define	CMD_SET_CURRSOR_POS			(0x80)		



#endif /* LCD_PRIV_H_ */