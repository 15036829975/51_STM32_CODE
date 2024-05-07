#include "stm32f10x.h"                  // Device header
#include "app_LightSeeking.h" 
#include "app_motor.h" 
#include "bsp.h"

  void app_LightSeeking(void)
	{
		int L1 = 1, R1 = 1;
		bsp_GetLightSeeking(&L1,0,&R1,0);
		if(L1 == LOW && R1 == HIGH)
		{
			Car_SpinRight(2500,2000);
		}
		else if(L1 == HIGH && R1 == LOW)
		{
			Car_SpinLeft(2000,2500);
		}
		else if(L1 == HIGH && R1 == HIGH)
		{
			Car_Run(3000);
		}
		else if(L1 == LOW && R1 == LOW)
		{
			Car_Stop();
		}
	}

	