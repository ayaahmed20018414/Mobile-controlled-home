/*
 * DIO_Interface.c
 *
 *  Created on: Sep 17, 2021
 *      Author: dell
 */



#include "../../LIB/STDTYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/CHECK_ERROR.h"
#include "PORT_Config.h"
#include "PORT_Interface.h"
#include "PORT_REG.h"
#include "PORT_private.h"

void PORT_VoidInit()
{
DDRA_REG=PORTA_DIR;
DDRB_REG=PORTB_DIR;
DDRC_REG=PORTC_DIR;
DDRD_REG=PORTD_DIR;

PORTA_REG_INITIAL=PORTA_INITIAL_VALUE;
PORTB_REG_INITIAL=PORTB_INITIAL_VALUE;
PORTC_REG_INITIAL=PORTC_INITIAL_VALUE;
PORTD_REG_INITIAL=PORTD_INITIAL_VALUE;

}
