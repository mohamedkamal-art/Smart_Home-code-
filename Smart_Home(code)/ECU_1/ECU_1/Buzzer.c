/*
 * Buzzer.c
 *
 * Created: 7/27/2020 9:49:48 AM
 *  Author: mohammed
 */ 

#include "DIO.h"

void Buzzer_Init(void)
{
	/*Buzzer in port A pin 3*/
	 DIO_SetPinDir(DIO_PORTC ,DIO_PIN0, DIO_PIN_OUTPUT);
}

void Buzzer_ON(void)
{
	DIO_WritePin(DIO_PORTC ,DIO_PIN0, DIO_PIN_HIGH);
}

void Buzzer_OFF(void)
{
	DIO_WritePin(DIO_PORTC ,DIO_PIN0, DIO_PIN_LOW);
}
