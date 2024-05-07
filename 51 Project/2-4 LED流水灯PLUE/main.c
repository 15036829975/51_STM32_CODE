#include <REGX52.H>
void Delay1ms(unsigned int xms)		//@12.000MHz
{
	unsigned char data i, j;
while(xms)
{
    
	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
	xms--;
}
}

void main()
{
	while(1)
		
	{P2=0xFE;//1111 1110
		Delay1ms(200);
	P2=0xFD;//1111 1101
		Delay1ms(200);
	P2=0xFB;//1111 1011
	Delay1ms(200);
	P2=0xF7;//1111 0111
		Delay1ms(200);
	P2=0xEF;//1110 1111
		Delay1ms(200);
	}

}