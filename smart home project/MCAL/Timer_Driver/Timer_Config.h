

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


/*Timer 0  Configurations */
/*TCCR0_REG timer/Counter Control Register */

/*
 * Waveform Generation Mode
 */
/* Options:
 *
 * 	   TIMER0_MODE_NORMAL
 * 	   TIMER0_MODE_PWM_PC
 * 	   TIMER0_MODE_CTC
 * 	   TIMER0_MODE_PWM_F
 *
 */
#define	TIMER0_OP_MODE  TIMER0_MODE_PWM_F



/*
 * Compare Output Mode, non-PWM Mode,Fast PWM Mode , Phase Correct PWM Mode
 */
/*Options:
 *     TIMER0_OC0_DISCONNECTED
 *
 *
 *    Compare Output Mode, non-PWM
 *
 *     TIMER0_OC0_TOGGLE_RES
 *     TIMER0_OC0_CLEAR
 *     TIMER0_OC0_SET
 *
 *
 *   Compare Output Mode, Fast PWM
 *
 *
 *      TIMER0_OC0_PWM_F_CLR_COMP_SET_TOP
 *      TIMER0_OC0_PWM_F_SET_COMP_CLR_TOP
 *
 *
 *   Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM
 *
 *
 *     TIMER0_OC0_PWM_PC_CLR_UPCOUNTING_SET_DOWNCOUNTING
 *     TIMER0_OC0_PWM_PC_SET_UPCOUNTING_CLR_DOWNCOUNTING
*/


#define TIMER0_OUTPUT_MODE     TIMER0_OC0_PWM_F_CLR_COMP_SET_TOP

/*Clock Selection*/
/*Options:
 *      TIMER0_CLK_SELCT_MASK
 *      TIMER0_NO_CLK
 *      TIMER0_PRESCALER_DIV_1
 *      TIMER0_PRESCALER_DIV_8
 *      TIMER0_PRESCALER_DIV_64
 *      TIMER0_PRESCALER_DIV_256
 *      TIMER0_PRESCALER_DIV_1024
 *      TIMER0_EXT_CLK_FALLING_EDGE
 *      TIMER0_EXT_CLK_FALLING_RISING
 */

#define TIMER0_CLK_SEL  TIMER0_PRESCALER_DIV_8


/*Timer/Counter0 Interrupt Mask Register – TIMSK0*/

/*Options:
 * 		ENABLE
 * 		DISABLE
 */
#define TIMER0_OVF_INT          DISABLE
#define TIMER0_CTC_INT		    DISABLE


/*==============================================================End_Timer0=========================================================================*/

/*Timer 1 Configurations */

/*Timer/Counter1 ControlRegister A – TCCR1A */

/*
 * Waveform Generation Mode
 */
/* Options:
 *
 * 	   TIMER1_MODE_NORMAL
 * 	   TIMER1_MODE_PWM_PC_8BIT
 * 	   TIMER1_MODE_PWM_PC_9BIT
 * 	   TIMER1_MODE_PWM_PC_10BIT
 *     TIMER1_MODE_CTC_OCR1A
 *     TIMER1_MODE_PWM_F_8BIT
 *     TIMER1_MODE_PWM_F_9BIT
 *     TIMER1_MODE_PWM_F_10BIT
 *     TIMER1_MODE_PWM_PC__FC_ICR1
 *     TIMER1_MODE_PWM_PC__FC_OCR1A
 *     TIMER1_MODE_PWM_PC_ICR1
 *     TIMER1_MODE_PWM_PC_OCR1A
 *     TIMER1_MODE_CTC_ICR1
 *     TIMER1_MODE_PWM_F_ICR1
 *     TIMER1_MODE_PWM_F_OCR1A
 *
 */
#define	TIMER1_OP_MODE  TIMER1_MODE_NORMAL


/*Options:
 * 		CAPTURE_EDGE_DETECTION_FALLING
 * 		CAPTURE_EDGE_DETECTION_RISING
 */

#define INPUT_CAPTURE_EDGE   CAPTURE_EDGE_DETECTION_RISING

/*
 * Compare Output Mode, non-PWM Mode,Fast PWM Mode , Phase Correct PWM Mode
 */
/*Options:
 *
 *      TIMER1_DISCONNECTED
 *
 *  Compare Output Mode, non-PWM
 *      TIMER1_CTC_TOGGLE
 *      TIMER1_CTC_CLEAR
 *      TIMER1_CTC_SET
 *
 *  Compare Output Mode, Fast PWM
 *
 *      TIMER1_PWM_F__SPICHAL_TOGGLE
 *      TIMER1_PWM_F_CLR_COMP_SET_TOP
 *      TIMER1_PWM_F_SET_COMP_CLR_TOP
 *
 *  Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM
 *
 *      TIMER1_PWM_PC_SPICHAL_TOGGLE
 *      TIMER1_PWM_PC_CLR_UPCOUNTING_SET_DOWNCOUNTING
 *      TIMER1_PWM_PC_SET_UPCOUNTING_CLR_DOWNCOUNTING
 *
 *
 *
*/


#define TIMER1_OUTPUT_CHANNELA_MODE     TIMER1_PWM_F_CLR_COMP_SET_TOP

#define TIMER1_OUTPUT_CHANNELB_MODE     TIMER1_PWM_F_CLR_COMP_SET_TOP


/*
 * Clock Selection
 */

/*Options:
 *
 *      TIMER1_CLK_SELCT_MASK
 *      TIMER1_NO_CLK
 *      TIMER1_PRESCALER_DIV_1
 *      TIMER1_PRESCALER_DIV_8
 *      TIMER1_PRESCALER_DIV_64
 *      TIMER1_PRESCALER_DIV_256
 *      TIMER1_PRESCALER_DIV_1024
 *      TIMER1_EXT_CLK_FALLING_EDGE
 *      TIMER1_EXT_CLK_FALLING_RISING
 */

#define TIMER1_CLK_SEL  TIMER1_PRESCALER_DIV_8


/*Timer/Counter1 Interrupt Mask Register – TIMSK1*/

/*Options:
 * 		ENABLE
 * 		DISABLE
 */


#define TIMER1_OVF_INT                  DISABLE
#define TIMER1_CTC_CHANNELA_INT		    DISABLE
#define TIMER1_CTC_CHANNELB_INT		    DISABLE
#define TIMER1_CAPTURE_INT		        ENABLE



/*=========================================================End_Timer1===================================================================*/

#endif
