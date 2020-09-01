/*
 * KeyPad_conf.h
 *
 * Created: 9/22/2019 9:54:48 AM
 *  Author: Louda
 */ 


#ifndef KEYPAD_CONF_H_
#define KEYPAD_CONF_H_

#define KEYPAD_NOKEYPRESSED		200
#define	KEYPAD_COLUMNNUM		4
#define	KEYPAD_ROWNUM			4



/**
in proteus
	bit_0	column_1
	bit_1	column_2
	bit_2	column_3
	bit_3	column_4
	bit_4	row_A
	bit_5	row_B
	bit_6	row_C
	bit_7	row_D
   */
#define KEYPAD_PORTVAL		DIO_PORTA 
#define KEYPAD_PORTDIR		DIO_DDRA


#endif /* KEYPAD_CONF_H_ */