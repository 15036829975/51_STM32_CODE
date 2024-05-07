#include "stm32f10x.h"                  // Device header
#include "app_motor.h"
#include "app_IRAvoid.h"
#include "bsp.h"
	void app_IRAvoid(void)
	{
		int IRL1=1,IRR1=1;
		bsp_GetIRAvoid(&IRL1,&IRR1);
		
		//ÓÒ¼ì²â
		if(IRL1 == HIGH && IRR1 == LOW )
		{
			Car_SpinLeft(3600,3600);
		}
		//×ó¼ì²â
		else if(IRL1 == LOW && IRR1 == HIGH)
		{
			Car_SpinRight(3600,3600);
		}
		//×óÓÒÎ´¼ì²âµ½
		else if(IRL1 == HIGH && IRR1 == HIGH)
		{
			Car_Run(3600);
		}
//		//×óÓÒ¾ù¼ì²âµ½
//		else if(IRL1 == LOW && IRR1 == LOW)
//		{
//			Car_SpinRight(1200,1200);
//			Delay_ms(500);
//		}
	}
