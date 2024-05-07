#include <REGX52.H>
#include “Timer0.h”
#include "Key.h"
unsigned char KeyNum;
void main()
{
	Timer0_Init();
	while(1)
	{
		KeyNum=Key();
	if(KeyNum)
	{
		if(KeyNum==1){P2_1=~P2_1;}
		if(KeyNum==2){P2_1=~P2_2;}
		if(KeyNum==3){P2_1=~P2_3;}
		if(KeyNum==4){P2_1=~P2_4;}
	}
	}
		
	
}
void Timer0_Init(void)		//1毫秒@12.000MHz
{
	
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0x18;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	ET0=1;
	EA=1;
	PT0=0;
}


void Timer0_Routine() interrupt 1
{	
		static	unsigned int TimeCount;
	  TL0 = 0x18;				//设置定时初始值
	  TH0 = 0xFC;				//设置定时初始值
		TimeCount++;
	if(TimeCount>=1000)
	{
		TimeCount=0;
		P2_0=~P2_0;
  	}
	
}