#include <REGX52.H>

unsigned char Key_KeyNumber;
unsigned char Key(void)
{
	unsigned char Temp;
	Temp=Key_KeyNumber;
	Key_KeyNumber=0;
	return Temp;
}
unsigned char Key_GetState()
{
	unsigned char KeyNum=0;
	if(P3_1==0)KeyNum=1;
	if(P3_0==0)KeyNum=2;
	if(P3_2==0)KeyNum=3;
	if(P3_3==0)KeyNum=4;
	
	return KeyNum;
}
void Key_Loop(void)
{
	static unsigned char NowState,LastState;
	LastState=NowState;
	NowState=Key_GetState();
		if(LastState==1 && NowState==0) Key_KeyNumber=1;
		if(LastState==2 && NowState==0) Key_KeyNumber=2;
		if(LastState==3 && NowState==0) Key_KeyNumber=3;
		if(LastState==4 && NowState==0) Key_KeyNumber=4;
}