#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "Buzzer.H"
#include "LightSensor.h"
#include "LED.h"
int main(void)
{
	LED_Init();
	Buzzer_Init();
	LightSensor_Init();
		while(1)
		{
			
				if(LightSensor_Get() == 1)
				{
					Buzzer_ON();
					LED1_OFF();
				}
				else
				{
					Buzzer_OFF();
					LED1_ON();
				}
			
			
		}
	
}
