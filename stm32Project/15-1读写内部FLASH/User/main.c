#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "MyFLASH.h"
#include "Key.h"

uint8_t KeyNum;
int main(void)
{
	OLED_Init();
	Key_Init();
	OLED_ShowHexNum(1,1,MyFLASH_ReadWord(0x08000010),8);
	OLED_ShowHexNum(2,1,MyFLASH_ReadHalfWord(0x08000010),4);
	OLED_ShowHexNum(3,1,MyFLASH_ReadByte(0x08000010),2);	
	
	
	
	while(1)
	{
		KeyNum=Key_GetNum();
		if(KeyNum==1)
		{
			MyFLASH_EraseAllPages();
			
		}
		if(KeyNum==2)
		{
			MyFLASH_ErasePage(0x08000000);
		}
		
		
	}
}
