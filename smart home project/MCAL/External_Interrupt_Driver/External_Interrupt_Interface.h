/*
 * INTERFACE.h
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */

#ifndef EXTERNAL_INTERRUPT_INTERFACE_H_
#define EXTERNAL_INTERRUPT_INTERFACE_H_


#define LOW_LEVEL      (u8)0
#define LOGICAL_CHANGE (u8)1
#define FALLING_EDGE   (u8)2
#define RISING_EDGE    (u8)3

/*to select the Sense Control for INT0  or INT1*/
/*
 * For LOW level the interrupt Requested
 * For Falling and Rising edges the interrupt Requested
 * For Falling  the interrupt Requested
 * For Rising edges the interrupt Requested
*/
#define LOW_LEVEL_INT01      0
#define LOGICAL_CHANGE_INT01 1
#define FALLING_EDGE_INT01   2
#define RISING_EDGE_INT01    3

/*to select the Sense Control for INT2 as it Triggered in edges*/
/*
 * For Falling  the interrupt Requested
 * For Rising edges the interrupt Requested
*/
#define FALLING_EDGE_INT2  0
#define RISING_EDGE_INT2   1

/*to Enable the interrupt or Not*/
#define ENABLE   1
#define DISABLE  0

/*External Interrupt Pins*/
/*
 * To enable INT0 as external Interrupt PIN (PORTD_PIN2)
 * To enable INT1 as external Interrupt PIN (PORTD_PIN3)
 * To enable INT2 as external Interrupt PIN (PORTB_PIN2)
 */
#define INT0 (u8)0
#define INT1 (u8)1
#define INT2 (u8)2


/*to set General Interrupt Enable GIE*/
#define SREG_I_BIT   (u8)7
/*GICR Bits to Enable PIE for Each one*/
#define GICR_INT0    (u8)6
#define GICR_INT1    (u8)7
#define GICR_INT2    (u8)5




/*to select sense for INT0 OR INT1*/
/*
 * to Configure INT0 for Controlling Sense in it
 * to Configure INT1 for Controlling Sense in it
 */
#define MCUCR_ISC01_ISC00_SELECT  (u8)0
#define MCUCR_ISC11_ISC10_SELECT  (u8)2

/*to select sense for INT2 */
#define MCUCSR_ISC2_BIT (u8)6



/*function to Enable or Disable the External Pin as Interrupt in Postbuild
 * input :EXTI_Pin_No,Enable or Disable
 * return : error status
 */
extern u8 EXTI_u8EnableOrDisableInterruptPin_Postbuild(u8 Copy_u8INTNum,u8 Copy_u8EN_DIS);


/*function to Control the Sense for EXTI Pins in Postbuild
 * input :EXTI_Pin_No,Sense Control
 * return : error status*/
/*
 *LOW_LEVEL_INT01         For LOW level the interrupt Requested                for INT0 Or INT1
 *LOGICAL_CHANGE_INT01    For Falling and Rising edges the interrupt Requested for INT0 Or INT1
 *FALLING_EDGE_INT01      For Falling  the interrupt Requested                 for INT0 Or INT1
 *RISING_EDGE_INT01       For Rising edges the interrupt Requested             for INT0 Or INT1
 *FALLING_EDGE_INT2       For Falling  the interrupt Requested                 for INT2 ONLY
 *RISING_EDGE_INT2        For Rising edges the interrupt Requested             for INT2 ONLY
 **/
extern u8 EXTI_u8ControlSense_Postbuild(u8 Copy_u8INTNum,u8 Copy_u8Sense);

/*function to Enable or Disable the External Pin as Interrupt in Prebuild
 *NO input,No return
 */
extern void EXTI_voidEnableOrDisableInterruptPin_Prebuild(void);

/*function to Control the Sense for EXTI Pins in Prebuild
 *NO input,No return
 */
extern void EXTI_VidControlSense_Prebuild(void);

/*CallBack Function*/
u8 SendAddress_Callback(void (*ISR_INT0)(void));

#endif
