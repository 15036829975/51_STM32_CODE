#ifndef _LCD_H
#define _LCD_H

#include "reg52.h"

typedef unsigned char BYTE;	//用BYTE代替unsigned char 
typedef unsigned int WORD;//WORD代替unsigned int
typedef bit BOOL ;//用BOOL代替bit  

void lcd_wcmd(BYTE cmd);
void lcd_wdat(BYTE dat);
void Lcd_WrData(BYTE row, BYTE col, BYTE *dat);
void Lcd_Wr_Data(BYTE row, BYTE col, BYTE *dat);

void lcd_init(void);


#endif