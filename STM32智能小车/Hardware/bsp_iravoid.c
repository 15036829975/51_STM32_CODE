#include "stm32f10x.h"
#include "bsp.h"

	void bsp_GetIRAvoid(int *p_iL1,int *p_iR1)
	{
		*p_iL1 = GPIO_ReadInputDataBit(IRAvoid_L1_PORT,IRAvoid_L1_PIN);
		*p_iR1 = GPIO_ReadInputDataBit(IRAvoid_R1_PORT,IRAvoid_R1_PIN);
	}
	
	
	
	int bsp_GetIRAvoid_Data(void)
	{
		int L1,R1,ReturnValue;
		L1=GPIO_ReadInputDataBit(IRAvoid_L1_PORT,IRAvoid_L1_PIN);
		R1=GPIO_ReadInputDataBit(IRAvoid_R1_PORT,IRAvoid_R1_PIN);
		ReturnValue =(L1 == 0 ? 10:0);
		ReturnValue +=(R1 == 0 ? 10:0);
		return ReturnValue;
	}
	