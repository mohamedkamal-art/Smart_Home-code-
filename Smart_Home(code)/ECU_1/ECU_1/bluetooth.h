/*
 * bluetooth.h
 *
 * Created: 8/26/2020 8:05:27 AM
 *  Author: mohammed
 */ 


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "UART.h"

void Bluetooth_Init(void);

void Bluetooth_SendChar(uint8 data);

void Bluetooth_SendString(uint8* str);

uint8 Bluetooth_ReceiveChar(void);






#endif /* BLUETOOTH_H_ */