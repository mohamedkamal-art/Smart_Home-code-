/*
 * ECU_2.c
 *
 * Created: 8/25/2020 1:34:32 PM
 * Author : mohammed
 */ 

#include "SPI.h"
#define F_CPU 8000000
#include <util/delay.h>
#include "LCD.h"
#include "Temp_Sensor.h"


int main(void)
{
	uint8 Recived_Data = 0;
	uint8 val = 0;
	uint8 temp = 0;
	
	LED0_Init();
	LED1_Init();
	LCD_Init();
	SPI_Slave_Init();
	TempSensor_Init();
	
	
	
	while (1)
	{
		Recived_Data = SPI_TranSiver(val);
		
		if(Recived_Data == '1')
		{
			LED0_ON();
			LCD_Clear();
			LCD_WriteString("RED LIGHT");
			
			Recived_Data = 0;
		}
		
		else if(Recived_Data == '2')
		{
			LED1_ON();
			LCD_Clear();
			LCD_WriteString("Blue LIGHT");
			
			Recived_Data = 0;
		}
		
		else if(Recived_Data == '3')
		{
			LED0_OFF();
			LCD_Clear();
			LCD_WriteString("close RED");
			
			Recived_Data = 0;
		}
		
		else if(Recived_Data == '4')
		{
			LED1_OFF();
			LCD_Clear();
			LCD_WriteString("close Blue");
			
			Recived_Data = 0;
		}
		
		else if(Recived_Data == '5')
		{
			TempSensor_Read(&temp);
			
			LCD_Clear();
			
			LCD_WriteInteger(temp);
			LCD_WriteString("Degree");
			
			_delay_ms(500);
			
			Recived_Data = 0;
		}
		
		
	}
}
