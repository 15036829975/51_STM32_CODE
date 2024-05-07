#include <REGX52.H>
#include "Nixie.h"
#include "Key.h"
#include "Timero.h"

unsigned char KeyNum;

void main()
{
	Timer0_Init();
	while(1)
	{
		KeyNum=Key();
		if(KeyNum)
		{
			Nixie_SetBuf(1,KeyNum);
			Nixie_SetBuf(2,KeyNum);
		}
	}
}
void Timer0_Routine()  interrupt 1
{
	static unsigned int T0Count1,T0Count2;
		TL0=0x18;    //设置定时初值
		TH0=0xFC;    //设置定时初值
		T0Count1++;
		if(T0Count1>=20)
{
			T0Count1=0;
			Key_Loop();
}
    T0Count2++;
		if(T0Count2>=2)
{
			T0Count2=0;
			Nixie_Loop();
}
}