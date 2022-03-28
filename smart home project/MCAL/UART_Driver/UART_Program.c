/*
 * DIO_Interface.c
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */


#include"util/delay.h"
#include <stdarg.h>
#include <stdio.h>
#include "string.h"
#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/CHECK_ERROR.h"
#include "UART_Config.h"
#include "UART_Interface.h"
#include "UART_private.h"
#include "UART_REG.h"


static void(*UART_VidCallBack_ISR_Funtion[3])(void)={NULL};

void UART_VoidInit()
{
/*USART Control and Status Register A – UCSRA*/
u8 Local_u8ClearTemp=0;
//Local_u8ClearTemp=UCSRA_REG|(0x80);
//Local_u8ClearTemp|=(1<<UCSRC_URSEL);
	/*Doubling Baud rate Choice*/
#if(DOUBLE_BAUD_RATE==ENABLE)
		{
			SET_BIT(UCSRA_REG,UCSRA_U2X);
		}
#else
		{
			CLR_BIT(UCSRA_REG,UCSRA_U2X);
		}
#endif

	/* Enable Multi Communication data*/
#if(MULTI_COMMINICATION_MODE==ENABLE)
		{
			SET_BIT(UCSRA_REG,UCSRA_MPCM);
		}
#else
		{
			CLR_BIT(UCSRA_REG,UCSRA_MPCM);
		}

#endif

/*=====================================================================================================================*/
	/*USART Control and Status Register B – UCSRB*/

	/*Enable Rx Complete Recieving Interrupt */

#if(RX_COMPLETE_INTERRUPT==ENABLE)
		{
			SET_BIT(UCSRB_REG,UCSRB_RXCIE);
		}
#else
		{
			CLR_BIT(UCSRB_REG,UCSRB_RXCIE);
		}

#endif
	/*Enable Tx Complete Transmitting Interrupt */


#if(TX_COMPLETE_INTERRUPT==ENABLE)
		{
			SET_BIT(UCSRB_REG,UCSRB_TXCIE);
		}
#else
		{
			CLR_BIT(UCSRB_REG,UCSRB_TXCIE);
		}

#endif


	/*USART Data Register Empty Interrupt Enable*/

#if(TX_EMPTY_BUFER_INTERRUPT==ENABLE)
		{
			SET_BIT(UCSRB_REG,UCSRB_UDRIE);
		}
#else
		{
			CLR_BIT(UCSRB_REG,UCSRB_UDRIE);
		}
#endif


/*=====================================================================================================*/


	/*USART Control and Status Register C – UCSRC*/

/* to Make the Selection on UCSRC_Register not  UBRRH Register */




		/*to Set Parity Mode*/
		UCSRC_REG &=PARITY_MODE_MASK;
		UCSRC_REG|=(PARITY_MODE<<PARITY_MODE_SHIFT_VAL)|(1<<UCSRC_URSEL);



/*to set the Data Size*/
#if(DATA_SIZE==DATA_SIZE_5_BIT ||DATA_SIZE==DATA_SIZE_6_BIT||DATA_SIZE==DATA_SIZE_7_BIT||DATA_SIZE==DATA_SIZE_8_BIT)
{
	UCSRC_REG &=(DATA_SIZE_MASK);
	UCSRC_REG|=(DATA_SIZE<<DATA_SIZE_SHIFT_VAL)|(1<<UCSRC_URSEL);


}

#elif (DATA_SIZE==DATA_SIZE_9_BIT)
{
	UCSRC_REG &=DATA_SIZE_MASK;
	UCSRC_REG|=(3<<DATA_SIZE_SHIFT_VAL)|(1<<UCSRC_URSEL);;

	SET_BIT(UCSRB_REG,UCSRC_UCSZ2)

}
#endif




#if(SYNCHONIZATION_MODE==SYNC_MODE)
		{
		UCSRC_REG|=(1<<UCSRC_UMSEL)|(1<<UCSRC_URSEL);
		}
#elif(SYNCHONIZATION_MODE==ASYNC_MODE)
		{

			CLR_BIT(Local_u8ClearTemp,UCSRC_UMSEL);
			UCSRC_REG|=Local_u8ClearTemp;
		}
#endif


/*To Select the Number of stop bits*/
#if(NUM_OF_STOP_BIT==STOP_BIT_2)
		{
			UCSRC_REG|=(1<<UCSRC_USBS)|(1<<UCSRC_URSEL);
		}
#elif(NUM_OF_STOP_BIT==STOP_BIT_1)
		{

			CLR_BIT(Local_u8ClearTemp,UCSRC_USBS);
			UCSRC_REG|=Local_u8ClearTemp;

		}
#endif



#if(CLOCK_POLARITY==TX_FALLING_RX_RISING)
		{
			UCSRC_REG|=(1<<UCSRC_UCPOL)|(1<<UCSRC_URSEL);
		}
#elif(CLOCK_POLARITY==TX_RISING_RX_FALLING)
		{

			CLR_BIT(Local_u8ClearTemp,UCSRC_UCPOL);
			UCSRC_REG|=Local_u8ClearTemp;
		}

#endif





/*Open Data Sheet to Select Baud Rate*/

		UBRRL_REG=BAUD_RATE_VALE;
		UBRRH_REG=(BAUD_RATE_VALE>>8)&(0x7F);

	UCSRB_REG|=(1<<UCSRB_RXEN)|(1<<UCSRB_TXEN);
}




u8 UART_u8FrameErrorDetection()
{
	u8 Local_u8FrameErrorStatus=0;

	if(GET_BIT(UCSRA_REG,UCSRA_FE))
	{
		Local_u8FrameErrorStatus=1;
	}
	return Local_u8FrameErrorStatus;

}

void UART_ReceiveString(u8 *str)
{
	u8 i = 0;
	str[i] = UART_u8RXRecieveData();
	while(str[i] != '#')
	{
		i++;
		str[i] = UART_u8RXRecieveData();
	}
	str[i] = '\0';
}
u8 UART_u8DataOverRunDetection()
{
	u8 Local_u8FrameErrorStatus=0;

	if(GET_BIT(UCSRA_REG,UCSRA_DOR))
	{
		Local_u8FrameErrorStatus=1;
	}
	return Local_u8FrameErrorStatus;

}

u8 UART_u8ParityErrorDetection()
{
	u8 Local_u8FrameErrorStatus=0;

	if(GET_BIT(UCSRA_REG,UCSRA_PE))
	{
		Local_u8FrameErrorStatus=1;
	}
	return Local_u8FrameErrorStatus;

}

void UART_u8SetBaudRate(u8 Copy_u8BaudRateVal,u8 Copy_u8Freq)
{
	u16 UBRR_Temp;
	if(SYNCHONIZATION_MODE==ASYNC_MODE)
	{
		if(DOUBLE_BAUD_RATE==ENABLE)
		{
			UBRR_Temp=(Copy_u8Freq)/(8*Copy_u8BaudRateVal)-1;
		}
		else
		{
			UBRR_Temp=(Copy_u8Freq)/(16*Copy_u8BaudRateVal)-1;
		}

	}
	else if (SYNCHONIZATION_MODE==SYNC_MODE)
	{
		UBRR_Temp=(Copy_u8Freq)/(2*Copy_u8BaudRateVal)-1;
	}
	CLR_BIT(UCSRC_REG,UCSRC_URSEL);
	UBRRL_REG=UBRR_Temp;
	UBRRH_REG=(UBRR_Temp>>8)&(0x7F);
}



void UART_VoidTXSendData(u16 Copy_u16TxData)
{
	UDR_REG=Copy_u16TxData;
	while(GET_BIT(UCSRA_REG,UCSRA_UDRE)==0);


}

u8 UART_u8RXRecieveData(void)
{

	//u16  Local_u16RecievedData;

	while(GET_BIT(UCSRA_REG,UCSRA_RXC)==0);
	//Local_u16RecievedData=	UDR_REG;

return UDR_REG;
}


void UART_VoidTxSendFloatNumber(f64 Copy_f64TxData)
{

	u32 DecimalNum=100000*(Copy_f64TxData-(u32)Copy_f64TxData);
	 UART_VoidSendNumber(Copy_f64TxData);
	 UART_VoidTXSendData('.');
	 UART_VoidSendNumber(DecimalNum);



}

void UART_VoidSendNumber(u32 Copy_u32Char)
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
		UART_VoidTXSendData(Local_Char_Converted[i]);
		}


}

u8 CountParameters(const u8 *String)
{
    u8 counter=0;
    for (int i=0; i<strlen(String);i++)
    {
        if(String[i]=='#')
        {
            counter++;
        }

    }

    return counter;
}

void log_print ( const u8 *StringOut ,...)
{
	 static u32 iterator=0;
    va_list args;
    u8 num=CountParameters(StringOut);
    va_start(args, num);




    while (*StringOut != '\0')
    {
        if ((*StringOut == '%')&&(*(StringOut+1) == 'd'))
        {
            int IntegerNum = (int)va_arg(args, int);

            if(IntegerNum<0)
            UART_VoidTXSendData('-');

            UART_VoidSendNumber(abs(IntegerNum));
            ++StringOut;
        }
        else if ((*StringOut == '%')&&(*(StringOut+1) =='f'))
        {
            double FloatNumber =(double ) va_arg(args, double);
            int valInt=(int)FloatNumber;


            if(valInt!=0)
            {
            	if(FloatNumber<0)
            		UART_VoidTXSendData('-');

            	UART_VoidTxSendFloatNumber(fabs(FloatNumber));

            }
            else
            {
            	if(valInt<0)
				UART_VoidTXSendData('-');
            	UART_VoidSendNumber(abs(valInt));
            }

            ++StringOut;
        }
       else if ((*StringOut == '%')&&(*(StringOut+1) == 'c'))
        {

            int Char = va_arg(args, int);

            UART_VoidTXSendData(Char);


            ++StringOut;
        }

      else if ((*StringOut == '%')&&(*(StringOut+1) == 's'))
        {
            u8 *String = va_arg(args, int);
            for(u8 i=0;i<strlen(String);i++)
            {

            	  UART_VoidTXSendData(String[i]);

            }
            ++StringOut;
        }
		  else if ((*StringOut == '\\' )&&(*(StringOut+1) == 'n'))
		  {
			  for(u8 i=0;i<70-iterator;i++)
			{
				  UART_VoidTXSendData(' ');

			}
			  iterator=0;
		  }
		  else if ((*StringOut == '\\')&&(*(StringOut+1) == 't'))
		  		  {
		  			  for(u8 i=0;i<7;i++)
		  			{
		  				  UART_VoidTXSendData(' ');
		  			}
		  		  }
        else
        {

        	 UART_VoidTXSendData(*StringOut);

        }
        ++StringOut;
        iterator++;
    }

    va_end(args);


}


u8 SendAddressUART_Callback(void (*ISR_UART)(void),u8 Copy_u8INT_Number)
{ u8 Local_u8Status=RT_OK;

	if(UART_VidCallBack_ISR_Funtion[Copy_u8INT_Number]!=NULL)
	{
		UART_VidCallBack_ISR_Funtion[Copy_u8INT_Number]=ISR_UART;
	}
	else
	{
		Local_u8Status=NULL_POINTER;
	}
	return Local_u8Status;

}

void __vector_13 (void) __attribute__((signal));     //RX Complete
void __vector_13 (void)
{

	UART_VidCallBack_ISR_Funtion[UART_RX_COMPLETE]();

}
void __vector_14 (void) __attribute__((signal));	//Buffer Register Empty
void __vector_14 (void)
{

	UART_VidCallBack_ISR_Funtion[UART_BUFFER_REGISTER_EMPTY]();

}

void __vector_15 (void) __attribute__((signal));		//TX Complete
void __vector_15 (void)
{

	UART_VidCallBack_ISR_Funtion[UART_TX_COMPLETE]();

}
