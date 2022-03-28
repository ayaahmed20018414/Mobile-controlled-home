/*
 * INTERFACE.h
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


/*TCCR0_REG timer/Counter Control Register */

/*
 * Waveform Generation Mode
 */

#define WAVEFORM_TIMER0_MODE_MASK      0b10110111
#define TIMER0_MODE_NORMAL             0x00
#define TIMER0_MODE_PWM_PC             0x40
#define TIMER0_MODE_CTC                0x08
#define TIMER0_MODE_PWM_F              0x48


/*
 * Compare Output Mode, non-PWM Mode,Fast PWM Mode , Phase Correct PWM Mode
 */

#define TIMER0_CTC_OUTPUT_MODES_MASK      0b11001111
#define TIMER0_OC0_DISCONNECTED           (u8)0x00

/*
 *  Compare Output Mode, non-PWM
 */
#define TIMER0_OC0_TOGGLE_RES             (u8)0x10
#define TIMER0_OC0_CLEAR                  (u8)0x20
#define TIMER0_OC0_SET                    (u8)0x30

/*
 * Compare Output Mode, Fast PWM
 */

#define TIMER0_OC0_PWM_F_CLR_COMP_SET_TOP                     (u8)0x20
#define TIMER0_OC0_PWM_F_SET_COMP_CLR_TOP                     (u8)0x30

/*
 * Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM
 */

#define TIMER0_OC0_PWM_PC_CLR_UPCOUNTING_SET_DOWNCOUNTING     (u8)0x20
#define TIMER0_OC0_PWM_PC_SET_UPCOUNTING_CLR_DOWNCOUNTING     (u8)0x30

/*
 *  Clock Select
 */

#define TIMER0_CLK_SELCT_MASK                0b11111000
#define TIMER0_NO_CLK                        (u8)0x00
#define TIMER0_PRESCALER_DIV_1               (u8)0x01
#define TIMER0_PRESCALER_DIV_8               (u8)0x02
#define TIMER0_PRESCALER_DIV_64              (u8)0x03
#define TIMER0_PRESCALER_DIV_256             (u8)0x04
#define TIMER0_PRESCALER_DIV_1024            (u8)0x05
#define TIMER0_EXT_CLK_FALLING_EDGE          (u8)0x06
#define TIMER0_EXT_CLK_FALLING_RISING        (u8)0x07



/*================================================End timer 0==============================================================================*/


/* TCCR1A Timer/Counter1 Control Register A */

/*
 * Waveform Generation Mode
 */

#define WAVEFORM_TIMER1_MODE_MASK_H1          0b11111100
#define TIMER1_MODE_NORMAL_H1            	  0x00
#define TIMER1_MODE_PWM_PC_8BIT_H1            0x01
#define TIMER1_MODE_PWM_PC_9BIT_H1            0x02
#define TIMER1_MODE_PWM_PC_10BIT_H1           0x03
#define TIMER1_MODE_CTC_OCR1A_H1              0x00
#define TIMER1_MODE_PWM_F_8BIT_H1             0x01
#define TIMER1_MODE_PWM_F_9BIT_H1             0x02
#define TIMER1_MODE_PWM_F_10BIT_H1            0x03
#define TIMER1_MODE_PWM_PC__FC_ICR1_H1        0x00
#define TIMER1_MODE_PWM_PC__FC_OCR1A_H1       0x01
#define TIMER1_MODE_PWM_PC_ICR1_H1            0x02
#define TIMER1_MODE_PWM_PC_OCR1A_H1           0x03
#define TIMER1_MODE_CTC_ICR1_H1               0x00
#define TIMER1_MODE_PWM_F_ICR1_H1             0x02
#define TIMER1_MODE_PWM_F_OCR1A_H1            0x03

enum WavForm_Mode
		{

	TIMER1_MODE_NORMAL            ,
	TIMER1_MODE_PWM_PC_8BIT       ,
	TIMER1_MODE_PWM_PC_9BIT       ,
	TIMER1_MODE_PWM_PC_10BIT      ,
	TIMER1_MODE_CTC_OCR1A         ,
	TIMER1_MODE_PWM_F_8BIT        ,
	TIMER1_MODE_PWM_F_9BIT        ,
	TIMER1_MODE_PWM_F_10BIT       ,
	TIMER1_MODE_PWM_PC__FC_ICR1   ,
	TIMER1_MODE_PWM_PC__FC_OCR1A  ,
	TIMER1_MODE_PWM_PC_ICR1       ,
	TIMER1_MODE_PWM_PC_OCR1A      ,
	TIMER1_MODE_CTC_ICR1          ,
	TIMER1_MODE_PWM_F_ICR1 =14    ,
	TIMER1_MODE_PWM_F_OCR1A

		};

/*
 * to select the edge that Capture mode detect
*/
#define CAPTURE_EDGE_DETECTION_FALLING (0)
#define CAPTURE_EDGE_DETECTION_RISING  (1)


/*
 * Compare Output Mode, non-PWM Mode,Fast PWM Mode , Phase Correct PWM Mode
 */

#define TIMER1_CHANNELB_CTC_OUTPUT_MODES_MASK      0b11001111

#define TIMER1_CHANNELA_CTC_OUTPUT_MODES_MASK      0b00111111

#define TIMER1_DISCONNECTED                              (u8)0x00

/*
 *  Compare Output Mode, non-PWM
 */
#define TIMER1_CTC_TOGGLE                           	 (u8)0x01
#define TIMER1_CTC_CLEAR                            	 (u8)0x02
#define TIMER1_CTC_SET                               	 (u8)0x03

/*
 * Compare Output Mode, Fast PWM
 */
#define TIMER1_PWM_F__SPICHAL_TOGGLE                      (u8)0x01
#define TIMER1_PWM_F_CLR_COMP_SET_TOP                     (u8)0x02
#define TIMER1_PWM_F_SET_COMP_CLR_TOP                     (u8)0x03

/*
 * Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM
 */
#define TIMER1_PWM_PC_SPICHAL_TOGGLE                 	  (u8)0x01
#define TIMER1_PWM_PC_CLR_UPCOUNTING_SET_DOWNCOUNTING     (u8)0x02
#define TIMER1_PWM_PC_SET_UPCOUNTING_CLR_DOWNCOUNTING     (u8)0x03



/*Timer/Counter1 Control Register B – TCCR1B*/

/*
 * Rest of bits to select Waveform Generation Mode
 */
#define WAVEFORM_TIMER1_MODE_MASK_H2          0b11100111
#define TIMER1_MODE_NORMAL_H2            	  0x00
#define TIMER1_MODE_PWM_PC_8BIT_H2            0x00
#define TIMER1_MODE_PWM_PC_9BIT_H2            0x00
#define TIMER1_MODE_PWM_PC_10BIT_H2           0x00
#define TIMER1_MODE_CTC_OCR1A_H2              0x01
#define TIMER1_MODE_PWM_F_8BIT_H2             0x01
#define TIMER1_MODE_PWM_F_9BIT_H2             0x01
#define TIMER1_MODE_PWM_F_10BIT_H2            0x01
#define TIMER1_MODE_PWM_PC__FC_ICR1_H2        0x02
#define TIMER1_MODE_PWM_PC__FC_OCR1A_H2       0x02
#define TIMER1_MODE_PWM_PC_ICR1_H2            0x02
#define TIMER1_MODE_PWM_PC_OCR1A_H2           0x02
#define TIMER1_MODE_CTC_ICR1_H2               0x03
#define TIMER1_MODE_PWM_F_ICR1_H2             0x03
#define TIMER1_MODE_PWM_F_OCR1A_H2            0x03
/*
 *  Clock Select
 */

#define TIMER1_CLK_SELCT_MASK                0b11111000
#define TIMER1_NO_CLK                        (u8)0x00
#define TIMER1_PRESCALER_DIV_1               (u8)0x01
#define TIMER1_PRESCALER_DIV_8               (u8)0x02
#define TIMER1_PRESCALER_DIV_64              (u8)0x03
#define TIMER1_PRESCALER_DIV_256             (u8)0x04
#define TIMER1_PRESCALER_DIV_1024            (u8)0x05
#define TIMER1_EXT_CLK_FALLING_EDGE          (u8)0x06
#define TIMER1_EXT_CLK_FALLING_RISING        (u8)0x07



#define ICR1_REG  (*(volatile u16*)0x46)
#define OCR1A_REG (*(volatile u16*)0x4A)
#define OCR1B_REG (*(volatile u16*)0x48)
#define TCNT1_REG (*(volatile u16*)0x4C)


/*================================================End timer 1==============================================================================*/


/*to Enable the interrupt or Not*/
#define ENABLE   1
#define DISABLE  0




/*function to select Clock
 *Input:selection clock Value
 *Output :no return
 */
extern void TMR0_VoidClkSelection(u8 Copy_u8ClkSelectVal);

extern void TMR0_VoidStartTimer();

extern void TMR0_VoidStopTimer();

/*function to set PreLoad Value
 *Input:Preload Value
 *Output :return Error Status
 */
extern void TMR0_VoidSetPreLoadValue(u8 Copy_u8PreLoadVal);

extern void TMR0_VoidSetCTCValue(u8 Copy_u8CTCVal);

extern void TMR0_VoidEnableINT_OVF();

extern void TMR0_VoidDisableINT_OVF();

extern void TMR0_VoidEnableINT_CTC();

extern void TMR0_VoidDisableINT_CTC();


/*function to Initialize the Timer 0
 * input :void
 * return :no return*/

extern void TMR0_VoidInit_Prebuild(void);

extern void TMR1_VoidInit_Prebuild();

extern void TMR1_VoidClkSelection(u8 Copy_u8ClkSelectVal);

extern void TMR1_VoidResetTimer();

extern u32 power(u32 a, u32 b);

extern u32 TIM0_VidPreloadVal(u8 Copy_u8Bits_Numbers ,u32 Copy_u32SystemFreq_inMiga ,u16 Copy_u8TimerPrescaller,f64 Copy_u32DiseredTime_inMicro);

extern void TMR1_VoidSetCompareMathChannelA(u16 Copy_u16CompMode);

extern void TMR1_VoidSetCompareMathChannelB(u16 Copy_u16CompMode);

extern void TMR1_VoidSetTopVal(u16 Copy_u8TopVal);

extern void TMR1_VoidEnableINT_OVF();

extern void TMR1_VoidDisableINT_OVF();

extern void TMR1_VoidEnableINT_CTC_ChannelA();

extern void TMR1_VoidDisableINT_CTC_ChannelA();

extern void TMR1_VoidEnableINT_CTC_ChannelB();

extern void TMR1_VoidDisableINT_CTC_ChannelB();

extern void TMR1_VoidEnableINT_CaptureMode();

extern void TMR1_VoidDisableINT_CaptureMode();

extern void TMR1_VoidSetTimerVal(u16 Copy_u16Timer1Value);

extern void TMR1_VoidSetInputCaptureEdge(u8 Copy_u8CAPTURE_EDGE);

extern u16 TMR1_VoidGetTimerVal();

extern u16 TMR1_VoidReadInputCapture();

extern void TMR1_VoidSetTopVal_FastPWM(u16 Copy_u16TopVal);

extern void TMR1_VoidStartTimer();

void ss();




/*CallBack Function*/
u8 SendAddressTimer_Callback(void (*ISR_Timer)(void),u8 Copy_u8INT_Number);



#endif
