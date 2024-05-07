#include "stm32f10x.h"
#include "bsp.h"


void TIM1_Int_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); //ʱ��ʹ��
	
	//��ʱ��TIM3��ʼ��
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler = (psc-1); //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim   //36Mhz
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;    //�ظ������ر�
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 
	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE ); //ʹ��ָ����TIM1�ж�,��������ж�

	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;  //TIM1�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���


	TIM_Cmd(TIM1, ENABLE);  //ʹ��TIMx					 
}

int num = 0;


void TIM1_UP_IRQHandler(void)   //TIM3�ж�
{
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET)  //���TIM3�����жϷ������
	{
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);  //���TIMx�����жϱ�־ 
		num++;
		/*switch(num)
		{
			case 1:  Colorful_Control(1,0,0); break;
			case 2:  Colorful_Control(0,1,0); num = 0; break;
			//case 3:  Colorful_Control(0,0,1); break;
			//case 4:  Colorful_Control(0,1,1); break;
			//case 5:  Colorful_Control(1,1,0); break;
			//case 6:  Colorful_Control(1,0,1); break;
			//case 7:  Colorful_Control(1,1,1); num = 0; break;
			default: break;
		}*/
	

		if(num <= (Angle_J1 * 11 + 500)/10)
		{
			GPIO_SetBits(Servo_J1_PORT, Servo_J1_PIN );		//������ӿڵ�ƽ�ø�
		}
		else
		{
			GPIO_ResetBits(Servo_J1_PORT, Servo_J1_PIN );		//������ӿڵ�ƽ�ø�
		}

		if(num <= (Angle_J2 * 11 + 500)/10)
		{
			GPIO_SetBits(Servo_J2_PORT, Servo_J2_PIN );		//������ӿڵ�ƽ�ø�
		}
		else
		{
			GPIO_ResetBits(Servo_J2_PORT, Servo_J2_PIN );		//������ӿڵ�ƽ�ø�
		}

		if(num <= (Angle_J3 * 11 + 500)/10)
		{
			GPIO_SetBits(Servo_J3_PORT, Servo_J3_PIN );		//������ӿڵ�ƽ�ø�
		}
		else
		{
			GPIO_ResetBits(Servo_J3_PORT, Servo_J3_PIN );		//������ӿڵ�ƽ�ø�
		}

		if(num <= (Angle_J4 * 11 + 500)/10)
		{
			GPIO_SetBits(Servo_J4_PORT, Servo_J4_PIN );		//������ӿڵ�ƽ�ø�
		}
		else
		{
			GPIO_ResetBits(Servo_J4_PORT, Servo_J4_PIN );		//������ӿڵ�ƽ�ø�
		}

		if(num <= (Angle_J5 * 11 + 500)/10)
		{
			GPIO_SetBits(Servo_J5_PORT, Servo_J5_PIN );		//������ӿڵ�ƽ�ø�
		}
		else
		{
			GPIO_ResetBits(Servo_J5_PORT, Servo_J5_PIN );		//������ӿڵ�ƽ�ø�
		}

		if(num <= (Angle_J6 * 11 + 500)/10)
		{
			GPIO_SetBits(Servo_J6_PORT, Servo_J6_PIN );		//������ӿڵ�ƽ�ø�
		}
		else
		{
			GPIO_ResetBits(Servo_J6_PORT, Servo_J6_PIN );		//������ӿڵ�ƽ�ø�
		}

		

		if(num == 2000) //2000*10=20ms  20msһ������
		{
			num = 0;
		}
		
	}
}
