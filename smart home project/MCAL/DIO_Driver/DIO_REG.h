/*
 * DIO_REG.h
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_

/* Group A Registers */
#define DDRA_REG *((volatile u8*)0x3A)
#define PORTA_REG *((volatile u8*)0x3B)
#define PINA_REG *((volatile u8*)0x39)

/* Group B Registers */
#define DDRB_REG *((volatile u8*)0x37)
#define PORTB_REG *((volatile u8*)0x38)
#define PINB_REG *((volatile u8*)0x36)


/* Group C Registers */
#define DDRC_REG *((volatile u8*)0x34)
#define PORTC_REG *((volatile u8*)0x35)
#define PINC_REG *((volatile u8*)0x33)


/* Group D Registers */
#define DDRD_REG *((volatile u8*)0x31)
#define PORTD_REG *((volatile u8*)0x32)
#define PIND_REG *((volatile u8*)0x30)
#endif /* DIO_REG_H_ */
