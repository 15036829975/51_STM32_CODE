#ifndef __BSP_IRAVOID_H__
#define __BSP_IRAVOID_H__

	#define IRAvoid_L1_RCC		RCC_APB2Periph_GPIOA
	#define IRAvoid_R1_RCC		RCC_APB2Periph_GPIOA

	#define IRAvoid_L1_PIN		GPIO_Pin_6
	#define IRAvoid_R1_PIN		GPIO_Pin_4

	#define IRAvoid_L1_PORT		GPIOA
	#define IRAvoid_R1_PORT		GPIOA
	
	int bsp_GetIRAvoid_Data(void);
	void bsp_GetIRAvoid(int *p_iL1,int *p_iR1);
	
	
#endif
