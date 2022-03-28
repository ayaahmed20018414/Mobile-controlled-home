/*
 * DIO_Interface.c
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */


#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/CHECK_ERROR.h"
#include "ADC_Config.h"
#include "ADC_Private.h"
#include "ADC_Interface.h"
#include "ADC_REG.h"

    /* ADCL|ADCH>>8 */
const f32 Step=4.8828125;
#define ADC_10_BIT_RESULT (*(volatile u16*)0x24)
static void(*ADC_VidCallBack_ISR_Funtion)(void)=NULL;
static u16*Global_pu16ADC_Reading=NULL;

#define IDIL (u8)1
#define BUZY (u8)0
u8 Global_u8State=IDIL;
void ADC_VoidInit_PreBuild(void)
{
	ADMUX_REG=ADMUX_INITAIL_VALUE;
	ADCSRA_REG=ADCSRA_REG_INITAIL_VALUE;
}

u8 ADC_u8AdjustmentSelect_Postbuild(u8 Copy_u8Justfication)
{
	u8 Local_u8Status=RT_OK;
if(Copy_u8Justfication==LEFT_JUSTFICATION)
	{
	 SET_BIT(ADMUX_REG,ADLAR);
	}
else if (Copy_u8Justfication==RIGHT_JUSTFICATION)
	{
	 CLR_BIT(ADMUX_REG,ADLAR);
	}
else
	{
	 Local_u8Status=RT_NOK;
	}

return Local_u8Status;

}

void ADC_VoidVrefSelect_Postbuild(u8 Copy_u8Vref)
{
	u8 Local_u8Temp=ADMUX_REG;
	Local_u8Temp&=SELECT_VREF_MASK;
	Local_u8Temp|=Copy_u8Vref;
	ADMUX_REG=Local_u8Temp;
}
void ADC_VoidPrescalerSelect_Postbuild(enum ADC_PRESACLEERS Copy_u8Prescaler)
{
	u8 Local_u8Temp=ADCSRA_REG;
	Local_u8Temp&=SELECT_PRESCALER_MASK;
	Local_u8Temp|=Copy_u8Prescaler;
	ADCSRA_REG=Local_u8Temp;
}

u8 ADC_u8ONO_OFFStateSelect_Postbuild(u8 Copy_u8ADC_State)
{
	u8 Local_u8Status=RT_OK;
	if(Copy_u8ADC_State==ENABLE)
		{
		 SET_BIT(ADCSRA_REG,ADEN);
		}
	else if (Copy_u8ADC_State==DISABLE)
		{
		 CLR_BIT(ADCSRA_REG,ADEN);
		}
	else
		{
		 Local_u8Status=RT_NOK;
		}

	return Local_u8Status;
}
u8 ADC_u8AutoTriggerEnable_Postbuild(u8 Copy_u8ADC_AutoTriggerEnable,u8 Copy_u8TriggerSource)
{
	u8 Local_u8Status=RT_OK;
	if(Copy_u8ADC_AutoTriggerEnable==ENABLE)
		{
		 SET_BIT(ADCSRA_REG,ADATE);
		 u8 Local_u8Temp=ADCSRA_REG;
		 	Local_u8Temp&=SELECT_AUTO_TRIGER_SOURSE_MASK;
		 	Local_u8Temp|=Copy_u8TriggerSource;
		 	ADCSRA_REG=Local_u8Temp;

		}
	else if (Copy_u8ADC_AutoTriggerEnable==DISABLE)
		{
		 CLR_BIT(ADCSRA_REG,ADATE);
		}
	else
		{
		 Local_u8Status=RT_NOK;
		}

	return Local_u8Status;
}




u8 ADC_u8GetDigitalValChannel(u8 Copy_u8Channel,u16 *Reading_Channel)
{
	u8 Local_u8Status=RT_OK;
	if(Global_u8State==IDIL)
	{
		Global_u8State=BUZY;
		u32 Local_u32Counter=0;
		u8 Local_u8Temp=ADMUX_REG;
		Local_u8Temp&=SELECT_ENDED_CHANNEL_MASK;
		Local_u8Temp|=Copy_u8Channel;
		ADMUX_REG=Local_u8Temp;
		SET_BIT(ADCSRA_REG,ADSC);

			if(GET_BIT(ADCSRA_REG,ADIE)==DISABLE)
			{
				while((GET_BIT(ADCSRA_REG,ADIF)!=1)&&(Local_u32Counter<TIME_OUT_WAITING))
				{
					Local_u32Counter++;
				}
				if(Local_u32Counter==TIME_OUT_WAITING)
				{
					/*return error status because the time defined in configuration is out*/
					Local_u8Status=RT_NOK;
				}
				else
				{
					SET_BIT(ADCSRA_REG,ADIF);

					if(Reading_Channel!=NULL)
					{
						if(GET_BIT(ADMUX_REG,ADLAR)==LEFT_JUSTFICATION)
						{
							*Reading_Channel= ADCH_REG;
						}
						else if (GET_BIT(ADMUX_REG,ADLAR)==RIGHT_JUSTFICATION)
						{
							*Reading_Channel=ADC_10_BIT_RESULT ;
						}
						Global_u8State=IDIL;
					}
					else
					{
						Local_u8Status=NULL_POINTER;
					}
				}


			}
	}
	else
	{
		Local_u8Status=BUSY_FUNC;
	}

return Local_u8Status;
}

u8 ADC_u8GetDigitalValChannelAsynchronus(u8 Copy_u8Channel,u16 *Reading_Channel,void(*ADC_Notifications)(void))
{
	u8 Local_u8Status=RT_OK;
	if(Global_u8State==IDIL)
	{

		u8 Local_u8Temp=ADMUX_REG;
			if(Reading_Channel!=NULL||ADC_Notifications!=NULL)
			{
				Global_u8State=BUZY;
				Local_u8Temp&=SELECT_ENDED_CHANNEL_MASK;
				Local_u8Temp|=Copy_u8Channel;
				ADMUX_REG=Local_u8Temp;
				ADC_VidCallBack_ISR_Funtion=ADC_Notifications;
				Global_pu16ADC_Reading=	Reading_Channel;

				SET_BIT(ADCSRA_REG,ADSC);
				SET_BIT(ADCSRA_REG,ADIE);

			}
			else
			{
				Local_u8Status=NULL_POINTER;
			}

	}
	else
	{
		return BUSY_FUNC;
	}



return Local_u8Status;
}


/*u8 SendAddress_Callback(void (*ISR_ADC)(void))
{ u8 Local_u8Status=RT_OK;
	if(ADC_VidCallBack_ISR_Funtion!=0)
	{
		ADC_VidCallBack_ISR_Funtion=ISR_ADC;
	}
	else
	{
		return NULL_POINTER;
	}
	return Local_u8Status;

}
*/
void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	if(GET_BIT(ADMUX_REG,ADLAR)==LEFT_JUSTFICATION)
	{
		*Global_pu16ADC_Reading= ADCH_REG;
	}
	else if (GET_BIT(ADMUX_REG,ADLAR)==RIGHT_JUSTFICATION)
	{
		*Global_pu16ADC_Reading=ADC_10_BIT_RESULT ;
	}

	Global_u8State=IDIL;
	ADC_VidCallBack_ISR_Funtion();
	CLR_BIT(ADCSRA_REG,ADIE);
}






