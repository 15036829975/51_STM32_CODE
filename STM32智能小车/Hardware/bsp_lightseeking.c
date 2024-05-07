#include "stm32f10x.h"
#include "bsp.h"

  void bsp_GetLightSeeking(int *p_iL1,int *p_iL2,int *p_iR1,int *p_iR2)
	{
		*p_iL1= GPIO_ReadInputDataBit(LightSeek_L1_PORT,LightSeek_L1_PIN);
		*p_iL2= GPIO_ReadInputDataBit(LightSeek_L1_PORT,LightSeek_L1_PIN);
		*p_iR1= GPIO_ReadInputDataBit(LightSeek_R1_PORT,LightSeek_R1_PIN);
	  *p_iR2= GPIO_ReadInputDataBit(LightSeek_R1_PORT,LightSeek_R1_PIN);		
	
	}
	
	
	