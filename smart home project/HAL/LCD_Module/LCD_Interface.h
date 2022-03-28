/*
 * LCD_Interface.h
 *
 *  Created on: Sep 24, 2021
 *      Author: dell
 */


#ifndef LCD_INRERFACE_H_
#define LCD_INTERFACE_H_


#define LINE1  0
#define LINE2  1


#define BIT_8 0
#define BIT_4 1

/*if we select send command*/
void LCD_VoidSendCommand(u8 Copyu8Command);

/* if we select send data*/
void LCD_VoidSendData(u8 Copy_u8Data);

/*to initialize the LCD*/
void LCD_VoidInit(void);

/*char to integer*/
void LCD_VoidSendNumber(u32 Copy_u32Char);

/*to Display Full String */
void LCD_VoidSendString( const u8* Copy_PtString);

/*to go to finite position in LCD DDRAM*/
void LCD_VoidGoToPos(u8 Copy_u8XPos,u8 Copy_u8YPos);

/*to make special char in LCD using GCRAM*/
void LCD_VoidCreateSpecialChar(const u8 *Copy_PcDataPattern,u8 Copy_u8BlockNo,u8 Copy_u8XPos,u8 Copy_u8YPos);

/*to Clean the LCD*/
void LCD_VoidClearDisplay(void);

/*to Shift Words Left*/
void LCD_VoidShiftLeft(u8 Copy_u8ShiftNumber,u8 Copy_u8XPos,u8 Copy_u8YPos);

/*to Shift Words Right*/
void LCD_VoidShiftRight(u8 Copy_u8ShiftNumber,u8 Copy_u8XPos,u8 Copy_u8YPos);

/*to display the cursor*/
void LCD_VoidCursorON(void);

/*to hide the cursor*/
void LCD_VoidCursorOFF(void);

/*to show blinking cursor in LCD*/
void LCD_VoidBlinkingCursorON(void);

/*to power (turn ON) the LCD */
void LCD_VoidDisplayON(void);

/*to turn OFF the LCD*/
void LCD_VoidDisplayOFF(void);


#endif /* LCD_INTERFACE_H_ */
