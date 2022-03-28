


#ifndef EXTERNAL_INTERRUPT_REG_H_
#define EXTERNAL_INTERRUPT_REG_H_

/* Status Register has I_Pin witch act as GIE */
#define SREG_REG *((volatile u8*)0x5F)

/*General Interrupt Control (PIE for each External Interrupt Pins)*/
#define GICR_REG *((volatile u8*)0x5B)

/*General Interrupt Flag to show the flags of all External Interrupt Pins*/
#define GIFR_REG *((volatile u8*)0x5A)

/*MCU Control Register contains control bits for interrupt sense control and general MCU functions*/
#define MCUCR_REG *((volatile u8*)0x55)

/*MCU Control and Status Register*/
#define MCUCSR_REG *((volatile u8*)0x54)

#endif
