#include "stm32f10x.h"                  // Device header
void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
//		GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);
//		GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//重映射
	
		GPIO_InitTypeDef GPIO_Initstructure;
		GPIO_Initstructure.GPIO_Mode= GPIO_Mode_AF_PP;
		GPIO_Initstructure.GPIO_Pin= GPIO_Pin_2;
		GPIO_Initstructure.GPIO_Speed= GPIO_Speed_50MHz;
		GPIO_Init(GPIOA,&GPIO_Initstructure);  //初始化GPIO
	TIM_InternalClockConfig(TIM2);//选择时钟
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period=100-1;      //   ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler=72-1;    //   PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_OCInitStruture;
	TIM_OCStructInit(&TIM_OCInitStruture);
	TIM_OCInitStruture.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStruture.TIM_OCNPolarity=TIM_OCPolarity_High;
	TIM_OCInitStruture.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStruture.TIM_Pulse=0;              //CCR
	
	
	TIM_OC3Init(TIM2,&TIM_OCInitStruture);//初始化输出比较通道


	
	TIM_Cmd(TIM2,ENABLE);
	
	
	
}
void PWM_SetCompare3(uint16_t Compare)
{
	TIM_SetCompare3(TIM2,Compare);
	
}
