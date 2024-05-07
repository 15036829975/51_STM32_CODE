#include <REGX52.H>
#include "OneWire.h"


#define DS18B20_SKIP_ROM      0XCC
#define DS18B20_CONVERT_T     0X44
#define DS18B20_READ_SCRATCHPAD     0XBE



void DS18B20_ConvertT(void)
{
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_CONVERT_T);	
	
	
	
}
float DS18B20_ReadT(void)
{
	unsigned char TLSB,TMSB;
	int Temp;
	float T;
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_READ_SCRATCHPAD);
	TLSB=OneWire_ReceiverByte();
	TMSB=OneWire_ReceiverByte();
//	LCD_ShowBinNum(1,1,TMSB,8);
//	LCD_ShowBinNum(1,9,TLSB,8);
	Temp=(TMSB<<8)|TLSB;
	T=Temp/16.0;
	return T;
}

