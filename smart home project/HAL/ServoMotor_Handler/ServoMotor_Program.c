/*
 * LM35_Program.c
 *
 *  Created on: Oct 16, 2021
 *      Author: dell
 */


/*
 * LCD_Program.c
 *
 *  Created on: Sep 24, 2021
 *      Author: dell
 */
#include"util/delay.h"
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/CHECK_ERROR.h"
#include"../../MCAL/Timer_Driver/Timer_Config.h"
#include"../../MCAL/Timer_Driver/Timer_Private.h"
#include"../../MCAL/Timer_Driver/Timer_Interface.h"
#include "../ServoMotor_Handler/ServoMotor_Interface.h"

#define Angle_0_tickis 400
#define Angle_180_tickis 2600


void ServoMotor_VoidInit()
{
	TMR1_VoidInit_Prebuild();
}



void ServoMotor_u16SetAngle(u16 Copy_u16Adngle,u8 Copy_u8Channel )
{

if ( Copy_u8Channel==TIMER1_CHANNELB)
{
	OCR1B_REG=Copy_u16Adngle;
			  _delay_ms(40);
}

else if(Copy_u8Channel==TIMER1_CHANNELA)
{
	OCR1A_REG=Copy_u16Adngle;
			  _delay_ms(40);
}
}

