/*
 * PORT_Config.h
 *
 *  Created on: Sep 28, 2021
 *      Author: dell
 */

#ifndef EXTERNAL_INTERRUPT_CONFIG_H_
#define EXTERNAL_INTERRUPT_CONFIG_H_


/*Configurations For setting Sense Control for INT0 and INT1*/
/*
 * 0-LOW_LEVEL_INT01
 * 1-LOGICAL_CHANGE_INT01
 * 2-FALLING_EDGE_INT01
 * 3-RISING_EDGE_INT01
*/
#define INT0_SENSE RISING_EDGE_INT01
#define INT1_SENSE LOW_LEVEL_INT01

/*Configurations For setting Sense Control for INT2*/
/*
 * 0-FALLING_EDGE_INT2
 * 1-RISING_EDGE_INT2
*/
#define INT2_SENSE FALLING_EDGE_INT2


/*Configure the External interrupt as Enable or Disable */
/*
 * 0-ENABLE
 * 1-DISABLE
*/
#define INT0_INITAIL_STATE ENABLE
#define INT1_INITAIL_STATE DISABLE
#define INT2_INITAIL_STATE DISABLE


#endif /* PORT_CONFIG_H_ */
