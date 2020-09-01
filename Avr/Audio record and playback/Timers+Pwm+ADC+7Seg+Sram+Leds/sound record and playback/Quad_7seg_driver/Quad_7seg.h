/*
 * quad_7seg.h
 *
 * Created: 9/17/2019 11:17:26 AM
 *  Author: Louda
 */ 


#ifndef QUAD_7SEG_H_
#define QUAD_7SEG_H_


#include "../Dio_driver/Dio.h"
#include "Quad_7seg_cfg.h"



#define  Quad_7SEG_SEG_1			(0U)
#define  Quad_7SEG_SEG_2			(1U)
#define  Quad_7SEG_SEG_3			(2U)
#define	 Quad_7SEG_SEG_4			(3U)


void Quad_7seg_Init(void);
void Quad_7seg_Num2ArrayOfDigits(u16 Display_num ,u8* ArrayOfDigits);
void Quad_7seg_Display(u8 Seg_Num , u8 Display_Digit);
void Quad_7seg_TurnOff(void);



#endif /* QUAD_7SEG_H_ */