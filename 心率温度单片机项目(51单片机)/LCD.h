#ifndef _LCD_H
#define _LCD_H

#include "reg52.h"

typedef unsigned char BYTE;	//��BYTE����unsigned char 
typedef unsigned int WORD;//WORD����unsigned int
typedef bit BOOL ;//��BOOL����bit  

void lcd_wcmd(BYTE cmd);
void lcd_wdat(BYTE dat);
void Lcd_WrData(BYTE row, BYTE col, BYTE *dat);
void Lcd_Wr_Data(BYTE row, BYTE col, BYTE *dat);

void lcd_init(void);


#endif