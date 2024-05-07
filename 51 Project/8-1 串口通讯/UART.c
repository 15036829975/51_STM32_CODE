#include <REGX52.H>
 /**
    * @brief  串口初始化//4800bps@12.000MHz
    * @param  无
    * @retval无
    */
void UART_Init()    
{
	SCON=0x40;
	PCON |= 0x80;
	TMOD &= 0x0F;			//设置定时器模式
	TMOD |= 0x20;			//设置定时器模式
	TL1 = 0xF3;			//设置定时初始值
	TH1 = 0xF3;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
	
	
}
 /**
    * @brief  串口发送一个字节数据
    * @param  Byte 要发送一个字节数据
    * @retval 无
    */
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
	
}