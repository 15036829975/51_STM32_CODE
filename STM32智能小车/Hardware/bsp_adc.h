#ifndef __BSP_ADC_H
#define __BSP_ADC_H

 void Adc_Init(void);
 float  Get_Battery_Volotage(void);	
 float Get_Measure_Volotage(void);

 static u16 Get_Adc_Average(u8 ch, u8 times);
 static u16 Get_Adc(u8 ch);
 
#endif
