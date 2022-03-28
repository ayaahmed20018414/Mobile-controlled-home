/*
 * LM35_Program.c
 *
 *  Created on: Oct 16, 2021
 *      Author: dell
 */

#ifndef HAL_LM35_MODULE_LM35_PROGRAM_H_
#define HAL_LM35_MODULE_LM35_PROGRAM_H_

/*to select the  returned unit*/
typedef enum
{
	Celsuis_Degree,
	Kilven_Degree,
	Fairenheit_Degree
}Degree_Unit;




/*to initialize the LM35 Which Initialize the ADC
 * input:No input
 * Output:No return
 */
void LM35_VoidInit(void);

/*to select  unit of the temprature degree
 * input:value of temprature ,unit degree
 * Output:return the temprature with selected unit
 */
extern u16 LM35_u16GetTempretureWithUnit(u16 Copy_u16AnalogVoltageMile,Degree_Unit Copy_enumUnit);

#endif /* HAL_LM35_MODULE_LM35_PROGRAM_C_ */
