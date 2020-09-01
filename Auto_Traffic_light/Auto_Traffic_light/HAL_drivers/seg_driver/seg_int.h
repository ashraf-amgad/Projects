/*
 * seg_int.h
 *
 * Created: 9/17/2019 11:17:26 AM
 *  Author: Louda
 */ 


#ifndef SEG_INT_H_
#define SEG_INT_H_


#include "../CAL_drivers/DIO_driver/DIO_int.h"
#include "seg_conf.h"

void seg_voidinit(void);
void seg_voiddisplay(u8 seg_num ,u8 display_num);
void seg_voidturnoff(u8 seg_num);


#define  seg1_pin1		DIO_Pin0
#define  seg1_pin2		DIO_Pin1
#define  seg1_pin3		DIO_Pin2
#define	 seg1_pin4		DIO_Pin3

#define  seg2_pin1		DIO_Pin4
#define  seg2_pin2		DIO_Pin5
#define  seg2_pin3		DIO_Pin6
#define	 seg2_pin4		DIO_Pin7

#define  seg1_En		DIO_Pin21	
#define  seg2_En		DIO_Pin22


#endif /* SEG_INT_H_ */