#include <REGX52.H>
#include <INTRINS.H>
void Delay50ms()		//@12.000MHz
{
	unsigned char data i, j;

	i = 98;
	j = 67;
	do
	{
		while (--j);
	} while (--i);
}



void main()
{

	while(1)
	{
	  P2=0xFE;
		Delay50ms();	//0101 0101;
		P2=0xFE;
		Delay50ms();
	}
}