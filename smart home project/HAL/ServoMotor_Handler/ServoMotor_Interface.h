/*
 * LM35_Program.c
 *
 *  Created on: Oct 16, 2021
 *      Author: dell
 */

#ifndef HAL_ServoMottor_MODULE_INTERFACE
#define HAL_ServoMotor_MODULE_INTERFACE



#define TIMER1_CHANNELA 0
#define TIMER1_CHANNELB 1

/*to initialize the LM35 Which Initialize the Timer1S
 * input:No input
 * Output:No return
 */
extern void ServoMotor_VoidInit();

/*to set the angle of ServoMotor
 * input:value of Angle,Timer1_Channel
 * Output:no return
 */

extern void ServoMotor_u16SetAngle(u16 Copy_u16Adngle,u8 Copy_u8Channel );

#endif
