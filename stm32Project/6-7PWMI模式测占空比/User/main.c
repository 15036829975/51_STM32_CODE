#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "IC.h"

uint8_t i;
int main(void)
{
	OLED_Init();
	IC_Init();
	OLED_ShowString(1,1,"Freq:000000Hz");
	OLED_ShowString(2,1,"Duty:00%");
	PWM_Init();
	PWM_SetPrescaler(72-1);       //Freq = 72M / (PSC+1) / 100;
	PWM_SetCompare1(60);           //Duty = CCR / 100;
	
	while(1)
	{
		OLED_ShowNum(1,6,IC_GetFreq(),5);
		OLED_ShowNum(2,6,IC_GetDuty(),2);
	}
}
