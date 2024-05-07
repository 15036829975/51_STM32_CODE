#include "stm32f10x.h"                  // Device header
#include "bsp_Ultrasonic.h"
#include "Delay.h"


void bsp_Ultrasonic_Timer2_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructer;
	NVIC_InitTypeDef NVIC_InitStructer;


	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	/*定时器TIM2初始化*/
	TIM_DeInit(TIM2);
	TIM_TimeBaseInitStructer.TIM_Period = 999;//定时周期为1000
	TIM_TimeBaseInitStructer.TIM_Prescaler = 71; //分频系数72
	TIM_TimeBaseInitStructer.TIM_ClockDivision = TIM_CKD_DIV1;//不分频
	TIM_TimeBaseInitStructer.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructer);
	
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);//开启更新中断

	/*定时器中断初始化*/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitStructer.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructer.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructer.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructer.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&NVIC_InitStructer);
	TIM_Cmd(TIM2, DISABLE);//关闭定时器使能

}


/*记录定时器溢出次数*/
unsigned int overcount = 0;

float bsp_getUltrasonicDistance(void)
{
	float length = 0, sum = 0;
	u16 tim,count;
	
	unsigned int  i = 0;

	while(i != 5)
	{
		GPIO_SetBits(TRIG_PORT, TRIG_PIN);  
		Delay_us(20);  					
		GPIO_ResetBits(TRIG_PORT, TRIG_PIN);

	
		while(GPIO_ReadInputDataBit(ECHO_PORT, ECHO_PIN) == RESET);
		TIM_Cmd(TIM2,ENABLE);
		
		i+=1;
		while(GPIO_ReadInputDataBit(ECHO_PORT, ECHO_PIN) == SET)
	{
			count = overcount;
		if(count >= 40)   //
		{
			TIM_Cmd(TIM2, DISABLE);
			TIM2->CNT = 0; 
			overcount = 0;  
			return 0;	
		}
			
	}
		TIM_Cmd(TIM2, DISABLE);
		
		tim = TIM_GetCounter(TIM2);
		
		length = (tim + overcount * 1000) / 58.0;
		
		sum = length + sum;
		TIM2->CNT = 0;
		overcount = 0; 
		Delay_ms(10);
	}
	length = sum / 5;
	return length;		
}
