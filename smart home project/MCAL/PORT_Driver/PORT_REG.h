/*
 * DIO_REG.h
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */

#ifndef PORT_REG_H_
#define PORT_REG_H_

/* Group A Registers */
#define DDRA_REG *((volatile u8*)0x3A)
#define PORTA_REG_INITIAL *((volatile u8*)0x3B)

/* Group B Registers */
#define DDRB_REG *((volatile u8*)0x37)
#define PORTB_REG_INITIAL *((volatile u8*)0x38)

/* Group C Registers */
#define DDRC_REG *((volatile u8*)0x34)
#define PORTC_REG_INITIAL *((volatile u8*)0x35)

/* Group D Registers */
#define DDRD_REG *((volatile u8*)0x31)
#define PORTD_REG_INITIAL *((volatile u8*)0x32)

#endif /* PORT_REG_H_ */
