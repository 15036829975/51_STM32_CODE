#include <REGX52.H>
#include "LCD1602.h"
#include "IR.h"
#include "Delay.h"
//unsigned char Num;
unsigned char Address;
unsigned char Conmand;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"a");
	IR_Init();
	while(1)
	{
	if(IR_GetDataFlag())
	{
		Address=IR_GetAddress();
		Conmand=IR_GetCommand();
		
		LCD_ShowHexNum(2,1,Address,2);
		LCD_ShowHexNum(2,5,Conmand,2);
	}
	
	}
}
//  void Int0_Routine(void) interrupt 0
//	{
//		Num--;
//	}