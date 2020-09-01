/*
 * SRAM128K.c
 *
 * Created: 3/11/2020 1:15:17 AM
 *  Author: Louda
 */ 


#include "sram128k.h"



void Sram_Init(void)
{
	SET_BITS(SRAM_READ_WRITE_DIRECTION_REG ,SRAM_READ_PIN | SRAM_WRITE_PIN);
	SET_BITS(SRAM_A16_LATCH_DIRECTION_REG ,SRAM_LATCH_EN_PIN);
	
	SET_BITS(SRAM_READ_WRITE_OUTPUT_REG ,SRAM_READ_PIN | SRAM_WRITE_PIN);
	CLR_BITS(SRAM_A16_LATCH_OUTPUT_REG ,SRAM_LATCH_EN_PIN);
	
	Set_Port(SRAM_A8_A15_DIRECTION_REG , 0xff);

}



void Sram_Write(u8 data , u32 address)
{
	
	/* set latch enable (enable latch) */
	SET_BITS(SRAM_A16_LATCH_OUTPUT_REG ,SRAM_LATCH_EN_PIN);
	
	/* output address */
	Set_Port(SRAM_AD_DIRECTION_REG , 0xff);
	Set_Port(SRAM_AD_OUTPUT_REG , (u8)address);
	Set_Port(SRAM_A8_A15_OUTPUT_REG , (u8)(address >> 8));
	
	if ((address >> 16) & 0x01)
	{
		SET_BITS(SRAM_A16_LATCH_OUTPUT_REG ,SRAM_A16_PIN);
	}
	
	else 
	{
		CLR_BITS(SRAM_A16_LATCH_OUTPUT_REG ,SRAM_A16_PIN);
	}
	
	
	/* clear latch enable (disable latch) */
	CLR_BITS(SRAM_A16_LATCH_OUTPUT_REG ,SRAM_LATCH_EN_PIN);
	
	
	/* start writing */
	CLR_BITS(SRAM_READ_WRITE_OUTPUT_REG ,SRAM_WRITE_PIN);
	
	/* output data */
	Set_Port(SRAM_AD_DIRECTION_REG , 0xff);
	Set_Port(SRAM_AD_OUTPUT_REG , data);
	
	
	/* stop writing */
	SET_BITS(SRAM_READ_WRITE_OUTPUT_REG ,SRAM_WRITE_PIN);			
}







u8 Sram_ReadData(u32 address)
{
	volatile u8 temp_data=0;
	
	/* set latch enable (enable latch) */
	SET_BITS(SRAM_A16_LATCH_OUTPUT_REG ,SRAM_LATCH_EN_PIN);
	
	/* output address */
	Set_Port(SRAM_AD_DIRECTION_REG , 0xff);
	Set_Port(SRAM_AD_OUTPUT_REG , (u8)(address));
	Set_Port(SRAM_A8_A15_OUTPUT_REG , (u8)(address >> 8));
	
	
	if ((address >> 16) & 0x01)
	{
		SET_BITS(SRAM_A16_LATCH_OUTPUT_REG ,SRAM_A16_PIN);
	}
	
	else 
	{
		CLR_BITS(SRAM_A16_LATCH_OUTPUT_REG ,SRAM_A16_PIN); 
	}
	
	
	
	/* clear latch enable (disable latch) */
	CLR_BITS(SRAM_A16_LATCH_OUTPUT_REG ,SRAM_LATCH_EN_PIN);
	Set_Port(SRAM_AD_DIRECTION_REG , 0x00);
	
	/* start reading */
	CLR_BITS(SRAM_READ_WRITE_OUTPUT_REG ,SRAM_READ_PIN);
	temp_data = SRAM_AD_INPUT_REG;
	
	/* stop reading */
	SET_BITS(SRAM_READ_WRITE_OUTPUT_REG ,SRAM_READ_PIN);
	return(temp_data);

}


void Sram_Disable(void)
{
	SET_BITS(SRAM_READ_WRITE_OUTPUT_REG ,SRAM_READ_PIN | SRAM_WRITE_PIN);
}









