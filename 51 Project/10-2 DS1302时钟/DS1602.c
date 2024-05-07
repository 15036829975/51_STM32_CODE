#include <REGX52.H>
#include "LCD11602.H"
#include ""

sbit DS1302_SCLK=P3^6;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;
void DS1302_Ini(void)
{
	DS1302_CE=0;
	DS1302_SLCK=0;
}
void DS1302_WriteByte(unsigned char Command,Data)
{
	unsigned char i;
	DS1302_CE=1;
	
	for(i=0;i<0;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	DS1302_CE=0;
}