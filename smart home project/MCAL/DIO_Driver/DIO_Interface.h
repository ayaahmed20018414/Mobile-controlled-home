/*
 * INTERFACE.h
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

//for Check Functions Status
#define RT_OK  (u8)0
#define RT_NOK (u8)1

//for PORTS Choice
enum PORTS{PORT_A,PORT_B,PORT_C,PORT_D};
/*#define PORT_A (u8)0
#define PORT_B (u8)1
#define PORT_C (u8)2
#define PORT_D (u8)3
*/
//for Pins Choice
enum PINS{PIN_0,PIN_1,PIN_2,PIN_3,PIN_4,PIN_5,PIN_6,PIN_7};

/*
#define PIN_0  (u8)0
#define PIN_1  (u8)1
#define PIN_2  (u8)2
#define PIN_3  (u8)3
#define PIN_4  (u8)4
#define PIN_5  (u8)5
#define PIN_6  (u8)6
#define PIN_7  (u8)7
*/
//for PINs Configuration

//for output Configuration
#define LOW  (u8)0
#define HIGH (u8)1

//for choose output or input (as in PORT_driver)
//#define OUTPUT (u8)1
//#define INPUT  (u8)0

//for input Configuration
#define PULL_UP   (u8)1
#define NORMAL_IN (u8)0

//for PORTS Configuration

//To choose Port INPUT or OUTPUTS (as in PORT_driver)
//#define FULL_INPUT  ((u8)0x00)
//#define FULL_OUTPUT ((u8)0xFF)

//At INPUT Choice
#define FULL_PULL_UP   ((u8)0xFF)
#define FULL_NORMAL_IN ((u8)0x00)

//At OUTPUT Choice
#define FULL_HIGH   ((u8)0xFF)
#define FULL_LOW    ((u8)0x00)




//u8 DIO_U8SetPortDir(u8 Copy_u8PortNo,u8  Copy_u8Dir);

u8 DIO_U8SetPortVal(u8 Copy_u8PortNo ,u8 Copy_Val);

u8 DIO_U8GetPortVal(u8 Copy_u8PortNo, u8* u8_Val);

//u8  DIO_U8SetPinDir(u8 Copy_u8PortNo,u8 Copy_u8PinNo,u8  Copy_u8Dir);

u8 DIO_U8SetPinVal(u8 Copy_u8PortNo,u8 Copy_u8PinNo,u8 Copy_Val);

u8 DIO_U8GetPinVal(u8 Copy_u8PortNo,u8 Copy_u8PinNo, u8* u8_Val);


#endif /* DIO_INTERFACE_H_ */
