#include "stm32f10x.h"                  // Device header
#include "bsp.h"
#include "stdio.h"
void bsp_Init(void)
{
		Colorful_GPIO_Init();				/*�߲�̽�յ�*/
//		MOTOR_GPIO_Init();  				/*���GPIO��ʼ��*/
//		Motor_PWM_Init(7200,0, 7200, 0);	/*����Ƶ��PWMƵ�� 72000000/7200=10khz	 */
//		Servo_GPIO_Init();					/*�ŷ����GPIO��ʼ��*/	
//    TIM1_Int_Init(9, 72);			/*������10Ϊ10us   Tout = (9+1)*(71+1)/72M = 10us */ 
		  LineWalking_GPIO_Init();  //Ѱ�ߴ�����
	//	IRAvoid_GPIO_Init();          //���ϴ�����
	//  LightSeeking_GPIO_Init();      //Ѱ���ʼ��
//	  Ultrasonic_GPIO_Init();           //������GPIO��ʼ��
//	  bsp_Ultrasonic_Timer2_Init();      //������TIM2��ʼ��
    	Uart1_Init(9600);               //���ڳ�ʼ��
	    Adc_Init();
	
	
//	  printf("Init OK");
}
