/*
 * PORT_Config.h
 *
 *  Created on: Sep 28, 2021
 *      Author: dell
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


#define TIME_OUT_WAITING 500000
/*ADMUX register*/
/*for first 5 Bits in ADMUX MUX0:MUX4 */
/*
 * 00000 Single Ended Channel ADC0
 * 00001 Single Ended Channel ADC1
 * 00010 Single Ended Channel ADC2
 * 00011 Single Ended Channel ADC3
 * 00100 Single Ended Channel ADC4
 * 00101 Single Ended Channel ADC5
 * 00110 Single Ended Channel ADC6
 * 00111 Single Ended Channel ADC7
 * 01000 Differential Ended Channel ADC0+ ADC0- ,Gain(10) for testing and noise detection
 * 01001 Differential Ended Channel ADC1+ ADC0-
 * 01010 Differential Ended Channel ADC0+ ADC0- ,Gain(200)
 * 01011 Differential Ended Channel ADC1+ ADC0- ,Gain(200)
 * 01100 Differential Ended Channel ADC2+ ADC2- ,Gain(10)
 * 01101Differential Ended Channel ADC3+ ADC2- , Gain(10)
 * 01110 Differential Ended Channel ADC2+ ADC2- ,Gain(200)
 * 01111 Differential Ended Channel ADC3+ ADC2- ,Gain(200)
 * 10000 Differential Ended Channel ADC0+ ADC1- ,Gain(1)
 * 10001 Differential Ended Channel ADC1+ ADC1- ,Gain(1)
 * 10010 Differential Ended Channel ADC2+ ADC1- ,Gain(1)
 * 10011 Differential Ended Channel ADC3+ ADC1- ,Gain(1)
 * 10100 Differential Ended Channel ADC4+ ADC1- ,Gain(1)
 * 10101 Differential Ended Channel ADC5+ ADC1- ,Gain(1)
 * 10110 Differential Ended Channel ADC6+ ADC1- ,Gain(1)
 * 10111 Differential Ended Channel ADC7+ ADC1- ,Gain(1)
 * 11000 Differential Ended Channel ADC0+ ADC2- ,Gain(1)
 * 11001 Differential Ended Channel ADC1+ ADC2- ,Gain(1)
 * 11010 Differential Ended Channel ADC2+ ADC2- ,Gain(1)
 * 11011 Differential Ended Channel ADC3+ ADC2- ,Gain(1)
 * 11100 Differential Ended Channel ADC4+ ADC2- ,Gain(1)
 * 11101 Differential Ended Channel ADC5+ ADC2- ,Gain(1)
 */

#define ADMUX_MUX0      0
#define ADMUX_MUX1      0
#define ADMUX_MUX2      0
#define ADMUX_MUX3      0
#define ADMUX_MUX4      0
/*
 * RIGH_Adjustment    0
 * – – – –   –                   ADC9 ADC8  ADCH
 * ADC7 ADC6 ADC5 ADC4 ADC3 ADC2 ADC1 ADC0  ADCL
 *
 * LEFT_Adjustment    1
 * ADC9 ADC8 ADC7 ADC6 ADC5 ADC4 ADC3 ADC2  ADCH
 * ADC1 ADC0 – – – – – –                    ADCL
 *
 */
#define ADMUX_ADLAR     0
/*for last 2 Bits in ADMUX REFS1,REFS0 */
/*
0 0 AREF, Internal Vref turned off
0 1 AVCC with external capacitor at AREF pin
1 0 Reserved
1 1 Internal 2.56V Voltage Reference with external capacitor at AREF pin
*/
#define ADMUX_REFS0     1
#define ADMUX_REFS1     0

/*==============================================================================================================================*/

/*ADCSRA Bits Configurations*/
/*first 3 Bits To select ADC Prescaler for clock*/
/* 0 0 0 Division Factor 2
 * 0 0 1 Division Factor 2
 * 0 1 0 Division Factor 4
 * 0 1 1 Division Factor 8
 * 1 0 0 Division Factor 16
 * 1 0 1 Division Factor 32
 * 1 1 0 Division Factor 64
 * 1 1 1 Division Factor 128
 */
#define ADCSRA_ADPS0  0
#define ADCSRA_ADPS1  1
#define ADCSRA_ADPS2  1
/*
 * Bit 3 – ADIE: ADC Interrupt Enable
 * Bit 4 – ADIF: ADC Interrupt Flag
 *  Bit 5 – ADATE: ADC Auto Trigger Enable
 * Bit 6 – ADSC: ADC Start Conversion
 * Bit 7 – ADEN: ADC Enable
 */

#define ADCSRA_ADIE   0
#define ADCSRA_ADIF   0
#define ADCSRA_ADATE  0
#define ADCSRA_ADSC	  0
#define ADCSRA_ADEN   1

/*==============================================================================================================================*/

/*Special FunctionIO Register–SFIOR*/
/*Select Auto Trigger Source*/
/*  0 0 0 Free Running mode
 *  0 0 1 Analog Comparator
 *  0 1 0 External Interrupt Request 0
 *  0 1 1 Timer/Counter0 Compare Match
 *  1 0 0 Timer/Counter0 Overflow
 *  1 0 1 Timer/Counter Compare Match B
 *  1 1 0 Timer/Counter1 Overflow
 *  1 1 1 Timer/Counter1 Capture Event
 */
#define SFIOR_ADTS0  (u8)0
#define SFIOR_ADTS0  (u8)0
#define SFIOR_ADTS0  (u8)0

/*==============================================================================================================================*/

#endif
