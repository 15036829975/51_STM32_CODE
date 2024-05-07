#include "stm32f10x.h"
#include "app_motor.h"
#include "app_linewalking.h"
#include "app_IRAvoid.h"
#include "app_IRFllow.h"
#include "app_LightSeeking.h"
#include "app_Ultrasonic.h"
#include "app_LineChack.h"
#include "bsp.h"
#include "stdio.h"




int main(void)
{	
	bsp_Init();
	float fVoltage = 0.0f;
	
//  Angle_J1=90;
//	int iGs=0;
	
	while (1)
	{
		
//		front_detection();
//		bsp_Colorful_Control(1, 0, 0);
//		Delay_ms(500);

//		left_detection();
//		bsp_Colorful_Control(0, 1, 0);
//		Delay_ms(500);

//		right_detection();
//		bsp_Colorful_Control(0, 0, 1);
//		Delay_ms(500);
//		app_LineWalking();
//			app_IRAvoid();
		
		//ºìÍâ¸úËæ
//		app_IRFllow();
		//Ð¡³µÑ°¹â
//		app_LightSeeking();
		
		//³¬Éù²¨±ÜÕÏ
//		app_ultrasonic_mode();

//  app_ultrasonic_servo_mode();
		
		
//		iGs= Get_GS_Value();
//		printf("Color:%d\r\n",iGs);
			
//		app_LineChack();
   fVoltage = Get_Battery_Volotage();
	 printf("V:%f",fVoltage);

	}
 								    
}
