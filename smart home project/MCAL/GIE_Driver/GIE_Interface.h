/*
 * INTERFACE.h
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */

#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_




/*to Enable the interrupt or Not*/
#define ENABLE   1
#define DISABLE  0

/*to set General Interrupt Enable GIE*/
#define SREG_I_BIT   (u8)7

/*to Enable or Disable the GIE BIT*/
void EXTI_VidEnableOrDisableGIE(u8 Copy_u8EN_DIS);


#endif /* DIO_INTERFACE_H_ */
