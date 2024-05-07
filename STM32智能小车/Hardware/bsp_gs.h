#ifndef __BSP_GS_H
#define __BSP_GS_H

void bsp_GS_Init(void);
int Get_GS_Value(void);
static u16 Get_Adc_Average(u8 ch, u8 times);
static u16 Get_Adc(u8 ch);

#endif
