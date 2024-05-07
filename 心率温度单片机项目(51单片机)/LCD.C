#include "LCD.h" //51寄存器文件
#include <intrins.h>

void Lcd_WrData(BYTE row, BYTE col, BYTE *dat);


sbit rw	= P2^6; //复位端
sbit rs = P2^5; //写数据端
sbit ep = P2^7;	//使能端
/*---------------------------------------------------
	 		延时函数
-----------------------------------------------------*/

void delay_ms(BYTE ms)
{							
	BYTE i;
	while(ms--)
	{
		for(i = 0; i< 110; i++)
		{
			_nop_();

		}
	}
}
void delay_us(void)
{
    unsigned char b;
    for(b=1;b>0;b--)  ;
}
/*---------------------------------------------------
	 		LCD检测忙函数
-----------------------------------------------------*/
BOOL lcd_bz(void)
{						
	BOOL result;
	rs = 0;
	rw = 1;
	ep = 1;
	delay_us();delay_us();delay_us();delay_us();
	result = (BOOL)(P0 & 0x80); //检测P0最高位是否为1
	ep = 0;
	return result;//返回侧忙结果	
}
/*---------------------------------------------------
	 		LCD写命令
-----------------------------------------------------*/
void lcd_wcmd(BYTE cmd)
{							// 写入指令数据到LCD
	while(lcd_bz());
	rs = 0;
	rw = 0;
	ep = 0;
	delay_us();delay_us();	
	P0 = cmd; //将8位指令通过P0口传给1602
	delay_us();delay_us();delay_us();delay_us();
	ep = 1;
	delay_us();delay_us();delay_us();delay_us();
	ep = 0;		
}
/*---------------------------------------------------
	 		LCD写数据
-----------------------------------------------------*/
void lcd_wdat(BYTE dat)	
{							//写入字符显示数据到LCD
	while(lcd_bz());
	rs = 1;
	rw = 0;
	ep = 0;
	P0 = dat;//将8位数据通过P0口传给1602 
	delay_us();delay_us();delay_us();delay_us();
	ep = 1;
	delay_us();delay_us();delay_us();delay_us();
	ep = 0;	
}
/*---------------------------------------------------
	 		LCD显示字符串
-----------------------------------------------------*/
void Lcd_WrData(BYTE row, BYTE col, BYTE *dat)
{	
	BYTE i;
	switch(row)
	{
		case 0:
		lcd_wcmd(col + 0x80);
		break;
		case 1:
		lcd_wcmd(0x40 + col + 0x80);
		break;
	}
	while(*dat != '\0')
	{						//显示字符"welcome!"
		lcd_wdat(*dat);
		dat++;
	}	

}
void Lcd_Wr_Data(BYTE row, BYTE col, BYTE *dat)
{	
	BYTE i;
	switch(row)
	{
		case 0:
		lcd_wcmd(col + 0x80);
		break;
		case 1:
		lcd_wcmd(0x40 + col + 0x80);
		break;
	}
						//显示字符"welcome!"
		lcd_wdat(*dat);

}


/*---------------------------------------------------
	 		LCD初始化
-----------------------------------------------------*/
void lcd_init(void)
{					  //LCD初始化设定
	lcd_wcmd(0x38);	  ////16*2显示，5*7点阵，8位数据
	delay_ms(1);
	lcd_wcmd(0x0c);	  //显示开，关光标
	delay_ms(1);
	lcd_wcmd(0x06);	  //移动光标
	delay_ms(1);
	lcd_wcmd(0x01);	  //清除LCD的显示内容
	delay_ms(1);

 Lcd_WrData(0,1,"Samrt");

}

	