#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "Key.h"

int main(void)
{
	OLED_Init();
	Key_Init();
	OLED_ShowString(1,1,"IWGD TEST");
	
	if(RCC_GetFlagStatus(RCC_FLAG_IWDGRST) == SET)
	{
		
		OLED_ShowString(2,1,"Running");
		Delay_ms(500);
		OLED_ShowString(2,1,"       ");
		Delay_ms(500);
		RCC_ClearFlag();
		
	}
	else
	{
		OLED_ShowString(2,1,"RST");
		Delay_ms(500);
		OLED_ShowString(2,1,"       ");
		Delay_ms(500);
		
	}
	
	
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	IWDG_SetPrescaler(IWDG_Prescaler_16);
	IWDG_SetReload(2499);                     //1000ms
	IWDG_ReloadCounter();
	IWDG_Enable();
	while(1)
	{
		
		Key_GetNum();
		
	  IWDG_ReloadCounter();
		
		Delay_ms(999);
	}
}
