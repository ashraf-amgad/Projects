/*
 * DIO_priv.h
 *
 * Created: 9/11/2019 8:57:29 AM
 *  Author: Louda
 */ 


#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

#include "DIO_conf.h"

#define DIO_IN  0
#define DIO_OUT 1



#define conc(x7 ,x6 ,x5 ,x4 ,x3 ,x2 ,x1 ,x0)           conchelper(x7 ,x6 ,x5 ,x4 ,x3 ,x2 ,x1 ,x0)
#define conchelper(x7 ,x6 ,x5 ,x4 ,x3 ,x2 ,x1 ,x0)     0b##x7##x6##x5##x4##x3##x2##x1##x0


#define DIO_u8PORTADIR          conc(DIO_Pin7_INILDIR ,DIO_Pin6_INILDIR ,DIO_Pin5_INILDIR ,DIO_Pin4_INILDIR ,DIO_Pin3_INILDIR ,DIO_Pin2_INILDIR ,DIO_Pin1_INILDIR ,DIO_Pin0_INILDIR)
#define DIO_u8PORTBDIR          conc(DIO_Pin15_INILDIR ,DIO_Pin14_INILDIR ,DIO_Pin13_INILDIR ,DIO_Pin12_INILDIR ,DIO_Pin11_INILDIR ,DIO_Pin10_INILDIR ,DIO_Pin9_INILDIR ,DIO_Pin8_INILDIR)
#define DIO_u8PORTCDIR          conc(DIO_Pin23_INILDIR ,DIO_Pin22_INILDIR ,DIO_Pin21_INILDIR ,DIO_Pin20_INILDIR ,DIO_Pin19_INILDIR ,DIO_Pin18_INILDIR ,DIO_Pin17_INILDIR ,DIO_Pin16_INILDIR)
#define DIO_u8PORTDDIR          conc(DIO_Pin31_INILDIR ,DIO_Pin30_INILDIR ,DIO_Pin29_INILDIR ,DIO_Pin28_INILDIR ,DIO_Pin27_INILDIR ,DIO_Pin26_INILDIR ,DIO_Pin25_INILDIR ,DIO_Pin24_INILDIR)






#define  DIO_PORTA     (*(volatile *)(0x3B))
#define  DIO_DDRA      (*(volatile *)(0x3A))
#define  DIO_PINA      (*(volatile *)(0x39))

#define  DIO_PORTB     (*(volatile *)(0x38))
#define  DIO_DDRB      (*(volatile *)(0x37))
#define  DIO_PINB      (*(volatile *)(0x36))



#define  DIO_PORTC     (*(volatile *)(0x35))
#define  DIO_DDRC      (*(volatile *)(0x34))
#define  DIO_PINC      (*(volatile *)(0x33))



#define  DIO_PORTD     (*(volatile *)(0x32))
#define  DIO_DDRD      (*(volatile *)(0x31))
#define  DIO_PIND      (*(volatile *)(0x30))



#endif /* DIO_PRIV_H_ */