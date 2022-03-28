/*
 * DIO_Interface.c
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */


#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/CHECK_ERROR.h"
#include "External_Interrupt_Interface.h"
#include "External_Interrupt_REG.h"
//const void *NULL=0;



u8 EXTI_u8EnableOrDisableInterruptPin_Postbuild(u8 Copy_u8INTNum,u8 Copy_u8EN_DIS)
{
	u8 Local_u8Status=RT_OK;
if (Copy_u8EN_DIS==ENABLE)
	{
		SET_BIT(SREG_REG,SREG_I_BIT);
		switch(Copy_u8INTNum)
		{
		case INT0:{SET_BIT(GICR_REG,GICR_INT0); break;}
		case INT1:{SET_BIT(GICR_REG,GICR_INT1); break;}
		case INT2:{SET_BIT(GICR_REG,GICR_INT2); break;}
		default:{Local_u8Status=RT_NOK;}
		}
	}
else if( Copy_u8EN_DIS==DISABLE)
	{
		switch(Copy_u8INTNum)
		{
		case INT0:{CLR_BIT(GICR_REG,GICR_INT0); break;}
		case INT1:{CLR_BIT(GICR_REG,GICR_INT1); break;}
		case INT2:{CLR_BIT(GICR_REG,GICR_INT2); break;}
		default:{Local_u8Status=RT_NOK;}
		}
	}
else
	{
	  Local_u8Status=RT_NOK;
	}
return Local_u8Status;

}

void EXTI_voidEnableOrDisableInterruptPin_Prebuild()
{
/*Configuration for INT0*/
#if INT0_INITAIL_STATE==ENABLE
	{
		SET_BIT(SREG_REG,SREG_I_BIT);
		SET_BIT(GICR_REG,GICR_INT0);

	}
#elif( INT0_INITAIL_STATE==DISABLE)
	{
		CLR_BIT(GICR_REG,GICR_INT0);
	}
#endif



	/*Configuration for INT1*/
#if INT1_INITAIL_STATE==ENABLE
	{
		SET_BIT(SREG_REG,SREG_I_BIT);
		SET_BIT(GICR_REG,GICR_INT1);

	}
#elif( INT1_INITAIL_STATE==DISABLE)
	{
		CLR_BIT(GICR_REG,GICR_INT1);
	}
#endif



	/*Configuration for INT2*/
#if INT2_INITAIL_STATE==ENABLE
	{
		SET_BIT(SREG_REG,SREG_I_BIT);
		SET_BIT(GICR_REG,GICR_INT2);

	}
#elif( INT0_INITAIL_STATE==DISABLE)
	{
		CLR_BIT(GICR_REG,GICR_INT2);
	}
#endif


}

u8 EXTI_u8ControlSense_Postbuild(u8 Copy_u8INTNum,u8 Copy_u8Sense)
{
	u8 Local_u8Status=RT_OK;
	switch(Copy_u8Sense)
	{
		case LOW_LEVEL:
		{
			switch(Copy_u8INTNum)
				{
				case INT0:{MCUCR_REG|=(LOW_LEVEL_INT01<<MCUCR_ISC01_ISC00_SELECT); break;}
				case INT1:{MCUCR_REG|=(LOW_LEVEL_INT01<<MCUCR_ISC11_ISC10_SELECT); break;}
				default:{Local_u8Status=RT_NOK;}
				}
		break;
		}
		case LOGICAL_CHANGE:
		{
			switch(Copy_u8INTNum)
				{
				case INT0:{MCUCR_REG|=(LOGICAL_CHANGE_INT01<<MCUCR_ISC01_ISC00_SELECT); break;}
				case INT1:{MCUCR_REG|=(LOGICAL_CHANGE_INT01<<MCUCR_ISC11_ISC10_SELECT); break;}
				default:{Local_u8Status=RT_NOK;}
				}
			break;
		}
		case FALLING_EDGE:
		{
			switch(Copy_u8INTNum)
				{
				case INT0:{MCUCR_REG|=(FALLING_EDGE_INT01<<MCUCR_ISC01_ISC00_SELECT); break;}
				case INT1:{MCUCR_REG|=(FALLING_EDGE_INT01<<MCUCR_ISC11_ISC10_SELECT); break;}
				case INT2:{CLR_BIT(MCUCSR_REG,MCUCSR_ISC2_BIT); break;}
				default:{Local_u8Status=RT_NOK;}
				}
			break;
		}
		case RISING_EDGE:
		{
			switch(Copy_u8INTNum)
				{
				case INT0:{MCUCR_REG|=(RISING_EDGE_INT01<<MCUCR_ISC01_ISC00_SELECT); break;}
				case INT1:{MCUCR_REG|=(RISING_EDGE_INT01<<MCUCR_ISC11_ISC10_SELECT); break;}
				case INT2:{SET_BIT(MCUCSR_REG,MCUCSR_ISC2_BIT); break;}
				default:{Local_u8Status=RT_NOK;}
				}
			break;
		}
		default:{Local_u8Status=RT_NOK;}

	}
	return Local_u8Status;

}

void EXTI_VidControlSense_Prebuild(void)
{
	/*select Sense for INT0*/
#if INT0_SENSE==FALLING_EDGE_INT01
	{
		MCUCR_REG|=(FALLING_EDGE_INT01<<MCUCR_ISC01_ISC00_SELECT);

	}
#elif INT0_SENSE==RISING_EDGE_INT01
	{
		MCUCR_REG|=(RISING_EDGE_INT01<<MCUCR_ISC01_ISC00_SELECT);
	}
#elif INT0_SENSE==LOW_LEVEL_INT01
	{
		MCUCR_REG|=(LOW_LEVEL_INT01<<MCUCR_ISC01_ISC00_SELECT);
	}
#elif INT0_SENSE==LOGICAL_CHANGE_INT01
	{
		MCUCR_REG|=(LOGICAL_CHANGE_INT01<<MCUCR_ISC01_ISC00_SELECT);
	}
#endif



	/*select Sense for INT1*/
#if INT1_SENSE==FALLING_EDGE_INT01
	{
		MCUCR_REG|=(FALLING_EDGE_INT01<<MCUCR_ISC11_ISC10_SELECT);

	}
#elif INT1_SENSE==RISING_EDGE_INT01
	{
		MCUCR_REG|=(RISING_EDGE_INT01<<MCUCR_ISC11_ISC10_SELECT);
	}
#elif INT1_SENSE==LOW_LEVEL_INT01
	{
		MCUCR_REG|=(LOW_LEVEL_INT01<<MCUCR_ISC11_ISC10_SELECT);
	}
#elif INT1_SENSE==LOGICAL_CHANGE_INT01
	{
		MCUCR_REG|=(LOGICAL_CHANGE_INT01<<MCUCR_ISC11_ISC10_SELECT);
	}
#endif



	/*select Sense for INT2*/
#if INT2_SENSE==FALLING_EDGE_INT2
	{
		CLR_BIT(MCUCSR_REG,MCUCSR_ISC2_BIT);

	}
#elif INT2_SENSE==RISING_EDGE_INT2
	{
		SET_BIT(MCUCSR_REG,MCUCSR_ISC2_BIT);
	}
#endif

}




void (*EXTI_VidCallBack_ISR_Funtion)(void)=(void*)0;

u8 SendAddress_Callback(void (*ISR_INT0)(void))
{
	u8 Local_u8ErrorStatus=RT_OK;
	if(EXTI_VidCallBack_ISR_Funtion!=0)
	{
		EXTI_VidCallBack_ISR_Funtion=ISR_INT0;
	}
	else
	{

		Local_u8ErrorStatus=NULL_POINTER;
	}
	return Local_u8ErrorStatus;

}
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	EXTI_VidCallBack_ISR_Funtion();
}


