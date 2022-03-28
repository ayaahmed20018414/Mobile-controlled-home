


#ifndef TIMER_REG_H_
#define TIMER_REG_H_


/*Timer 0 Registers*/


/*Timer/Counter Control Register*/
#define TCCR0_REG *((volatile u8*)0x53)

enum TCCR0_R{

	              TCCR0_CS00,
		          TCCR0_CS01,
			      TCCR0_CS02,
			      TCCR0_WGM01,
			      TCCR0_COM00,
				  TCCR0_COM01,
				  TCCR0_WGM00,
				  TCCR0_FOC0,
			};

/*Timer/Counter0 Output Compare Register*/
#define OCR0_REG *((volatile u8*)0x5C)

/*Timer0 Value */
#define TCNT0_REG *((volatile u8*)0x52)


/*=================================================================End Timer0==============================================================*/


/*Timer 1 Registers*/
/*Timer/Counter1 Control Register A */

#define TCCR1A_REG *((volatile u8*)0x4F)
enum TCCR1A_R{
	        TCCR1A_WGM10 ,
			TCCR1A_WGM11 ,
			TCCR1A_FOC1B ,
			TCCR1A_FOC1A ,
			TCCR1A_COM1B0,
			TCCR1A_COM1B1,
		    TCCR1A_COM1A0,
			TCCR1A_COM1A1,
			};
/*Timer/Counter1 Control Register B*/
#define TCCR1B_REG *((volatile u8*)0x4E)

enum TCCR1B_R{
	       TCCR1B_CS10   ,
		   TCCR1B_CS11   ,
		   TCCR1B_CS12   ,
		   TCCR1B_WGM12  ,
		   TCCR1B_WGM13  ,
		   TCCR1B_ICES1=6,
		   TCCR1B_ICNC1
			};

/*Timer/Counter1 – Counter Register High Byte*/
#define TCNT1H_REG *((volatile u8*)0x4D)

/*Timer/Counter1 – Counter Register Low Byte*/
#define TCNT1L_REG *((volatile u8*)0x4C)

/*Timer/Counter1 – Output Compare Register A High Byte*/
#define OCR1AH_REG *((volatile u8*)0x4B)

/*Timer/Counter1 – Output Compare Register A Low Byte*/
#define OCR1AL_REG *((volatile u8*)0x4A)

/*Timer/Counter1 – Output Compare Register B High Byte*/
#define OCR1BH_REG *((volatile u8*)0x49)

/*Timer/Counter1 – Output Compare Register B Low Byte*/
#define OCR1BL_REG *((volatile u8*)0x48)

/*Timer/Counter1 – Input Capture Register High Byte*/
#define ICR1H_REG *((volatile u8*)0x47)

/*Timer/Counter1 – Input Capture Register Low Byte*/
#define ICR1L_REG *((volatile u8*)0x46)


/*=================================================================End Timer1==============================================================*/
/*Timer2 Registers*/

/*Timer/Counter Control Register*/
#define TCCR2_REG *((volatile u8*)0x45)
enum TCCR2_R{
	TCCR2_CS20 ,
	TCCR2_CS21 ,
	TCCR2_CS22 ,
	TCCR2_WGM21,
	TCCR2_COM20,
	TCCR2_COM21,
	TCCR2_WGM20,
	TCCR2_FOC2 ,
			};
/*Timer/Counter2 (8 Bits)*/
#define TCNT2_REG *((volatile u8*)0x44)

/*Timer/Counter2 Output Compare Register*/
#define OCR2_REG *((volatile u8*)0x43)

/*Asynchronous Status Register*/
#define ASSR_REG *((volatile u8*)0x42)


/*=================================================================End Timer2==============================================================*/



/*Timer0 Flags*/
#define TIFR_REG *((volatile u8*)0x58)

/*Timer/Counter Interrupt Mask Register*/
#define TIMSK_REG *((volatile u8*)0x59)
enum TIMSK_R{
	TMR0_TOIE0,
	TMR0_OCIE0,
	TMR1_TOIE1,
	TMR1_OCIE1B,
	TMR1_OCIE1A,
	TMR1_TICIE1,
	TMR2_TOIE2,
	TMR2_OCIE2};

#endif
