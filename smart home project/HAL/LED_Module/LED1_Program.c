/*
 * LED1_interface.c
 *
 *  Created on: Sep 19, 2021
 *      Author: dell
 */
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include  "../../MCAL/DIO_Driver/DIO_REG.h"
#include  "../../MCAL/DIO_Driver/DIO_Interface.h"
#include "LED_Interface.h"

u8 LED_U8ON_OFF(enum PORTS Copy_PortNo,enum LEDs Copy_LedNo,u8 Copy_u8ON_OR_OFF)
{
	u8 Local_Status=RT_OK;
	if((Copy_LedNo<0)||(Copy_LedNo>7)||Copy_PortNo<0||Copy_PortNo>3)
	{
		Local_Status=RT_NOK;
	}
	else
	{
		if( Copy_u8ON_OR_OFF==LED_ON)
			{
			switch(Copy_PortNo)
					{
					case 0:{ SET_BIT(DDRA_REG,Copy_LedNo);SET_BIT(PORTA_REG,Copy_LedNo);break;}
					case 1:{ SET_BIT(DDRB_REG,Copy_LedNo);SET_BIT(PORTB_REG,Copy_LedNo);break;}
					case 2:{ SET_BIT(DDRC_REG,Copy_LedNo);SET_BIT(PORTC_REG,Copy_LedNo);break;}
					case 3:{ SET_BIT(DDRD_REG,Copy_LedNo); SET_BIT(PORTD_REG,Copy_LedNo);break;}

			         }

	        }
		else if( Copy_u8ON_OR_OFF==LED_OFF)
					{
					switch(Copy_PortNo)
							{
							case 0:{ CLR_BIT(PORTA_REG,Copy_LedNo);break;}
							case 1:{ CLR_BIT(PORTB_REG,Copy_LedNo);break;}
							case 2:{ CLR_BIT(PORTC_REG,Copy_LedNo);break;}
							case 3:{ CLR_BIT(PORTD_REG,Copy_LedNo);break;}

					         }

			        }



	}
	return Local_Status;

}
