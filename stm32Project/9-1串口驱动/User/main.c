#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

int main(void)
{
	OLED_Init();
	Serial_Init();
	
	
	
	//uint8_t MyArray[]={0x42,43,0x44,0x45};
	
	//Serial_SendArray(MyArray,4);
	//Serial_SendString("Hello!\r\n");
	//Serial_SendNum(12345,5);
	//printf("NUM=%d\r\n",666);
//	char String[100];
//	sprintf(String,"NUM=%d\r\n",666);
//	Serial_SendString(String);
	Serial_Printf("世界");
	while(1)
	{
	}
}
