#include <reg52.h>
#include <intrins.h>
#include "lcd1602.h"
#include "common.h"

sbit RS = P2^5;
sbit RW = P2^6;
sbit E = P2^7;

#define DataPort P0

void lcd_clear(void)//����
{
   lcd_write_com(0x01);
	 delay_ms(5);
}

void lcd_write_com(unsigned char byte)//дָ��
{
		RS = 0;
	  RW = 0;
	  E = 1;
	  DataPort = byte;
	  _nop_();
	  _nop_();
	  delay_ms(1);
	  E = 0;
	    
}

void lcd_write_data(unsigned char byte)//д����
{
	  RS = 1;
	  RW = 0;
	  E = 1;
	  DataPort = byte;
	  _nop_();
	  _nop_();
	  delay_ms(1);
	  E = 0;
}

void lcd_init()//1602��ʼ��
{
	  delay_ms(5);
	  lcd_write_com(0x38);//����16*2��ʾ��5*7����8λ���ݽӿ�
	  delay_ms(5);
	  lcd_write_com(0x38);//����16*2��ʾ��5*7����8λ���ݽӿ�
	  delay_ms(5);
	  lcd_write_com(0x38);//����16*2��ʾ��5*7����8λ���ݽӿ�
	  delay_ms(5);
	  lcd_write_com(0x08); //�ر���ʾ
	  delay_ms(5);
	  lcd_write_com(0x01);//����ָ��
	  delay_ms(5);
	  lcd_write_com(0x06);
	  delay_ms(5);
	  lcd_write_com(0x0c);
	  delay_ms(5);
	  
}
void lcd_write_char(unsigned char x,unsigned char y,unsigned char byte)//��ĳһλ����ʾһ�ַ�
{
	  if(0 == y)
		{
			lcd_write_com(0x80 + x);
		}
	  else if(1 == y)
		{
			lcd_write_com(0x80 + 0x40 + x);
		}
		lcd_write_data(byte);
}

void lcd_write_str(unsigned char x, unsigned char y, unsigned char *s)//��ĳһλ����ʾһ�ַ���
{
	 if(0 == y)
		{
			lcd_write_com(0x80 + x);
		}
	  else
		{
			lcd_write_com(0x80 + 0x40 + x);
		}
		
		while(*s)
		{
			lcd_write_data(*s);
			s++;
		}
		
}
