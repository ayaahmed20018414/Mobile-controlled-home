/*
 * DIO_Interface.c
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */

#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GIE_REG.h"
#include "GIE_Interface.h"


void EXTI_VidEnableOrDisableGIE(u8 Copy_u8EN_DIS)
{
	if (Copy_u8EN_DIS==ENABLE)
		{
			SET_BIT(SREG_REG,SREG_I_BIT);

		}
	else if( Copy_u8EN_DIS==DISABLE)
		{
		    CLR_BIT(SREG_REG,SREG_I_BIT);
		}
}
