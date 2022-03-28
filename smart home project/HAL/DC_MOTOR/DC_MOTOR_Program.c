/*
 * DIO_Interface.c
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */

#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/CHECK_ERROR.h"
#include "DC_MOTOR_Config.h"
#include "DC_MOTOR_Interface.h"
#include "../../MCAL/DIO_Driver/DIO_REG.h"
#include "../../MCAL/DIO_Driver/DIO_Interface.h"





/*if you want to rotate the motor clockwise*/
void DC_MOTOR_VidRotateClockWise(void)
{
DIO_U8SetPinVal(DC_MOTOR_PORT_CONNECT,UNTI_CLOCKWISE_PIN,LOW);
DIO_U8SetPinVal(DC_MOTOR_PORT_CONNECT,CLOCKWISE_PIN,HIGH);

}

/*if you want to rotate the motor unti_clockwise*/
void DC_MOTOR_VidRotateUntiClockWise(void)
{
	DIO_U8SetPinVal(DC_MOTOR_PORT_CONNECT,CLOCKWISE_PIN,LOW);
	DIO_U8SetPinVal(DC_MOTOR_PORT_CONNECT,UNTI_CLOCKWISE_PIN,HIGH);
}

void DC_MOTOR_VidStop(void)
{
	DIO_U8SetPinVal(DC_MOTOR_PORT_CONNECT,CLOCKWISE_PIN,LOW);
	DIO_U8SetPinVal(DC_MOTOR_PORT_CONNECT,UNTI_CLOCKWISE_PIN,LOW);
}









