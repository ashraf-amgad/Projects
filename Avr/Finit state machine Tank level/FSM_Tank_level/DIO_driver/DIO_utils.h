/*
 * DIO_utils.h
 *
 * Created: 9/11/2019 8:56:41 AM
 *  Author: Louda
 */ 


#ifndef DIO_UTILS_H_
#define DIO_UTILS_H_


#define Set_Bit(reg,bit_num) (reg|=(1<<bit_num))
#define Clr_Bit(reg,bit_num) (reg&=(~(1<<bit_num)))
#define Tog_Bit(reg,bit_num) (reg^=(1<<bit_num))
#define Get_Bit(reg,bit_num) (reg&(1<<bit_num))
#define Set_Low_nible(reg)   (reg|0x0f)
#define Set_High_nible(reg)  (reg|0xf0) 
#define CLr_Low_nible(reg)   (reg&0xf0)
#define Clr_High_nible(reg)  (reg&0x0f)  
#define Get_Low_nible(reg)   (reg&0x0f)
#define Get_High_nible(reg)  (reg&0xf0) >> 4
   

#endif /* DIO_UTILS_H_ */