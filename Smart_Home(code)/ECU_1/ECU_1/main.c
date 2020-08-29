/*
 * ECU_1.c
 *
 * Created: 8/25/2020 1:08:09 PM
 * Author : mohammed
 */ 


#include "bluetooth.h"
#include "LCD.h"
#define F_CPU 8000000
#include <util/delay.h>
#include "LED.h"
#include "SPI.h"
#include "Buzzer.h"


int main(void)
{
	
	uint8 RX_Data = 0;// for UART
	
	uint8 tx_data = 0;// for spi
	
	uint8 val = 0;// tx for uArt
	
	
	Bluetooth_Init();
	
	SPI_Master_Init();
	
	SPI_Master_InitTrans();
	
	_delay_ms(1000);

	LCD_Init();
	
	Buzzer_Init();
	///////////////////////////////////////////////////////
	uint8 times = 0;
	
	while(1)
	{
	uint16 temp = 0 ;
	uint8 password[4]={'1','1','1','1'};
	uint8 try[4];
	uint8 value=0;
	uint8 i=0;
	
	
	LCD_Clear();
	LCD_WriteString("ENTER PASSWORD");
	LCD_GoTo(1,0);
	
	while(i<4)
	{
		RX_Data = Bluetooth_ReceiveChar();
		LCD_WriteChar(RX_Data);
		_delay_ms(200);
		LCD_WriteCommand(0x10);
		LCD_WriteChar('*');
		
		
		try[i]=RX_Data;
		i++;
	}
	if ((password[0]==try[0])&&(password[1]==try[1])&&(password[2]==try[2])&&(password[3]==try[3]))
	{
		LCD_Clear();
		LCD_WriteString("correct");
		_delay_ms(1000);
		LCD_Clear();
		LCD_WriteString("(1)Red Light");
		LCD_GoTo(1 , 0);
		LCD_WriteString("(2)Blue Light");
		_delay_ms(1000);
		LCD_Clear();
		LCD_WriteString("(3)close red");
		LCD_GoTo(1 , 0);
		LCD_WriteString("(4)close blue");
		_delay_ms(1000);
		LCD_Clear();
		LCD_WriteString("(5)Measure Temp");
		
		
		
		
		while (1)
		{
			
			
			RX_Data = Bluetooth_ReceiveChar();
			
			_delay_ms(100);
			
			val = SPI_TranSiver(RX_Data);
		}
		
			
	}
	else if ((password[0]!=try[0])||(password[1]!=try[1])||(password[2]!=try[2])||(password[3]!=try[3]))
	{
		LCD_Clear();
		LCD_WriteString("Wrong Password");
		_delay_ms(1000);
		times++;
	}
	
	if(times == 4)
	{
		LCD_Clear();
		LCD_WriteString("wait 10 Sec");
		Buzzer_ON();
		_delay_ms(10000);
		Buzzer_OFF();
		LCD_Clear();
		times = 0;
	}
	
	}//for while times
	
	/////////////////////////////////////////////////////////////////
	
	
}