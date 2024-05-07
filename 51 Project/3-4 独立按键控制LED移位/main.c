#include <REGX52.H>

void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char data i, j;
	while(xms)
	{
	i = 12;
	j = 169;
	do
	{
		while (--j);
	} while (--i);
	xms--;
	}
}
unsigned char LED=0;
void main()
	
{
	P2=~0x01;
	
	while(1)
	{
		
		if(P3_1==0)
		{	
			Delay(20);
		while(P3_1==0);
		Delay(20);
		LED++;
		if(LED>=8)
			LED=0;
		P2=~(0x01<<LED);
	  }
		if(P3_0==0)
		{
			Delay(20);
		while(P3_0==0);
		Delay(20);
			if(LED==0)
			LED=7;
			else
		  LED--;
		P2=~(0x01<<LED);
	  }
	}
	
	
}