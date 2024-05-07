#include <REGX52.H>
#include "LCD1602.H"
#include "Delay.H"
int a=0;
void main()
{
	LCD_Init();
		while(1)
	{
		
		
		a++;
		Delay(10);
		LCD_ShowNum(1,1,a,3);
		
	}
	
	
}