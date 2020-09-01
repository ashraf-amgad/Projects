/*
 * sram128k.h
 *
 * Created: 3/11/2020 1:14:33 AM
 *  Author: Louda
 */ 


#ifndef _SRAM128K_H_
#define _SRAM128K_H_

#include "../Dio_driver/Dio.h"



#define SRAM_AD_OUTPUT_REG				DIO_PORTC
#define SRAM_AD_INPUT_REG				DIO_PINC
#define SRAM_AD_DIRECTION_REG			DIO_DDRC

#define SRAM_A8_A15_OUTPUT_REG			DIO_PORTD
#define SRAM_A8_A15_DIRECTION_REG		DIO_DDRD

#define SRAM_A16_PIN					DIO_PIN0
#define SRAM_LATCH_EN_PIN				DIO_PIN1
#define SRAM_A16_LATCH_OUTPUT_REG		DIO_PORTB
#define SRAM_A16_LATCH_DIRECTION_REG	DIO_DDRB



#define SRAM_WRITE_PIN					DIO_PIN6
#define SRAM_READ_PIN					DIO_PIN7
#define SRAM_READ_WRITE_OUTPUT_REG		DIO_PORTA
#define SRAM_READ_WRITE_DIRECTION_REG	DIO_DDRA





void Sram_Init(void);
void Sram_Write(u8 data , u32 address);
u8 Sram_ReadData(u32 address);
void Sram_Disable(void);

#endif /* _SRAM128K_H_ */