#include "stm32f10x.h"                  // Device header
#include "bsp.h"
#include "app_motor.h"
	void app_LineChack(void)
	{
		int LineL1=1,LineL2=1,LineR1=1,LineR2=1;
		bsp_GetLightSeeking(&LineL1,&LineL2,&LineR1,&LineR2);
		if(LineL2==LOW || LineR2== LOW || LineL1==LOW || LineR1 == LOW)
		{
			Car_Back(2000);
			Delay_ms(1000);
			Car_Left(2000);
			Delay_ms(1000);
		}
		else
		{
			Car_Run(2000);
		}
	}
	
	
	