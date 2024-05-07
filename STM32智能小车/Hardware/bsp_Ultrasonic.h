#ifndef __BSP_ULTRASONIC_H
#define __BSP_ULTRASONIC_H

extern void bsp_Ultrasonic_Timer2_Init(void);
extern float bsp_getUltrasonicDistance(void);


#define TRIG_RCC		RCC_APB2Periph_GPIOA
#define ECHO_RCC		RCC_APB2Periph_GPIOA

#define TRIG_PIN		GPIO_Pin_15
#define ECHO_PIN		GPIO_Pin_12

#define TRIG_PORT		GPIOA
#define ECHO_PORT		GPIOA


#endif
