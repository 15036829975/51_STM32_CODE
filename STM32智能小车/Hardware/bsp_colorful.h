

#ifndef __BSP_COLORFUL_H__
#define __BSP_COLORFUL_H__




#define Colorful_Red_PIN	GPIO_Pin_1
#define Colorful_Red_PORT	GPIOB
#define Colorful_Red_RCC	RCC_APB2Periph_GPIOB

#define Colorful_Green_PIN	GPIO_Pin_0
#define Colorful_Green_PORT	GPIOB
#define Colorful_Green_RCC	RCC_APB2Periph_GPIOB

#define Colorful_Blue_PIN	GPIO_Pin_7
#define Colorful_Blue_PORT	GPIOA
#define Colorful_Blue_RCC	RCC_APB2Periph_GPIOA


void bsp_Colorful_Control(int v_RedOnOff, int v_GreenOnOff, int v_BlueOnOff);



#endif


