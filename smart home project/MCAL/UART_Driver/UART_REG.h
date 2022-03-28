/*
 * DIO_REG.h
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */

#ifndef UART_REG_H_
#define UART_REG_H_

/* Transmitter and Reciever Register
 *  (READ = Recieving)
 *  (WRITE=Transmitting)
 *     */
#define UDR_REG *((volatile u8*)0x2C)

#define UCSRA_REG *((volatile u8*)0x2B)

enum UCSRA_Register
	{
	UCSRA_MPCM,
	UCSRA_U2X ,
	UCSRA_PE  ,
	UCSRA_DOR ,
	UCSRA_FE  ,
	UCSRA_UDRE,
	UCSRA_TXC ,
	UCSRA_RXC

	};


/* Group B Registers */
#define UCSRB_REG *((volatile u8*)0x2A)

enum UCSRB_Register
	{
	UCSRB_TXB8  ,
	UCSRB_RXB8  ,
	UCSRB_UCSZ2 ,
	UCSRB_TXEN  ,
	UCSRB_RXEN  ,
	UCSRB_UDRIE ,
	UCSRB_TXCIE ,
	UCSRB_RXCIE ,


	};


#define UBRRL_REG *((volatile u8*)0x29)
#define UBRRH_REG *((volatile u8*)0x40)


#define UCSRC_REG *((volatile u8*)0x40)

enum UCSRC_Register
	{
	UCSRC_UCPOL ,
	UCSRC_UCSZ0 ,
	UCSRC_UCSZ1 ,
	UCSRC_USBS  ,
	UCSRC_UPM0  ,
	UCSRC_UPM1  ,
	UCSRC_UMSEL ,
	UCSRC_URSEL ,
	};



#endif /* PORT_REG_H_ */
