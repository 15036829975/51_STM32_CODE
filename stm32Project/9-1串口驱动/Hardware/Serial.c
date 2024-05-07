#include "stm32f10x.h"                  // Device header
#include "stdarg.h"
#include <stdio.h>
	void Serial_Init(void)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
		
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
		GPIO_Init(GPIOA, &GPIO_InitStructure);

		USART_InitTypeDef USART_InitStruture;
		
		USART_InitStruture.USART_BaudRate=9600;
		USART_InitStruture.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
		USART_InitStruture.USART_Mode=USART_Mode_Tx;
		USART_InitStruture.USART_Parity=USART_Parity_No;
		USART_InitStruture.USART_StopBits=USART_StopBits_1;
		USART_InitStruture.USART_WordLength=USART_WordLength_8b;
		USART_Init(USART1,&USART_InitStruture);
		USART_Cmd(USART1,ENABLE);
	}
	
	void Serial_SendByte(uint8_t Byte)
	{
		USART_SendData(USART1,Byte);
		while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	}
	void  Serial_SendArray(uint8_t *Arry,uint16_t Length)
	{
		uint16_t i;
		for(i=0;i<Length;i++)
		{
			
			Serial_SendByte(Arry[i]);
		}
		
		
	}
	
	void Serial_SendString(char *String)
	{
		uint8_t i;
		for(i=0;String[i] !='\0';i++)
		{
			Serial_SendByte(String[i]);
		}
		
	}
	
	uint32_t Serial_Pow(uint32_t X,uint32_t Y)
	{
		uint32_t Result =1;
		while(Y--)
		{
			Result *=X;
		}
		return Result;
	}
	void Serial_SendNum(uint32_t Number,uint8_t Length)
	{
		uint8_t i;
		for(i=0;i<Length;i++)
		{
			Serial_SendByte(Number /Serial_Pow(10,Length-i-1) % 10 + 0x30);
		}
		
	}
	
	int fputc(int ch, FILE *f)  //重新定向printf函数,fputc是printf的底层
	{
		Serial_SendByte(ch);
		return ch;
	}
	void Serial_Printf(char *format,...)
	{
		char String[100];
		va_list arg;
		va_start(arg,format);
		vsprintf(String,format,arg);
		va_end(arg);
		Serial_SendString(String);
	}

	