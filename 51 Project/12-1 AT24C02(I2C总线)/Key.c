#include <REGX52.H>
#include "Delay.h"
unsigned char Key()
{
	unsigned char KeyNum=0;
	if(P2_1==0){Delay(20);while(P2_1==0);Delay(20);KeyNum=1;}
	if(P2_0==0){Delay(20);while(P2_2==0);Delay(20);KeyNum=2;}
	if(P2_2==0){Delay(20);while(P2_3==0);Delay(20);KeyNum=3;}
	if(P2_3==0){Delay(20);while(P2_4==0);Delay(20);KeyNum=4;}
	
	return KeyNum;
}