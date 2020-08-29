/*
 * bluetooth.c
 *
 * Created: 8/26/2020 8:05:43 AM
 *  Author: mohammed
 */ 

#include "bluetooth.h"


void Bluetooth_Init(void)
{
	UART_Init();
}

void Bluetooth_SendChar(uint8 data)
{
	UART_SendChar(data);
}

void Bluetooth_SendString(uint8* str)
{
	UART_SendString(str);
}

uint8 Bluetooth_ReceiveChar(void)
{
	uint8 data = 0;
	
	data = UART_ReceiveChar();
	
	return data;
}