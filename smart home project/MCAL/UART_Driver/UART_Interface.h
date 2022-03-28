/*
 * INTERFACE.h
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/*
 * Data Size Selection
 */
#define DATA_SIZE_MASK	0xF9
#define DATA_SIZE_SHIFT_VAL 1


#define DATA_SIZE_5_BIT 0x00
#define DATA_SIZE_6_BIT 0x01
#define DATA_SIZE_7_BIT 0x02
#define DATA_SIZE_8_BIT 0x03
#define DATA_SIZE_9_BIT	0x04
/*
 * to Select register to write
 */
#define REGISTER_SELECT_UCSRC u8(1)
#define REGISTER_SELECT_UBRRH u8(0)

/*
 * to Select mode of synchronization
 */
#define SYNC_MODE	1
#define ASYNC_MODE  0


/*
 * to Select Parity mode
 */
#define PARITY_MODE_MASK	0xCF
#define PARITY_MODE_SHIFT_VAL 4


#define PARITY_DISCONNECTED_MODE  	0x00
#define PARITY_EVEN_MODE 			0x02
#define PARITY_ODD_MODE 			0x03

/*
 * to Select the Number of Stop Bits
 */
#define STOP_BIT_1	0
#define STOP_BIT_2  1

/*
 * to select Clock Polarity
 */
#define TX_RISING_RX_FALLING 0
#define TX_FALLING_RX_RISING 1


#define ENABLE   1
#define DISABLE  0

/*
 *
 *
 *
 */

extern void UART_ReceiveString(u8 *str);

extern u8 UART_u8FrameErrorDetection();


extern u8 UART_u8DataOverRunDetection();


extern u8 UART_u8ParityErrorDetection();


extern void UART_VoidInit();


extern void UART_u8SetBaudRate(u8 Copy_u8BaudRateVal,u8 Copy_u8Freq);


extern u8 UART_u8RXRecieveData(void);


extern void UART_VoidTXSendData(u16 Copy_u16TxData);


extern u8 SendAddressUART_Callback(void (*ISR_UART)(void),u8 Copy_u8INT_Number);

extern void UART_VoidTxSendFloatNumber(f64 Copy_f64TxData);

extern void UART_VoidSendNumber(u32 Copy_u32Char);

extern u8 CountParameters(const u8 *String);

extern void log_print ( const u8 *StringOut ,...);

#endif /* PORT_INTERFACE_H_ */
