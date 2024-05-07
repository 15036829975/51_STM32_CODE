#ifndef __BSP_LLGHTSEEKING_H__
#define __BSP_LLGHTSEEKING_H__


#define LightSeek_L1_RCC		RCC_APB2Periph_GPIOB
#define LightSeek_R1_RCC		RCC_APB2Periph_GPIOA

#define LightSeek_L1_PIN		GPIO_Pin_3
#define LightSeek_R1_PIN		GPIO_Pin_5

#define LightSeek_L1_PORT		GPIOB
#define LightSeek_R1_PORT		GPIOA

/*Ñ°¹â´«¸ÐÆ÷*/
#define USE_LIGHTSEEKING_L1
#define USE_LIGHTSEEKING_R1

void bsp_GetLightSeeking(int *p_iL1,int *p_iL2,int *p_iR1,int *p_iR2);

#endif
