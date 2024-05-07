#include "stm32f10x.h"
#include "bsp.h"
void bsp_Colorful_Control(int v_RedOnOff, int v_GreenOnOff, int v_BlueOnOff)
{
	if(v_RedOnOff == 1)
	{
		GPIO_SetBits(Colorful_Red_PORT, Colorful_Red_PIN);
	}
	else
	{
		GPIO_ResetBits(Colorful_Red_PORT, Colorful_Red_PIN);
	}

	if(v_GreenOnOff == 1)
	{
		GPIO_SetBits(Colorful_Green_PORT, Colorful_Green_PIN);
	}
	else
	{
		GPIO_ResetBits(Colorful_Green_PORT, Colorful_Green_PIN);
	}

	if(v_BlueOnOff == 1)
	{
		GPIO_SetBits(Colorful_Blue_PORT, Colorful_Blue_PIN);
	}
	else
	{
		GPIO_ResetBits(Colorful_Blue_PORT, Colorful_Blue_PIN);
	}
}
