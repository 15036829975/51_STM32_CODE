#include <REGX52.H>
#include "DS18B20.h"
#include "Key.h"
#include "AT24C02.h"
#include "Delay.h"
#include "LCD1602.h"
#include "DS18B20.h"
float T;
char TLOW,THIGH;
void main() 
{
	
	LCD_Init();
	LCD_ShowString(1,1,"T:");
	
	while(1)
	{
			DS18B20_ConvertT();
			T=DS18B20_ReadT();
		if(T<0)
		{
			LCD_ShowChar(1,3,'-');
			T=-T;
		}
			else
			{
				LCD_ShowChar(1,3,'+');
			}
			LCD_ShowNum(1,4,T,3);
			LCD_ShowChar(1,7,'.');
			LCD_ShowNum(1,8,(unsigned long)(T*100)%100,2);
		}
}