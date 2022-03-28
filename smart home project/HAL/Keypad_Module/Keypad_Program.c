/*
 * DIO_Interface.c
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */


#include"util/delay.h"
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/CHECK_ERROR.h"
#include "../../MCAL/DIO_Driver/DIO_REG.h"
#include "../../MCAL/DIO_Driver/DIO_Interface.h"
#include "../Keypad_Module/Keypad_Config.h"
#include "../Keypad_Module/Keypad_Interface.h"
#include "../Keypad_Module/Keypad_Private.h"
#include "../Keypad_Module/Keypad_REG.h"



u8 Keypad_u8GetPressedKey()
{
	/*if not pressed return value indicate that not pressed*/
u8 Local_u8KeypadPressedStatus;
u8 Local_u8KeypadValue=TR_NOT_PRESSED;
u8 Local_u8KeypadCoulumnIterator=0;
u8 Local_u8KeypadRowIterator=0;

/*value showed when pressing*/
static u8 Local__u8KeypadValues[ROW_NUM][COULUMN_NUM]=ARRAY_VALUE;
static u8 Local_u8KeypadCoulums[COULUMN_NUM]={KEYPAD_COULUMN0,KEYPAD_COULUMN1,KEYPAD_COULUMN2,KEYPAD_COULUMN3};
static u8 Local_u8KeypadRows[ROW_NUM]={KEYPAD_ROW0,KEYPAD_ROW1,KEYPAD_ROW2,KEYPAD_ROW3};

for(Local_u8KeypadCoulumnIterator=0;Local_u8KeypadCoulumnIterator<COULUMN_NUM;Local_u8KeypadCoulumnIterator++)
{
	/*Activate the coulumn seriesly*/
	DIO_U8SetPinVal(KEYPAD_PORT,Local_u8KeypadCoulums[Local_u8KeypadCoulumnIterator],LOW);

	for(Local_u8KeypadRowIterator=0;  Local_u8KeypadRowIterator<ROW_NUM ;Local_u8KeypadRowIterator++)
	{

     DIO_U8GetPinVal(KEYPAD_PORT,Local_u8KeypadRows[Local_u8KeypadRowIterator],&Local_u8KeypadPressedStatus);
     /*if we pressed on button the coulomn selected in for loop 1 which indicate the button pushed here */
       if(Local_u8KeypadPressedStatus==LOW)
       {
    	   /*put the value of pressed key*/
    	   Local_u8KeypadValue=Local__u8KeypadValues[Local_u8KeypadRowIterator][Local_u8KeypadCoulumnIterator];

       }
       /*polling to indicate that user pull your hand up the button or not */
       while(Local_u8KeypadPressedStatus==LOW)
       {
    	   /*check again the user pulled up his hand or not*/
    	   DIO_U8GetPinVal(KEYPAD_PORT,Local_u8KeypadRows[Local_u8KeypadRowIterator],&Local_u8KeypadPressedStatus);
       }
      // return Local_u8KeypadValue;

	}
	/*Deactivate the coulumn seriesly*/
		DIO_U8SetPinVal(KEYPAD_PORT,Local_u8KeypadCoulums[Local_u8KeypadCoulumnIterator],HIGH);
}

return Local_u8KeypadValue;
}










