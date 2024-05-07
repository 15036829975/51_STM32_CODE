#include "stm32f10x.h"                  // Device header
#include "bsp.h"
#include "stdio.h"
void bsp_Init(void)
{
		Colorful_GPIO_Init();				/*七彩探照灯*/
//		MOTOR_GPIO_Init();  				/*电机GPIO初始化*/
//		Motor_PWM_Init(7200,0, 7200, 0);	/*不分频。PWM频率 72000000/7200=10khz	 */
//		Servo_GPIO_Init();					/*伺服电机GPIO初始化*/	
//    TIM1_Int_Init(9, 72);			/*计数到10为10us   Tout = (9+1)*(71+1)/72M = 10us */ 
		  LineWalking_GPIO_Init();  //寻线传感器
	//	IRAvoid_GPIO_Init();          //避障传感器
	//  LightSeeking_GPIO_Init();      //寻光初始化
//	  Ultrasonic_GPIO_Init();           //超声波GPIO初始化
//	  bsp_Ultrasonic_Timer2_Init();      //超声波TIM2初始化
    	Uart1_Init(9600);               //串口初始化
	    Adc_Init();
	
	
//	  printf("Init OK");
}
