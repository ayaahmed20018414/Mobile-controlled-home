/*
 * LCD_Program.c
 *
 *  Created on: Sep 24, 2021
 *      Author: dell
 */
#include <string.h>
#include"util/delay.h"
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/CHECK_ERROR.h"
#include"../../MCAL/DIO_Driver/DIO_REG.h"
#include"../../MCAL/DIO_Driver/DIO_Interface.h"
#include"LCD_Config.h"
#include"LCD_Private.h"
#include"LCD_Interface.h"

u8 Global_u8Clear=0;
u8 Global_u8XPos=0;
u8 Global_u8YPos=0;
u8 Global_u8EnterGoToFunc=0;
/*if we select send command*/
# if(LCD_MODE==BIT_8)
void LCD_VoidSendCommand(u8 Copy_u8Command)
{
	/*for function set: RS:command,R/W:write */
		DIO_U8SetPinVal(LCD_Config_PORT,LCD_RS_PIN,LOW);
		DIO_U8SetPinVal(LCD_Config_PORT,LCD_R_W_PIN,LOW);
		DIO_U8SetPortVal(LCD_DATA_PORT,Copy_u8Command);


	/*making enable pulse high for 2mile sec only*/
	DIO_U8SetPinVal(LCD_Config_PORT,LCD_EN_PIN,HIGH);
	_delay_ms(2);
	DIO_U8SetPinVal(LCD_Config_PORT,LCD_EN_PIN,LOW);

}

/* if we select send data*/
void LCD_VoidSendData(u8 Copy_u8Data)
{
		    /*for function set:
	        * RS:command
	        * R/W:write
	       */
	        DIO_U8SetPinVal(LCD_Config_PORT,LCD_RS_PIN,HIGH);
			DIO_U8SetPinVal(LCD_Config_PORT,LCD_R_W_PIN,LOW);
			DIO_U8SetPortVal(LCD_DATA_PORT,Copy_u8Data);


		/*making enable pulse high for 2mile sec only*/
		DIO_U8SetPinVal(LCD_Config_PORT,LCD_EN_PIN,HIGH);
		_delay_ms(2);
		DIO_U8SetPinVal(LCD_Config_PORT,LCD_EN_PIN,LOW);



}

#elif (LCD_MODE==BIT_4)

	void LCD_VoidSendCommand(u8 Copy_u8Command)
	 {
	        /*Set RS pin 0 (Instruction register selected)*/
	        DIO_U8SetPinVal(LCD_Config_PORT,LCD_RS_PIN,LOW);
	        /*Set RW pin 0 (Write Mode selected)*/
			DIO_U8SetPinVal(LCD_Config_PORT,LCD_R_W_PIN,LOW);



		 for(u8 i=4;i<8;i++)
		 {
			 /*Output value of Instruction bit i at Data Register DIO Pin i*/
			 DIO_U8SetPinVal(LCD_DATA_PORT,i,GetBit(Copy_u8Command,i));
		 }
		 /*latch sent data*/
		 /*Set EN pin 1 (LCD Read data )*/

		 /*making enable pulse high for 2mile sec only*/
		 	DIO_U8SetPinVal(LCD_Config_PORT,LCD_EN_PIN,HIGH);
		 	_delay_ms(2);
		 	DIO_U8SetPinVal(LCD_Config_PORT,LCD_EN_PIN,LOW);

		 /*output second 4 bits instruction to data bus*/
		 for(u8 i=0;i<4;i++)
		 {
			 /*Output value of Instruction bit i at Data Register DIO Pin i*/
			 DIO_U8SetPinVal(LCD_DATA_PORT,i,GetBit(Copy_u8Command,i));
		 }
		 /*latch sent data*/
		 /*Set EN pin 1 (LCD Read data )*/

		 /*making enable pulse high for 2mile sec only*/
		 	DIO_U8SetPinVal(LCD_Config_PORT,LCD_EN_PIN,HIGH);
		 	_delay_ms(2);
		 	DIO_U8SetPinVal(LCD_Config_PORT,LCD_EN_PIN,LOW);
	 }



	 void LCD_VoidSendData(u8 Copy_u8Data)
	 {
		 /*Set RS pin 0 (Instruction register selected)*/
		  DIO_U8SetPinVal(LCD_Config_PORT,LCD_RS_PIN,HIGH);
		 /*Set RW pin 0 (Write Mode selected)*/
		DIO_U8SetPinVal(LCD_Config_PORT,LCD_R_W_PIN,LOW);



		 		 for(u8 i=4;i<8;i++)
		 		 {
		 			 /*Output value of Instruction bit i at Data Register DIO Pin i*/
		 			 DIO_U8SetPinVal(LCD_DATA_PORT,i,GetBit(Copy_u8Data,i));
		 		 }
		 		 /*latch sent data*/
		 		 /*Set EN pin 1 (LCD Read data )*/

		 		 /*making enable pulse high for 2mile sec only*/
		 		 	DIO_U8SetPinVal(LCD_Config_PORT,LCD_EN_PIN,HIGH);
		 		 	_delay_ms(2);
		 		 	DIO_U8SetPinVal(LCD_Config_PORT,LCD_EN_PIN,LOW);

		 		 /*output second 4 bits instruction to data bus*/
		 		 for(u8 i=0;i<4;i++)
		 		 {
		 			 /*Output value of Instruction bit i at Data Register DIO Pin i*/
		 			 DIO_U8SetPinVal(LCD_DATA_PORT,i,GetBit(Copy_u8Data,i));
		 		 }
		 		 /*latch sent data*/
		 		 /*Set EN pin 1 (LCD Read data )*/

		 		 /*making enable pulse high for 2mile sec only*/
		 		 	DIO_U8SetPinVal(LCD_Config_PORT,LCD_EN_PIN,HIGH);
		 		 	_delay_ms(2);
		 		 	DIO_U8SetPinVal(LCD_Config_PORT,LCD_EN_PIN,LOW);
	 }/*end of HLCD_voidWriteData()*/


	#endif /*end of Mode select*/




/*to initialize the LCD*/
void LCD_VoidInit(void)
{
/*delay for waiting after VDD rises*/
	_delay_ms(40);

#if NUM_LINES ==LINE1
	{
		LCD_VoidSendCommand(0b00110000);

	}
#elif NUM_LINES ==LINE2
	{
		LCD_VoidSendCommand(0b00111000);

	}
#endif

	_delay_us(50);
/*set ON/OFF Control |  Display :ON, Cursur:OFF ,Blink:OFF*/
	LCD_VoidSendCommand(0b00001100);

	/* Display Clear */
	LCD_VoidSendCommand(0x01);
}





/*To go to defined position in the LCD */
void LCD_VoidGoToPos(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	Global_u8EnterGoToFunc=1;
	Global_u8XPos=Copy_u8XPos;
	Global_u8YPos=Copy_u8YPos;
u8 Local_PositionAddress;
/*if the position in line1 the address is from  0 to 0x40 which is Y position */
	if(Copy_u8XPos==0)
	{
		Local_PositionAddress=Copy_u8YPos;

	}
	/*if the position in line2 the address is from  0x41 to 0x67 which is yposition+0x40 */
	else if(Copy_u8XPos==1)
		{
			Local_PositionAddress=Copy_u8YPos+0x40;

		}
	/*we set the register DDRAM with its command which in d.s the 8th bit is 1 and the rest of bits is address*/

	LCD_VoidSendCommand(1<<7 | Local_PositionAddress);
}


/*To clear the LCD*/
void LCD_VoidClearDisplay(void)
{
	 Global_u8Clear=1;
	LCD_VoidSendCommand(1);
}
void LCD_VoidCursorON(void)
{
	LCD_VoidSendCommand(SOLID_CURSOR);
}
void LCD_VoidCursorOFF()
{
	LCD_VoidSendCommand(CURSOR_OFF);
}
void LCD_VoidBlinkingCursorON(void)
{
	LCD_VoidSendCommand(BLINK_CURSOR);
}

void LCD_VoidDisplayON(void)
{
	LCD_VoidSendCommand(DISPLAY_ON);
}
void LCD_VoidDisplayOFF(void)
{
	LCD_VoidSendCommand(DISPLAY_OFF);
}


/*to shift the words left from defined position*/
void LCD_VoidShiftLeft(u8 Copy_u8ShiftNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	s8 Local_ShiftIterator=0;
	for(Local_ShiftIterator=Copy_u8YPos ; Local_ShiftIterator>Copy_u8YPos-Copy_u8ShiftNumber ;Local_ShiftIterator--)
	{
		LCD_VoidGoToPos(Copy_u8XPos,Local_ShiftIterator);
		LCD_VoidSendData(' ');
	}
}
/*to shift the words Right from defined position*/
void LCD_VoidShiftRight(u8 Copy_u8ShiftNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_ShiftIterator=0;
	for(Local_ShiftIterator=Copy_u8YPos ; Local_ShiftIterator<Copy_u8YPos+Copy_u8ShiftNumber ;Local_ShiftIterator++)
	{
		LCD_VoidGoToPos(Copy_u8XPos,Local_ShiftIterator);
		LCD_VoidSendData(' ');
	}
}
/*to convert ascii char to integer*/

void LCD_VoidSendNumber(u32 Copy_u32Char)
{
u8 Local_Char_Converted[16];
u32  Local_Temp=Copy_u32Char;
u8 Counter=0;
while(Local_Temp>=1)
{
    Counter++;
    Local_Temp/=10;
}
Local_Temp=Copy_u32Char;

	for(u8 i=0;i<Counter;i++)
		{

			Local_Char_Converted[i]=Local_Temp%10+'0';

			Local_Temp/=10;
		}

	for (int i = Counter-1; i >=0 ; i--)
		{
			LCD_VoidSendData(Local_Char_Converted[i]);
		}


}


void LCD_VoidSendString( const u8* Copy_PtString)
{u8 Local_Counter=0;

    while(Copy_PtString[Local_Counter]!='\0')
    {

    	LCD_VoidSendData(Copy_PtString[Local_Counter]);
    	Local_Counter++;
    }

}


void LCD_VoidCreateSpecialChar(const u8 *Copy_PcDataPattern,u8 Copy_u8BlockNo,u8 Copy_u8XPos,u8 Copy_u8YPos)

{
	/*calculating the address of CGRAM which is 64 byte for 8 locations */
u8 Local_u8CGRAMAddress=8*Copy_u8BlockNo;

/*for counting in for loop*/
u8 Local_u8Iterator=0;

/*Send CGRAM Address as command to LCD ,Setting bit 6,clearing bit 7 */
LCD_VoidSendCommand(1<<6 |Local_u8CGRAMAddress);

/*Send Data(our pattern) in CGRAM in the address chosen above*/
 for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
	 LCD_VoidSendData(Copy_PcDataPattern[Local_u8Iterator]);
	}
 /*choose the position in LCD display*/
 LCD_VoidGoToPos(Copy_u8XPos, Copy_u8YPos);

 /*Sending data to display LCD which were written in GCRAM ,it take the location of address and take the whole block from Copy_u8BlockNo*8 to Copy_u8BlockNo*8+8*/
 LCD_VoidSendData(Copy_u8BlockNo);
}

