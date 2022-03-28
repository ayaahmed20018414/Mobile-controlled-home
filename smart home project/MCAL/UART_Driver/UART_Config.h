/*
 * PORT_Config.h
 *
 *  Created on: Sep 28, 2021
 *      Author: dell
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/*USART Control and Status Register A – UCSRA */
/*
 * Double the USART Transmission Speed
 */

/*Options:
 * 	DISABLE
 * 	ENABLE
 */
#define DOUBLE_BAUD_RATE   DISABLE

/*
 * Multi-processor Communication Mode
 */

/*Options:
 * 	DISABLE
 * 	ENABLE
 */
#define MULTI_COMMINICATION_MODE  DISABLE




/*======================================================================================================*/



/*USART Control and Status Register B – UCSRB*/

/*
 * RX Complete Interrupt Enable
 * TX Complete Interrupt Enable
 * USART Data Register Empty Interrupt Enable
 */

/*Options:
 * 	DISABLE
 * 	ENABLE
 */
#define RX_COMPLETE_INTERRUPT 	 DISABLE

#define TX_COMPLETE_INTERRUPT 	 DISABLE

#define TX_EMPTY_BUFER_INTERRUPT DISABLE


/*========================================================================================================*/

/*USART Control and Status Register C – UCSRC*/

/*
 * to Select the size of Data
 */


/*Options:
 *    DATA_SIZE_5_BIT
 *    DATA_SIZE_6_BIT
 *    DATA_SIZE_7_BIT
 *    DATA_SIZE_8_BIT
 *    DATA_SIZE_9_BIT
 */
#define DATA_SIZE   DATA_SIZE_8_BIT

/*
 * to Select Register to Write UCSRC or UBRRH
 */
/*
 * Options:
 * 		REGISTER_SELECT_UCSRC
 * 	    REGISTER_SELECT_UBRRH
 */
#define REGITER_SELECTION   REGISTER_SELECT_UCSRC



/*
 * To Select the Mode of Synchronization
 */
/*
 * Options:
 * 		SYNC_MODE
 *  	ASYNC_MODE
 */

#define SYNCHONIZATION_MODE ASYNC_MODE

/*
 * To Select the Parity Bit Mode
 */

/*
 * Options:
 *    PARITY_DISCONNECTED_MODE
 *    PARITY_EVEN_MODE
 *    PARITY_ODD_MODE
 */
#define PARITY_MODE PARITY_DISCONNECTED_MODE

/*
 * To Select The Number of Stop bits
 */
/*
 * Options:
 *   STOP_BIT_1
 *   STOP_BIT_2
 */

#define NUM_OF_STOP_BIT	STOP_BIT_1

/*
 * To Select The Polarity Of Sending and Recieving
 */

/*
 * Options:
 * 		TX_RISING_RX_FALLING
 * 		TX_FALLING_RX_RISING
 */
#define CLOCK_POLARITY TX_RISING_RX_FALLING

/**
 * select Baudrate from Data Sheet
 */
#define BAUD_RATE_VALE   51
#endif /* PORT_CONFIG_H_ */
