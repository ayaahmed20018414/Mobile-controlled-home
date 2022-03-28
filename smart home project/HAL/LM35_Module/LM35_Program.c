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

#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/CHECK_ERROR.h"
#include"../../MCAL/ADC_Driver/ADC_Config.h"
#include"../../MCAL/ADC_Driver/ADC_Private.h"
#include"../../MCAL/ADC_Driver/ADC_Interface.h"
#include "LM35_Interface.h"
const f32 ADC_STEP=4.8828125;

void LM35_VoidInit()
{
	ADC_VoidInit_PreBuild();
}

u16 LM35_u16GetTempretureWithUnit(u16 Copy_u16DigitalVoltage,Degree_Unit Copy_enumUnit)
{f32 Local_f32Temprature=(Copy_u16DigitalVoltage*ADC_STEP)/10.0;
 u16 Local_u8State=RT_OK;
	switch(Copy_enumUnit)
	{
	case Celsuis_Degree   :{return (u16) (Local_f32Temprature   )   ;break; }
	case Kilven_Degree    :{return (u16)(Local_f32Temprature+273.15);break; }
	case Fairenheit_Degree:{return (u16)(Local_f32Temprature*1.8+32);break; }
	default:{Local_u8State=RT_NOK;}
 	}
	return Local_u8State;
}

