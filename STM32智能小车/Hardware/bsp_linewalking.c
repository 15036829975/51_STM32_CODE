#include "stm32f10x.h"                  // Device header
#include "bsp.h"
void bsp_GetLineWalking(int *p_iL1,int *p_iL2,int *p_iR1,int *p_iR2)
{
	*p_iL1 = GPIO_ReadInputDataBit(LineWalk_L1_PORT,LineWalk_L1_PIN);
	*p_iL2 = GPIO_ReadInputDataBit(LineWalk_L2_PORT,LineWalk_L2_PIN);
	*p_iR1 = GPIO_ReadInputDataBit(LineWalk_R1_PORT,LineWalk_R1_PIN);
	*p_iR2 = GPIO_ReadInputDataBit(LineWalk_R2_PORT,LineWalk_R2_PIN);

}
	