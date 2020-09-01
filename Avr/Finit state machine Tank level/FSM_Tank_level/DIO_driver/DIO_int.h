/*
 * DIO_int.h
 *
 * Created: 9/11/2019 9:18:22 AM
 *  Author: Louda
 */ 


#ifndef DIO_INT_H_
#define DIO_INT_H_

#include "DIO_priv.h"
#include "DIO_types.h"
#include "DIO_utils.h"
#include "DIO_conf.h"


void DIO_voidinit(void);
u8 DIO_u8ReadPinVal(u8 pin_num);
u8 DIO_u8ReadPinDir(u8 pin_num);
u8 DIO_u8SetPin(u8 pin_num);
u8 DIO_u8ClrPin(u8 pin_num);
u8 DIO_u8TogPin(u8 pin_num);
u8 DIO_u8GetPortlownible(u8 reg);
u8 DIO_u8GetPorthighnible(u8 reg);
void DIO_voidSetPort(u8* reg);
void DIO_voidClrPort(u8* reg);


#define DIO_Pin0   0
#define DIO_Pin1   1
#define DIO_Pin2   2
#define DIO_Pin3   3
#define DIO_Pin4   4
#define DIO_Pin5   5
#define DIO_Pin6   6
#define DIO_Pin7   7
#define DIO_Pin8   8
#define DIO_Pin9   9
#define DIO_Pin10  10
#define DIO_Pin11  11
#define DIO_Pin12  12
#define DIO_Pin13  13
#define DIO_Pin14  14
#define DIO_Pin15  15
#define DIO_Pin16  16
#define DIO_Pin17  17
#define DIO_Pin18  18
#define DIO_Pin19  19
#define DIO_Pin20  20
#define DIO_Pin21  21
#define DIO_Pin22  22
#define DIO_Pin23  23
#define DIO_Pin24  24
#define DIO_Pin25  25
#define DIO_Pin26  26
#define DIO_Pin27  27
#define DIO_Pin28  28
#define DIO_Pin29  29
#define DIO_Pin30  30
#define DIO_Pin31  31


#define DIO_PortA  0 
#define DIO_PortB  1
#define DIO_PortC  2
#define DIO_PortD  3

#define DIO_NumOfPorts     4
#define DIO_NumOfPortPins  8
#define DIO_NumOfAllPins   32




#endif /* DIO_INT_H_ */