/*
 * DIO_Interface.c
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */


#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/CHECK_ERROR.h"
#include "Timer_REG.h"
#include "Timer_Interface.h"
#include "Timer_Private.h"
#include "Timer_Config.h"


static void(*Timer_VidCallBack_ISR_Funtion[8])(void)={NULL};

void TMR0_VoidInit_Prebuild()
{
	TCCR0_REG &=WAVEFORM_TIMER0_MODE_MASK;
	TCCR0_REG |=TIMER0_OP_MODE;
	TCCR0_REG &=TIMER0_CTC_OUTPUT_MODES_MASK;
	TCCR0_REG |=TIMER0_OUTPUT_MODE;


#if TIMER0_OP_MODE==TIMER0_MODE_NORMAL
	{
			#if TIMER0_OVF_INT==ENABLE
				{
					SET_BIT(TIMSK_REG,TMR0_TOIE0);
				}
			#else
				{
					CLR_BIT(TIMSK_REG,TMR0_TOIE0);
				}
			#endif
	}
#else
	{

			#if TIMER0_CTC_INT==ENABLE
				{
					SET_BIT(TIMSK_REG,TMR0_OCIE0);
				}
			#else
				{
					CLR_BIT(TIMSK_REG,TMR0_OCIE0);
				}
			#endif
	}
#endif

TCCR0_REG &=TIMER0_CLK_SELCT_MASK;
TCCR0_REG |=TIMER0_CLK_SEL;
}

void TMR0_VoidClkSelection(u8 Copy_u8ClkSelectVal)
{
	TCCR0_REG &=TIMER0_CLK_SELCT_MASK;
	TCCR0_REG |=Copy_u8ClkSelectVal;
}

void TMR0_VoidStartTimer()
{
	TCCR0_REG &=TIMER0_CLK_SELCT_MASK;
	TCNT0_REG=0x00;

}

void TMR0_VoidStopTimer()
{
	TCCR0_REG &=TIMER0_CLK_SELCT_MASK;

}

void TMR0_VoidSetPreLoadValue(u8 Copy_u8PreLoadVal)
{
	OCR0_REG=Copy_u8PreLoadVal;
}

void TMR0_VoidSetCTCValue(u8 Copy_u8CTCVal)
{
	OCR0_REG=Copy_u8CTCVal;
}

void TMR0_VoidEnableINT_OVF()
{
	SET_BIT(TIMSK_REG,TMR0_TOIE0);
}

void TMR0_VoidDisableINT_OVF()
{
	CLR_BIT(TIMSK_REG,TMR0_TOIE0);
}

void TMR0_VoidEnableINT_CTC()
{
	SET_BIT(TIMSK_REG,TMR0_OCIE0);
}

void TMR0_VoidDisableINT_CTC()
{
	CLR_BIT(TIMSK_REG,TMR0_OCIE0);
}

void TMR0_VoidResetTimer()
{
	TCNT0_REG=0x00;
}

/*=================================================================================================End Timer 0====================================================================*/


void TMR1_VoidInit_Prebuild()
{
	TCCR1A_REG &=WAVEFORM_TIMER1_MODE_MASK_H1;
	TCCR1B_REG &=WAVEFORM_TIMER1_MODE_MASK_H2;

	switch(TIMER1_OP_MODE)
		{

		case TIMER1_MODE_NORMAL:
							{
									TCCR1A_REG|=TIMER1_MODE_NORMAL_H1;
									TCCR1B_REG|=TIMER1_MODE_NORMAL_H2<<3;

									break;
							}

		case TIMER1_MODE_PWM_PC_8BIT      :
		{
										TCCR1A_REG|=TIMER1_MODE_PWM_PC_8BIT_H1;
										TCCR1B_REG|=TIMER1_MODE_PWM_PC_8BIT_H2<<3;
										break;
								}
		case TIMER1_MODE_PWM_PC_9BIT      :
		{
										TCCR1A_REG|=TIMER1_MODE_PWM_PC_9BIT_H1;
										TCCR1B_REG|=TIMER1_MODE_PWM_PC_9BIT_H2<<3;
										break;
								}
		case TIMER1_MODE_PWM_PC_10BIT     :
		{
										TCCR1A_REG|=TIMER1_MODE_PWM_PC_10BIT_H1;
										TCCR1B_REG|=TIMER1_MODE_PWM_PC_10BIT_H2<<3;
										break;
								}
		case TIMER1_MODE_CTC_OCR1A        :
		{
										TCCR1A_REG|=TIMER1_MODE_CTC_OCR1A_H1;
										TCCR1B_REG|=TIMER1_MODE_CTC_OCR1A_H2<<3;
										break;
								}
		case TIMER1_MODE_PWM_F_8BIT       :
		{
										TCCR1A_REG|=TIMER1_MODE_PWM_F_8BIT_H1;
										TCCR1B_REG|=TIMER1_MODE_PWM_F_8BIT_H2<<3;
										break;
								}
		case TIMER1_MODE_PWM_F_9BIT       :
		{
										TCCR1A_REG|=TIMER1_MODE_PWM_F_9BIT_H1;
										TCCR1B_REG|=TIMER1_MODE_PWM_F_9BIT_H2<<3;
										break;
								}
		case TIMER1_MODE_PWM_F_10BIT      :
		{
										TCCR1A_REG|=TIMER1_MODE_PWM_F_10BIT_H1;
										TCCR1B_REG|=TIMER1_MODE_PWM_F_10BIT_H2<<3;
										break;
								}
		case TIMER1_MODE_PWM_PC__FC_ICR1  :
		{
										TCCR1A_REG|=TIMER1_MODE_PWM_PC__FC_ICR1_H1;
										TCCR1B_REG|=TIMER1_MODE_PWM_PC__FC_ICR1_H2<<3;
										break;
								}
		case TIMER1_MODE_PWM_PC__FC_OCR1A :
		{
										TCCR1A_REG|=TIMER1_MODE_PWM_PC__FC_OCR1A_H1;
										TCCR1B_REG|=TIMER1_MODE_PWM_PC__FC_OCR1A_H2<<3;
										break;
								}
		case TIMER1_MODE_PWM_PC_ICR1      :
		{
										TCCR1A_REG|=TIMER1_MODE_PWM_PC_ICR1_H1;
										TCCR1B_REG|=TIMER1_MODE_PWM_PC_ICR1_H2<<3;
										break;
								}
		case TIMER1_MODE_PWM_PC_OCR1A     :
		{
										TCCR1A_REG|=TIMER1_MODE_PWM_PC_OCR1A_H1;
										TCCR1B_REG|=TIMER1_MODE_PWM_PC_OCR1A_H2<<3;
										break;
								}
		case TIMER1_MODE_CTC_ICR1         :
		{
										TCCR1A_REG|=TIMER1_MODE_CTC_ICR1_H1;
										TCCR1B_REG|=TIMER1_MODE_CTC_ICR1_H2<<3;
										break;
								}
		case TIMER1_MODE_PWM_F_ICR1       :
		{
										TCCR1A_REG|=TIMER1_MODE_PWM_F_ICR1_H1;
										TCCR1B_REG|=TIMER1_MODE_PWM_F_ICR1_H2<<3;
										break;
								}
		case TIMER1_MODE_PWM_F_OCR1A      :
		{
										TCCR1A_REG|=TIMER1_MODE_PWM_F_OCR1A_H1;
										TCCR1B_REG|=TIMER1_MODE_PWM_F_OCR1A_H2<<3;
										break;
								}

		}

				TCCR1A_REG &=TIMER1_CHANNELA_CTC_OUTPUT_MODES_MASK;
				TCCR1A_REG |=TIMER1_OUTPUT_CHANNELA_MODE<<6;
				TCCR1A_REG &=TIMER1_CHANNELB_CTC_OUTPUT_MODES_MASK;
				TCCR1A_REG |=TIMER1_OUTPUT_CHANNELB_MODE<<4;


				#if(INPUT_CAPTURE_EDGE==CAPTURE_EDGE_DETECTION_FALLING)
					{
						CLR_BIT(TCCR1B_REG ,TCCR1B_ICES1);
					}
				#elif (INPUT_CAPTURE_EDGE==CAPTURE_EDGE_DETECTION_RISING)
					{
						SET_BIT(TCCR1B_REG ,TCCR1B_ICES1);
					}
				#endif

				#if( TIMER1_OVF_INT==ENABLE)
					{
						SET_BIT(TIMSK_REG,TMR1_TOIE1);
					}
				#else
					{
						CLR_BIT(TIMSK_REG,TMR1_TOIE1);
					}
				#endif

				#if ( TIMER1_CTC_CHANNELA_INT==ENABLE)
					{
						SET_BIT(TIMSK_REG,TMR1_OCIE1A);
					}
				#else
					{
						CLR_BIT(TIMSK_REG,TMR1_OCIE1A);
					}
				#endif
			#if (TIMER1_CTC_CHANNELB_INT==ENABLE)
				{
					SET_BIT(TIMSK_REG,TMR1_OCIE1B);
				}
			#else
				{
					CLR_BIT(TIMSK_REG,TMR1_OCIE1B);
				}
	        #endif


			#if (TIMER1_CAPTURE_INT==ENABLE)
            	{
            		SET_BIT(TIMSK_REG,TMR1_TICIE1);
				}
			#else
				{
					CLR_BIT(TIMSK_REG,TMR1_TICIE1);
				}
			#endif
	TCCR1B_REG &=TIMER1_CLK_SELCT_MASK;
	TCCR1B_REG |=TIMER1_CLK_SEL;


}
void ss()
{
	TCCR1A_REG &=TIMER1_CHANNELA_CTC_OUTPUT_MODES_MASK;
						TCCR1A_REG |=TIMER1_OUTPUT_CHANNELA_MODE<<6;
						TCCR1A_REG &=TIMER1_CHANNELB_CTC_OUTPUT_MODES_MASK;
						TCCR1A_REG |=TIMER1_OUTPUT_CHANNELB_MODE<<4;
}
void TMR1_VoidSetInputCaptureEdge(u8 Copy_u8CAPTURE_EDGE)
{
	if(Copy_u8CAPTURE_EDGE==CAPTURE_EDGE_DETECTION_FALLING)
	{
		CLR_BIT(TCCR1B_REG,TCCR1B_ICES1);
	}
else if(Copy_u8CAPTURE_EDGE==CAPTURE_EDGE_DETECTION_RISING)
	{
		SET_BIT(TCCR1B_REG ,TCCR1B_ICES1);
	}

}

void TMR1_VoidStartTimer()
{
	TCCR1B_REG &=TIMER1_CLK_SELCT_MASK;
	TCCR1B_REG |=TIMER1_CLK_SEL;
	TCNT1_REG=0x00;

}

u16 TMR1_VoidReadInputCapture()
{
	return ICR1_REG;
}


void TMR1_VoidSetTopVal_FastPWM(u16 Copy_u16TopVal)
{
	 ICR1_REG=Copy_u16TopVal;
}

void TMR1_VoidClkSelection(u8 Copy_u8ClkSelectVal)
{
	TCCR1B_REG &=TIMER1_CLK_SELCT_MASK;
	TCCR1B_REG |=Copy_u8ClkSelectVal;
}

void TMR1_VoidResetTimer()
{
	TCNT1_REG=0;
}

void TMR1_VoidStopTimer()
{
	TCCR1B_REG &=TIMER1_CLK_SELCT_MASK;

}

void TMR1_VoidSetCompareMathChannelA(u16 Copy_u16CompMode)
{
	OCR1A_REG=Copy_u16CompMode;
}
void TMR1_VoidSetCompareMathChannelB(u16 Copy_u16CompMode)
{
	OCR1B_REG=Copy_u16CompMode;

}

void TMR1_VoidSetTopVal(u16 Copy_u8TopVal)
{
	ICR1_REG=Copy_u8TopVal;

}

void TMR1_VoidEnableINT_OVF()
{
	SET_BIT(TIMSK_REG,TMR1_TOIE1);
}

void TMR1_VoidDisableINT_OVF()
{
	CLR_BIT(TIMSK_REG,TMR1_TOIE1);
}

void TMR1_VoidEnableINT_CTC_ChannelA()
{
	SET_BIT(TIMSK_REG,TMR1_OCIE1A);
}

void TMR1_VoidDisableINT_CTC_ChannelA()
{
	CLR_BIT(TIMSK_REG,TMR1_OCIE1A);
}

void TMR1_VoidEnableINT_CTC_ChannelB()
{
	SET_BIT(TIMSK_REG,TMR1_OCIE1B);
}

void TMR1_VoidDisableINT_CTC_ChannelB()
{
	CLR_BIT(TIMSK_REG,TMR1_OCIE1B);
}

void TMR1_VoidEnableINT_CaptureMode()
{
	SET_BIT(TIMSK_REG,TMR1_TICIE1);
}

void TMR1_VoidDisableINT_CaptureMode()
{
	CLR_BIT(TIMSK_REG,TMR1_TICIE1);
}

void TMR1_VoidSetTimerVal(u16 Copy_u16Timer1Value)
{
	TCNT1_REG=Copy_u16Timer1Value;
}
u16 TMR1_VoidGetTimerVal()
{
	return TCNT1_REG;
}

u32 power(u32 a, u32 b)
{  u32 n=a;
    if(b==0)
        return 1;
    for (u8 i=1; i<b; i++)
      a=a*n;
    return a;
}

u32 TIM0_VidPreloadVal(u8 Copy_u8Bits_Numbers ,u32 Copy_u32SystemFreq_inMiga ,u16 Copy_u8TimerPrescaller,f64 Copy_u32DiseredTime_inMicro)

{
    f64 Local_f64NumberOfCounts;
    u32 Local_u32PreloadValue;
    u32 Local_u32NumberTicks=power(2,Copy_u8Bits_Numbers );
    f64 Local_f64OverFlowTime_inMicro=Local_u32NumberTicks*(( (f64)Copy_u8TimerPrescaller)/ ( (f64)Copy_u32SystemFreq_inMiga ) );
    if(Copy_u32DiseredTime_inMicro>Local_f64OverFlowTime_inMicro)
    {
        Local_f64NumberOfCounts =Copy_u32DiseredTime_inMicro/Local_f64OverFlowTime_inMicro;
        Local_u32PreloadValue=Local_u32NumberTicks*(1-(Local_f64NumberOfCounts-(u32)(Local_f64NumberOfCounts)) );
        return (u32)(Local_f64NumberOfCounts)+1;
        /*
         ISR()
        {
            static u32 Local_u32Counter=0;
            Local_u32Counter++;
            if(Local_u32Counter==TIM0_VidPreloadVal( , , ,)
            {
                //Tack Action
                Timer_reg=Preloadval=.......
                Local_u32Counter=0;
            }


        }*/
    }
    else if(Copy_u32DiseredTime_inMicro<Local_f64OverFlowTime_inMicro)
    {
        Local_f64NumberOfCounts =Copy_u32DiseredTime_inMicro/Local_f64OverFlowTime_inMicro;
        Local_u32PreloadValue=Local_u32NumberTicks*(1-(Local_f64NumberOfCounts-(u32)(Local_f64NumberOfCounts)) );
        return 1;
        /*
        ISR()
       {
           //Tack_ACtion
           // Timer_reg=Preloadval=.......

       }*/
    }
    return 1;

}



u8 SendAddressTimer_Callback(void (*ISR_Timer)(void),u8 Copy_u8INT_Number)
{ u8 Local_u8Status=RT_OK;

	if(Timer_VidCallBack_ISR_Funtion[Copy_u8INT_Number]!=NULL)
	{
		Timer_VidCallBack_ISR_Funtion[Copy_u8INT_Number]=ISR_Timer;
	}
	else
	{
		Local_u8Status=NULL_POINTER;
	}
	return Local_u8Status;

}

void __vector_11 (void) __attribute__((signal));     //Timer0 OVF
void __vector_11 (void)
{

	Timer_VidCallBack_ISR_Funtion[TIM0_OVF]();

}

/*void __vector_10 (void) __attribute__((signal));	//Timer0 CTC
void __vector_10 (void)
{

	Timer_VidCallBack_ISR_Funtion[TIM0_CTC]();

}*/

void __vector_9 (void) __attribute__((signal));		//Timer1 OVF
void __vector_9 (void)
{

	Timer_VidCallBack_ISR_Funtion[TMR1_OVF]();

}

void __vector_8 (void) __attribute__((signal)); 	//Timer1 CTC_B
void __vector_8 (void)
{

	Timer_VidCallBack_ISR_Funtion[TMR1_CTC_ChannelB]();

}

void __vector_7 (void) __attribute__((signal));		//Timer1 CTC_A
void __vector_7 (void)
{

	Timer_VidCallBack_ISR_Funtion[TMR1_CTC_ChannelA]();

}

/*void __vector_6 (void) __attribute__((signal));		//Timer1 ICU
void __vector_6 (void)
{

	Timer_VidCallBack_ISR_Funtion[TMR1_ICU]();

}
*/
void __vector_5 (void) __attribute__((signal));	     //Timer2 OVF
void __vector_5 (void)
{

	Timer_VidCallBack_ISR_Funtion[TMR2_OVF]();

}

void __vector_4 (void) __attribute__((signal));		//Timer2 CTC
void __vector_4 (void)
{

	Timer_VidCallBack_ISR_Funtion[TMR2_CTC]();

}





