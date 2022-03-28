
#include"util/delay.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "../LIB/STDTYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/CHECK_ERROR.h"
#include "../MCAL/PORT_Driver/PORT_REG.h"
#include "../MCAL/PORT_Driver/PORT_Config.h"
/*#include "../MCAL/External_Interrupt_Driver/External_Interrupt_Interface.h"
#include "../MCAL/External_Interrupt_Driver/External_Interrupt_Config.h"*/
#include "../MCAL/PORT_Driver/PORT_Interface.h"
#include "../MCAL/DIO_Driver/DIO_REG.h"
#include "../MCAL/DIO_Driver/DIO_Interface.h"
/*#include "../MCAL/GIE_Driver/GIE_REG.h"
#include "../MCAL/GIE_Driver/GIE_Interface.h"*/
#include "../MCAL/UART_Driver/UART_REG.h"
#include "../MCAL/UART_Driver/UART_Interface.h"
#include "../MCAL/UART_Driver/UART_Config.h"
/*#include "../HAL/LCD_Module/LCD_Interface.h"
#include "../HAL/LCD_Module/LCD_Config.h"
#include "../HAL/Keypad_Module/Keypad_Private.h"
#include "../HAL/Keypad_Module/Keypad_Interface.h"
#include "../HAL/Keypad_Module/Keypad_Config.h"*/
#include "../HAL/DC_MOTOR/DC_MOTOR_Interface.h"
#include "../HAL/DC_MOTOR/DC_MOTOR_Private.h"
#include "../HAL/DC_MOTOR/DC_MOTOR_Config.h"




/*Implement Linked list for storing users data */

typedef struct  Users_Data{
  u8 User_Name[20];
  u8 User_Password[8];
}Users_Data;

/*creating struct to collect data of Users*/
typedef struct UserNode
{
	Users_Data data;
    struct UserNode *next;

}UserNode;


/*creating head and tail of linked list */
UserNode *HeadUser=NULL;
UserNode *TailUser=NULL;
u8 Global_u8UserNumber=0;

/*to know the  */
#define Data_Name     (u8)1
#define Data_Password (u8)0
#define NUMBER_OF_PW_TRIALS  3

u8 			PasswordIsCorrect_OR_Not(u8 Copy_u8EnteredPassword[],u8 Copy_u8Index);
UserNode*   CreatNewUser(Users_Data data1);
void 		InsertUser (UserNode *Node);
s8 			NameIsExist(u8 Name[]);
void 		DeleteUserAccount(u8 Name[]);
u8		    PasswordIsCorrect_OR_Not(u8 Copy_u8EnteredPassword[],u8 Copy_u8Index);
void 		EditingReservation(u8 Name[]);





int main (void)
{
	 PORT_VoidInit();
	// LCD_VoidInit();
	 UART_VoidInit();
	 Users_Data Global_stUser_Num;
	 s8  Local_s8NotFound_OR_FoundWhere;
	 u8  Local_s8PWNotFound_OR_Found;
	 u8  Local_u16RecievedString[20];
	 u8  Local_u8CounterPW=0;
	 u8  Local_u8ExitSyrtem_OR_Not=0;
	 u8 Local_u8PWNotCorrect_OR_Correct;

	 while(1)
	 {
		  log_print ("\n Are you New User or Not? \n Y\N \n");
		 UART_ReceiveString(Local_u16RecievedString);
		// log_print ( "%c",Local_u16RecievedString[2]);

		 /*========================================Entering  New Data of the New User ===============================================*/
		  if(Local_u16RecievedString[2]=='Y')

		  {
			/*=================Entering Name in Linked list for Specified index User==============*/
				log_print ( "Enter your Name Please:\n ");
				UART_ReceiveString(Local_u16RecievedString);
				log_print ( " The Name is : %s \n",Local_u16RecievedString);
				strcpy(Global_stUser_Num.User_Name,Local_u16RecievedString);

			/*=================Entering Password in Linked list for Specified index User==============*/
				log_print ( "Enter your Password Please:\n ");
				UART_ReceiveString(Local_u16RecievedString);
				log_print ( " The Password is :  %s \n",Local_u16RecievedString);
				strcpy(Global_stUser_Num.User_Password,Local_u16RecievedString);

			/*=================Inserting the data in Linked list for Specified index User==============*/
				InsertUser (CreatNewUser(Global_stUser_Num));
				log_print ("Sign Up is Done\n");

		  }
		  /*========================================Checking the Data of current Users ===============================================*/
		  else if(Local_u16RecievedString[2]=='N')
		  {
			  log_print ( "Enter your Name Please:\n ");
		      UART_ReceiveString(Local_u16RecievedString);
		      Local_s8NotFound_OR_FoundWhere=NameIsExist(Local_u16RecievedString);

		      if(Local_s8NotFound_OR_FoundWhere==-1)
		      {
		    	  log_print ( " The Name  : %s is Not Found Please Sign up before Sign in\n ",Local_u16RecievedString);
		      }
		      else
		      {
		    	  u8 Local_u8Iterator_ForEnteringPW_Trials;
		    	  log_print ( " The Name  : %s is Found at index %d \n ",Local_u16RecievedString,Local_s8NotFound_OR_FoundWhere);


				  for(Local_u8Iterator_ForEnteringPW_Trials=0;Local_u8Iterator_ForEnteringPW_Trials<NUMBER_OF_PW_TRIALS;Local_u8Iterator_ForEnteringPW_Trials++)
				  {



					  log_print("Enter the Password please :\n");
					  UART_ReceiveString(Local_u16RecievedString);
					  Local_u8PWNotCorrect_OR_Correct=PasswordIsCorrect_OR_Not( Local_u16RecievedString, Local_s8NotFound_OR_FoundWhere);
					  if(Local_u8PWNotCorrect_OR_Correct==0)
					  {

						 log_print("Sign in Done Successfully ! :\n");
						 Local_u8CounterPW=0;
						 break;
					  }
					  else if(Local_u8PWNotCorrect_OR_Correct==1)
					  {
						  log_print("Sign in Failed Please, Try again ! :\n");
						  Local_u8CounterPW++;
					  }

				  }

				  if(Local_u8CounterPW==NUMBER_OF_PW_TRIALS)
				  {
					  log_print("Your tries is expired\n please assure with password and try later\n");
					  DIO_U8SetPinVal(PORT_C,PIN_1,HIGH);
					  for(u8 i=0;i<5;i++)
					  {
						  DIO_U8SetPinVal(PORT_C,PIN_4,HIGH);
						  _delay_ms(500);
						 DIO_U8SetPinVal(PORT_C,PIN_4,LOW);
						 _delay_ms(500);

					  }

					  DIO_U8SetPinVal(PORT_C,PIN_1,LOW);

				  }
				  else if(Local_u8CounterPW==0)
				  {
					  Local_u8ExitSyrtem_OR_Not=0;
					  while(1)
					  {
					  log_print("\n");
					  log_print("Do you want Door subsystem or Light subsystem?\n");
					  log_print("IF you want Door subsystem Press D :\n");
					  log_print("IF you want Door subsystem Press L :\n");
					  log_print("IF you want Exit Press E :\n");
					  UART_ReceiveString(Local_u16RecievedString);

					  switch (Local_u16RecievedString[2])
					  {
							  case'L':
									{
									  while(1)
									  {
										  log_print("\n");
										  log_print("Do you want to Open or close Light ?\n");
										  log_print("IF you want Open Press O :\n");
										  log_print("IF you want Close Press C :\n");
										  log_print("IF you want to Back Press B :\n");
										  UART_ReceiveString(Local_u16RecievedString);
										  if (Local_u16RecievedString[2]=='O')
										  {
											  DIO_U8SetPinVal(PORT_C,PIN_0,HIGH);
										  }
										  else if (Local_u16RecievedString[2]=='C')
										  {
											 DIO_U8SetPinVal(PORT_C,PIN_0,LOW);
										  }
										  else if (Local_u16RecievedString[2]=='B')
										  {
											  break;
										  }
										  else
										  {
											  log_print("\n");
											  log_print ( "This Choice is not available");
										  }
										}
									  break;
									 }

							  case'D':
									  {

										while(1)
										  {
											  log_print("\n");
											  log_print("Do you want to Open or close Door ?\n");
											  log_print("IF you want Open Press  O :\n");
											  log_print("IF you want Close Press C :\n");
											  log_print("IF you want to Back Press B :\n");
											  UART_ReceiveString(Local_u16RecievedString);
											  if (Local_u16RecievedString[2]=='O')
												  {
												  DC_MOTOR_VidRotateUntiClockWise();
												   _delay_ms(1000);
												   DC_MOTOR_VidStop();

												  }
											   else if (Local_u16RecievedString[2]=='C')
												 {
												   DC_MOTOR_VidRotateClockWise();
												  _delay_ms(1000);
												  DC_MOTOR_VidStop();
												 }
											   else if (Local_u16RecievedString[2]=='B')
												 {
													  break;
												  }
												 else
												 { log_print("\n");
												  log_print ( "This Choice is not available");
												 }

											}
											break;
										  }
										  case'E':
										  {
											  Local_u8ExitSyrtem_OR_Not=1;
											  break;
										  }
										  default:
										  {
											  log_print("\n");
											  log_print ( "This Choice is not available,Try Again");
										  }



							  }

					  if(Local_u8ExitSyrtem_OR_Not==1)
					  {
						  break;
					  }

						   }

				  }


		      }
		  }
		  else
		  {
			  log_print ( "Invaild Choice");
		  }


 }
		return 0;
}




	    UserNode*CreatNewUser(Users_Data data1)
	    {
	    	UserNode *NewUser=(UserNode *)malloc(sizeof (UserNode));
	        strcpy(NewUser->data.User_Name,data1.User_Name);
	        strcpy(NewUser->data.User_Password,data1.User_Password);
	        NewUser->next=NULL;
	        return NewUser;
	    }





	    void InsertUser (UserNode *Node)
	    {
	        if (Global_u8UserNumber == 0)
	        {
	        	HeadUser = TailUser = Node;
	        }
	        else
	        {
	        	TailUser->next=Node;
	        	TailUser= Node;
	        }
	        Global_u8UserNumber++;

	    }

	    s8 NameIsExist(u8 Name[])
	    {
	        UserNode *temp=HeadUser;
	        u8 Local_u8EnteredNameLength=strlen(Name);
	        u8 Local_u8CounterLenght=0;
	        u8 Local_u8UserIndex=0;

	        while(temp!=NULL)
	        {
	            if(Local_u8EnteredNameLength==strlen(temp->data.User_Name))
	            {
	                for(u8 i=0;i<Local_u8EnteredNameLength;i++)
	                {
	                    if(temp->data.User_Name[i] == Name[i])
	                    {
	                        Local_u8CounterLenght++;
	                    }
	                    else
	                    {
	                        break;
	                    }

	                }
	                if(Local_u8CounterLenght==strlen(temp->data.User_Name))
	                {
	                    return  Local_u8UserIndex;
	                }
	                else
	                {
	                    Local_u8CounterLenght=0;
	                }
	            }


	            Local_u8UserIndex++;
	            temp=temp->next;

	        }
	        return -1;
	    }


	    void DeleteUserAccount(u8 Name[])
	    {
	    	s8 User_Posision=NameIsExist(&Name);
	        if(User_Posision!=-1)
	        {
	            UserNode *temp=HeadUser;
	            if(User_Posision==0)
	            {

	                if (Global_u8UserNumber == 1)
	                {
	                    free(HeadUser) ;
	                    HeadUser = NULL;
	                }
	                else
	                {
	                    HeadUser=HeadUser->next;
	                    free(temp);
	                }

	            }
	            else if (User_Posision==Global_u8UserNumber-1)
	            { UserNode *temp2;
	                while (temp->next!=TailUser)
	                {
	                    temp=temp->next;
	                }
	                temp->next=NULL;
	                temp2=TailUser;
	                free(temp2);
	                TailUser=temp;
	            }
	            else
	            {
	                UserNode *past=HeadUser;
	                UserNode *curr=HeadUser->next;
	                for (int i=1; i<User_Posision; i++)
	                {
	                    past=past->next;
	                    curr=curr->next;
	                }
	                past->next=curr->next;
	                free(curr);

	            }
	            Global_u8UserNumber--;
	            printf("The Deletion is Done :)\n");
	        }
	        else
	        {
	            printf("Incorrect Account ,You don't reseve before :)\n");
	        }
	    }

	    u8 PasswordIsCorrect_OR_Not(u8 Copy_u8EnteredPassword[],u8 Copy_u8Index)
	    {
	        UserNode *Curr=HeadUser;
	        for(u8 i=0;i<Copy_u8Index;i++)
	        {
	            Curr=Curr->next;
	        }
	        if(strlen(Copy_u8EnteredPassword)==strlen(Curr->data.User_Password))
	        {
	            for(u8 i=0;i<strlen(Copy_u8EnteredPassword);i++)
	            {
	                if(Copy_u8EnteredPassword[i]!=Curr->data.User_Password[i])
	                {
	                    return 1;
	                }
	            }
	        }
	        else
	        {
	            return 1;
	        }

	        return 0;
	    }

	    void EditingReservation(u8 Name[])
	    {
	        s8 position=NameIsExist(Name);
	        if(position!=-1)
	        {

	            UserNode *temp=HeadUser;
	            for (int i = 0; i <position ; ++i)
	            {
	                temp=temp->next;
	            }
	            printf("\nPLease ,Enter new data :");
	            printf("\nEnter the Name please :");
	            gets(temp->data.User_Name);
	            printf("\nEnter the Age please :");
	            scanf("%d", &temp->data.User_Password);

	            printf("\nThe editing information succeeded :)\n");

	        }
	        else
	        {
	            printf("Incorrect Name ,You don't Make account before :)\n");
	        }

	    }

