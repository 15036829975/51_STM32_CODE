#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "LED.h"
#include "Moter.h"

int main(void)
{

	
	LED_Init();
	while(1)
	{
		LED1_ON();
	}
	
}
