/*
 * INTERFACE.h
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */


#ifndef ADC_INTERFACE_H_
#define ADC_INTERRUPT_INTERFACE_H_

#define pre_2    1
#define pre_4    2
#define pre_8    3
#define pre_16   4
#define pre_32   5
#define pre_64   6
#define pre_128  7

#define  ADC_PRE_CLR_MASK  0b11111000

extern void ADC_VidInit (void) ;
extern u16 ADC_VidGetDigitalRead (u8 copy_u8Channel) ;
#define pre  pre_64


/*ADMUX register*/
/*its bits*/
enum ADMUX
	{
	MUX0,
	MUX1,
	MUX2,
	MUX3,
	MUX4,
	ADLAR,
	REFS0,
	REFS1
	  };
/*
 * to select Mode ended ,Gain
 */
/*for first 5 Bits in ADMUX MUX0:MUX4 to select Channel */
#define SELECT_ENDED_CHANNEL_MASK              0b11100000
#define SINGLE_ENDED_CHANNEL_ADC0              (u8)0x00
#define SINGLE_ENDED_CHANNEL_ADC1              (u8)0x01
#define SINGLE_ENDED_CHANNEL_ADC2              (u8)0x02
#define SINGLE_ENDED_CHANNEL_ADC3              (u8)0x03
#define SINGLE_ENDED_CHANNEL_ADC4              (u8)0x04
#define SINGLE_ENDED_CHANNEL_ADC5              (u8)0x05
#define SINGLE_ENDED_CHANNEL_ADC6              (u8)0x06
#define SINGLE_ENDED_CHANNEL_ADC7              (u8)0x07
#define DIFFERNTIAL_ENDED_ADC0_ADC0_GAIN_10    (u8)0x08
#define DIFFERNTIAL_ENDED_ADC1_ADC0_GAIN_10    (u8)0x09
#define DIFFERNTIAL_ENDED_ADC0_ADC0_GAIN_200   (u8)0x0A
#define DIFFERNTIAL_ENDED_ADC1_ADC0_GAIN_200   (u8)0x0B
#define DIFFERNTIAL_ENDED_ADC2_ADC2_GAIN_10    (u8)0x0C
#define DIFFERNTIAL_ENDED_ADC3_ADC2_GAIN_10    (u8)0x0D
#define DIFFERNTIAL_ENDED_ADC2_ADC2_GAIN_200   (u8)0x0E
#define DIFFERNTIAL_ENDED_ADC3_ADC2_GAIN_200   (u8)0x0F
#define DIFFERNTIAL_ENDED_ADC0_ADC1_GAIN_1     (u8)0x10
#define DIFFERNTIAL_ENDED_ADC1_ADC1_GAIN_1     (u8)0x11
#define DIFFERNTIAL_ENDED_ADC2_ADC1_GAIN_1     (u8)0x12
#define DIFFERNTIAL_ENDED_ADC3_ADC1_GAIN_1     (u8)0x13
#define DIFFERNTIAL_ENDED_ADC4_ADC1_GAIN_1     (u8)0x14
#define DIFFERNTIAL_ENDED_ADC5_ADC1_GAIN_1     (u8)0x15
#define DIFFERNTIAL_ENDED_ADC6_ADC1_GAIN_1     (u8)0x16
#define DIFFERNTIAL_ENDED_ADC7_ADC1_GAIN_1     (u8)0x17
#define DIFFERNTIAL_ENDED_ADC0_ADC2_GAIN_1     (u8)0x18
#define DIFFERNTIAL_ENDED_ADC1_ADC2_GAIN_1     (u8)0x19
#define DIFFERNTIAL_ENDED_ADC2_ADC2_GAIN_1     (u8)0x1A
#define DIFFERNTIAL_ENDED_ADC3_ADC2_GAIN_1     (u8)0x1B
#define DIFFERNTIAL_ENDED_ADC4_ADC2_GAIN_1     (u8)0x1C
#define DIFFERNTIAL_ENDED_ADC5_ADC2_GAIN_1     (u8)0x1D
#define SINGLE_ENDED_VGB                       (u8)0x1E
#define SINGLE_ENDED_GROUND                    (u8)0x1F

/*for last 2 Bits in ADMUX REFS1,REFS0 */
/*
0 0 AREF, Internal Vref turned off
0 1 AVCC with external capacitor at AREF pin
1 0 Reserved
1 1 Internal 2.56V Voltage Reference with external capacitor at AREF pin
*/
#define SELECT_VREF_MASK  0b00111111
#define Normal_Aref    0<<6
#define AVCC_WITH_Aref 1<<6
#define INTERNAL_Vref  3<<6
/*
 * RIGH_justfication      0
 * – – – –   –                   ADC9 ADC8  ADCH
 * ADC7 ADC6 ADC5 ADC4 ADC3 ADC2 ADC1 ADC0  ADCL
 *
 * LEFT_justfication       1
 * ADC9 ADC8 ADC7 ADC6 ADC5 ADC4 ADC3 ADC2  ADCH
 * ADC1 ADC0 – – – – – –                    ADCL
 *
 */
#define LEFT_JUSTFICATION  (u8)1
#define RIGHT_JUSTFICATION (u8)0

/*==============================================================================================================================*/

/*ADCSRA Bits Configurations*/
enum ADCSRA{
	ADPS0,
	ADPS1,
	ADPS2,
	ADIE,
	ADIF,
	ADATE,
	ADSC,
	ADEN};
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
/*
 * Bit 3 – ADIE: ADC Interrupt Enable
 * Bit 4 – ADIF: ADC Interrupt Flag
 * Bit 5 – ADATE: ADC Auto Trigger Enable
 * Bit 6 – ADSC: ADC Start Conversion
 * Bit 7 – ADEN: ADC Enable
 */
#define SELECT_PRESCALER_MASK  0b11111000
enum ADC_PRESACLEERS{
	ADC_PRESCALER_DIV_1,
	ADC_PRESCALER_DIV_2,
	ADC_PRESCALER_DIV_4,
	ADC_PRESCALER_DIV_8,
	ADC_PRESCALER_DIV_16,
	ADC_PRESCALER_DIV_32,
	ADC_PRESCALER_DIV_64,
	ADC_PRESCALER_DIV_128
					};


/*==============================================================================================================================*/

/*Special FunctionIO Register–SFIOR*/
enum SFIOR{ADTS0=5, ADTS1, ADTS2};
/*Select Auto Trigger Source*/
#define SELECT_AUTO_TRIGER_SOURSE_MASK            0b00011111
#define FREE_RUNNING_MODE                    0<<5
#define ANALOG_COMPARATOR_MODE               1<<5
#define EXTI_REQUEST_MODE	                 2<<5
#define TIMMER_CONNTER0_COMPARE_MATCH_MODE   3<<5
#define TIMMER_CONNTER0_OVERFLOW_MODE        4<<5
#define TIMMER_CONNTER_COMPARE_MATCH_B_MODE  5<<5
#define TIMMER_CONNTER1_OVERFLOW_MODE        6<<5
#define TIMMER_CONNTER1_CAPTURE_EVENT_MODE   7<<5


/*==============================================================================================================================*/

/*to Enable the interrupt or Not*/
#define ENABLE   1
#define DISABLE  0



/*function to Enable or Disable the ADC as Interrupt in Postbuild
 * input :EXTI_Pin_No,Enable or Disable
 * return : error status
 */
extern void ADC_VoidModeChannleAndAdjustmentAndVrefSelect_Postbuild(u8 Copy_u8Justfication,u8 Copy_u8Vref,u8 Copy_u8EN_DIS_AutoTrigger,u8 Copy_u8AutoTriggerSource,u8 Copy_u8PreScaler,u8 EN_DIS_INT);

/*function to Initialize the ADC
 * input :void
 * return :no return*/

extern void ADC_VoidInit_PreBuild();

/*function to select Channel and start Conversion with Polling Mode
 *Input:Channel Select , pionter to Channel reading (digital value of ADCH,ADCL)
 *Output :return Error Status
 */
extern u8 ADC_u8GetDigitalValChannel(u8 Copy_u8Channel ,u16* Reading_Channel);
/*function to select Channel and start Conversion with Enable Interrupt
 *Input:Channel Select , pionter to Channel reading (digital value of ADCH,ADCL),Pionter to function notification the Interrupt is completed
 *Output :return Error Status
 */
extern u8 ADC_u8GetDigitalValChannelAsynchronus(u8 Copy_u8Channel,u16 *Reading_Channel,void(*ADC_Notifications)(void));
/*function to select Channel and start Conversion
 *Input:Channel Select
 *Output :return Analog value of ADCH,ADCL
 */
extern u8 ADC_u8AdjustmentSelect_Postbuild(u8 Copy_u8Justfication);

/*function to Select Vref of the ADC
 * input :Vref
 * return :no return*/
extern void ADC_VoidVrefSelect_Postbuild(u8 Copy_u8Vref);

/*function to Select Prescaler of the ADC
 * input :Prescaler
 * return :error status
*/

extern void ADC_VoidPrescalerSelect_Postbuild(u8 Copy_u8Prescaler);

/*function to Power ON or OFF the ADC
 * input :Enable/Disable
 * return :no return*/
extern u8 ADC_u8ONO_OFFStateSelect_Postbuild(u8 Copy_u8ADC_State);
/*function to Power ON or OFF the ADC
 * input :Enable/Disable   ,AutoTrigger_source_selection
 * return :error status*/
extern u8 ADC_u8AutoTriggerEnable_Postbuild(u8 Copy_u8ADC_AutoTriggerEnable,u8 Copy_u8TriggerSource);
/*CallBack Function*/
//u8 SendAddress_Callback(void (*ISR_ADC)(void));

#endif
