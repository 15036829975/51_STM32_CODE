#include "stm32f10x.h"                  // Device header
#include "bsp.h"
#include "app_motor.h"
#include "app_IRFllow.h"
		void app_IRFllow(void)
		{
			int IRL1=1,IRR1=1;
			bsp_GetIRAvoid(&IRL1,&IRR1);
			if( IRL1 == HIGH && IRR1 == LOW)
			{
				Car_SpinRight(3600,3600);
				Angle_J1= 180;
				bsp_Colorful_Control(0,1,0);
			}
			else if(IRL1 == LOW && IRR1 == HIGH)
			{
				Car_SpinLeft(3600,3600);
				Angle_J1= 0;
				bsp_Colorful_Control(0,0,1);
			}
			else if(IRL1 ==HIGH && IRR1 ==HIGH)
			{
				Car_Stop();
				Angle_J1= 90;
				bsp_Colorful_Control(1,0,0);
			}
			else if(IRL1 == LOW && IRR1 == LOW)
			{
				Car_Run(3600);
				Angle_J1= 90;
				bsp_Colorful_Control(1,1,1);
			}
		}
		