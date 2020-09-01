/*
 * quad_7seg.h
 *
 * Created: 9/17/2019 11:17:40 AM
 *  Author: Louda
 */ 


#ifndef QUAD_7SEG_CFG_H_
#define QUAD_7SEG_CFG_H_




#define  Quad_7SEG_A			DIO_PIN0
#define  Quad_7SEG_B			DIO_PIN1
#define  Quad_7SEG_C			DIO_PIN2
#define	 Quad_7SEG_D			DIO_PIN3

#define	 Quad_7SEG_PINS_OUTPUT_REG			DIO_PORTC
#define	 Quad_7SEG_PINS_DIRECTION_REG		DIO_DDRC


#define  Quad_7SEG_SEG_1_EN		DIO_PIN4
#define  Quad_7SEG_SEG_2_EN		DIO_PIN5
#define  Quad_7SEG_SEG_3_EN		DIO_PIN6
#define  Quad_7SEG_SEG_4_EN		DIO_PIN7

#define	 Quad_7SEG_EN_PINS_OUTPUT_REG			DIO_PORTB
#define	 Quad_7SEG_EN_PINS_DIRECTION_REG		DIO_DDRB


#endif /* QUAD_7SEG_CFG_H_ */