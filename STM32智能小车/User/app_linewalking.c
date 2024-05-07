#include "stm32f10x.h"                  // Device header
#include "app_linewalking.h"
#include "bsp.h"
#include "app_motor.h"



	void app_LineWalking(void)
	{
//		int LineL1=1, LineL2=1, LineR1=1, LineR2=1;
		
//		bsp_GetLineWalking(&LineL1,&LineL2,&LineR1,&LineR2);
		
//		if((LineL1 == LOW  || LineL2 == LOW )&& LineR2 == LOW )//左弯
//		{
//			Car_SpinLeft(2000,2000);
//			Delay_ms(80);
//		}
//		 if(LineL1 == LOW  && (LineR1 == LOW || LineR2 == LOW) )//右弯
//		{
//			Car_SpinRight(2000,2000);
//			Delay_ms(80);
//		}
//		 if(LineL1 == LOW)
//		{
//			Car_SpinLeft(1500,1500);
//			Delay_ms(10);
//		}
//		else if(LineR2 == LOW)
//		{
//			Car_SpinLeft(1500,1500);
//			Delay_ms(10);
//		}
//		else if(LineL2 == LOW  && LineR1 == HIGH)//中间黑线微调左转
//		{
//			Car_Left(1600);
//		}
//		else if(LineL2 == HIGH  && LineR1 == LOW)//中间黑线微调右转
//		{
//			Car_Right(1600);
//		}
//		else if(LineL2 == LOW  && LineR1 == LOW)//加速前进
//		{
//			Car_Run(2000);
//		}
}
