


#ifndef ADC_REG_H_
#define ADC_REG_H_


/*MCU Control and Status Register*/
#define SFIOR_REG *((volatile u8*)0x50)

/* ADC Multiplexer Selection Register To select Channel  and Vref and Justification*/
#define ADMUX_REG *((volatile u8*)0x27)

/*ADC Control and Status Register A – ADCSRA to Enable the ADC , Start Conversion, Prescaller to clock*/
#define ADCSRA_REG *((volatile u8*)0x26)

/*ADC Result Register High*/
#define ADCH_REG *((volatile u8*)0x25)

/*ADC Result Register Low*/
#define ADCL_REG *((volatile u8*)0x24)

#define ADC_10_BIT_RESULT *((volatile u16*)0x24)
#endif
