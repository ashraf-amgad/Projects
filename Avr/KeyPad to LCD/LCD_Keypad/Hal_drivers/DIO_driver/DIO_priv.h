/*
 * DIO_priv.h
 *
 * Created: 9/11/2019 8:57:29 AM
 *  Author: Louda
 */ 


#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_


#define HIGH		1
#define LOW			0

#define IN			0
#define OUT			1



#define conc(x7 ,x6 ,x5 ,x4 ,x3 ,x2 ,x1 ,x0)           conchelper(x7 ,x6 ,x5 ,x4 ,x3 ,x2 ,x1 ,x0)
#define conchelper(x7 ,x6 ,x5 ,x4 ,x3 ,x2 ,x1 ,x0)     0b##x7##x6##x5##x4##x3##x2##x1##x0


#define DIO_PORTA_INITDIR         conc(PORTA_PIN7_INITDIR ,PORTA_PIN6_INITDIR ,PORTA_PIN5_INITDIR ,PORTA_PIN4_INITDIR ,PORTA_PIN3_INITDIR ,PORTA_PIN2_INITDIR ,PORTA_PIN1_INITDIR ,PORTA_PIN0_INITDIR)
#define DIO_PORTB_INITDIR         conc(PORTB_PIN7_INITDIR ,PORTB_PIN6_INITDIR ,PORTB_PIN5_INITDIR ,PORTB_PIN4_INITDIR ,PORTB_PIN3_INITDIR ,PORTB_PIN2_INITDIR ,PORTB_PIN1_INITDIR ,PORTB_PIN0_INITDIR)
#define DIO_PORTC_INITDIR         conc(PORTC_PIN7_INITDIR ,PORTC_PIN6_INITDIR ,PORTC_PIN5_INITDIR ,PORTC_PIN4_INITDIR ,PORTC_PIN3_INITDIR ,PORTC_PIN2_INITDIR ,PORTC_PIN1_INITDIR ,PORTC_PIN0_INITDIR)
#define DIO_PORTD_INITDIR         conc(PORTD_PIN7_INITDIR ,PORTD_PIN6_INITDIR ,PORTD_PIN5_INITDIR ,PORTD_PIN4_INITDIR ,PORTD_PIN3_INITDIR ,PORTD_PIN2_INITDIR ,PORTD_PIN1_INITDIR ,PORTD_PIN0_INITDIR)

#define DIO_PORTA_INITVAL         conc(PORTA_PIN7_INITVAL ,PORTA_PIN6_INITVAL ,PORTA_PIN5_INITVAL ,PORTA_PIN4_INITVAL ,PORTA_PIN3_INITVAL ,PORTA_PIN2_INITVAL ,PORTA_PIN1_INITVAL ,PORTA_PIN0_INITVAL)
#define DIO_PORTB_INITVAL         conc(PORTB_PIN7_INITVAL ,PORTB_PIN6_INITVAL ,PORTB_PIN5_INITVAL ,PORTB_PIN4_INITVAL ,PORTB_PIN3_INITVAL ,PORTB_PIN2_INITVAL ,PORTB_PIN1_INITVAL ,PORTB_PIN0_INITVAL)
#define DIO_PORTC_INITVAL         conc(PORTC_PIN7_INITVAL ,PORTC_PIN6_INITVAL ,PORTC_PIN5_INITVAL ,PORTC_PIN4_INITVAL ,PORTC_PIN3_INITVAL ,PORTC_PIN2_INITVAL ,PORTC_PIN1_INITVAL ,PORTC_PIN0_INITVAL)
#define DIO_PORTD_INITVAL         conc(PORTD_PIN7_INITVAL ,PORTD_PIN6_INITVAL ,PORTD_PIN5_INITVAL ,PORTD_PIN4_INITVAL ,PORTD_PIN3_INITVAL ,PORTD_PIN2_INITVAL ,PORTD_PIN1_INITVAL ,PORTD_PIN0_INITVAL)




#define  DIO_PORTA     (*(volatile u8*)(0x3B))
#define  DIO_DDRA      (*(volatile u8*)(0x3A))
#define  DIO_PINA      (*(volatile u8*)(0x39))

#define  DIO_PORTB     (*(volatile u8*)(0x38))
#define  DIO_DDRB      (*(volatile u8*)(0x37))
#define  DIO_PINB      (*(volatile u8*)(0x36))



#define  DIO_PORTC     (*(volatile u8*)(0x35))
#define  DIO_DDRC      (*(volatile u8*)(0x34))
#define  DIO_PINC      (*(volatile u8*)(0x33))



#define  DIO_PORTD     (*(volatile u8*)(0x32))
#define  DIO_DDRD      (*(volatile u8*)(0x31))
#define  DIO_PIND      (*(volatile u8*)(0x30))



#endif /* DIO_PRIV_H_ */