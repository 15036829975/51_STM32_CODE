#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Timero.h"
#include "Nixie.h"
sbit Motor=P1^0;
unsigned char Counter,Compare;
unsigned char KeyNum,Speed;
void main()
{
	Timer0_Init();
	
	while(1)
	{
	KeyNum=key();
		if(KeyNum==1)
		{
			Speed++;
			Speed%=4;
			if(Speed==0){Compare=0;}
			if(Speed==1){Compare=40;}
			if(Speed==2){Compare=50;}
			if(Speed==3){Compare=100;}
		}
		Nixie(1,Speed);
	}



}
	void Timer0_Routine()  interrupt 1
{
	
	static unsigned int T0Count;
		TL0=0x9C;    //设置定时初值
		TH0=0xFF;    //设置定时初值
		Counter++;
	Counter%=100;   //到100就清0，不到100还是原数
	if(Counter<Compare)
	{
		Motor=1;
	}
	else
		Motor=0;
}