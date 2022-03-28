/*
 * Led_init.h
 *
 *  Created on: Sep 19, 2021
 *      Author: dell
 */

#ifndef LED_INIT_H_
#define LED_INIT_H_

#define RT_OK (u8)0
#define RT_NOK (u8)1

enum LEDs{LED0,LED1,LED2,LED3,LED4,LED5,LED6,LED7};
#define LED_ON   (u8)1
#define LED_OFF  (u8)0



#endif /* LED_INIT_H_ */
u8 LED_U8ON_OFF(enum PORTS Copy_PortNo,enum LEDs Copy_LedNo,u8 Copy_u8ON_OR_OFF);
