#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
#include "Key.h"
#include "Led.h"
#include <string.h>


int main(void)
{
	/*模块初始化*/
	OLED_Init();		//OLED初始化
	
	/*显示静态字符串*/
	OLED_ShowString(1, 1, "TxPacket");
	OLED_ShowString(3, 1, "RxPacket");
		
	Serial_Init();		

	LED_Init();
	
	
	
	while (1)
	{
		if(Serial_GetRxFlag() == 1)
		{
		OLED_ShowString(4,1,"                ");
		OLED_ShowString(4,1,Serial_RxPacket);
    if(strcmp(Serial_RxPacket,"LED_ON") == 0)
		{
		LED1_ON();
		OLED_ShowString(2,1,"                ");
		OLED_ShowString(2,1,"LED_ON_OK");
		}
		else  if(strcmp(Serial_RxPacket,"LED_OFF") == 0)
		{
		LED1_OFF();
		OLED_ShowString(2,1,"                ");
		OLED_ShowString(2,1,"LED_OFF_OK");

		}
		else
		{
		OLED_ShowString(2,1,"                ");
		OLED_ShowString(2,1,"ERROR_COMMAND");

		}
		}
		
	}
}
