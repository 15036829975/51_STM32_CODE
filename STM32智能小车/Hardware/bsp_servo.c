#include "stm32f10x.h"
#include "bsp.h"



/*使用定时器1驱动*/
int Angle_J1 = 0;
int Angle_J2 = 0;
int Angle_J3 = 0;
int Angle_J4 = 0;
int Angle_J5 = 0;
int Angle_J6 = 0;



void Servo_J1(int v_iAngle)/*定义一个脉冲函数，用来模拟方式产生PWM值*/
{
	int pulsewidth;    						//定义脉宽变量

	pulsewidth = (v_iAngle * 11) + 500;			//将角度转化为500-2480 的脉宽值

	GPIO_SetBits(Servo_J1_PORT, Servo_J1_PIN );		//将舵机接口电平置高
	Delay_us(pulsewidth);					//延时脉宽值的微秒数

	GPIO_ResetBits(Servo_J1_PORT, Servo_J1_PIN );	//将舵机接口电平置低
	Delay_ms(20 - pulsewidth/1000);			//延时周期内剩余时间
}


void Servo_J2(int v_iAngle)/*定义一个脉冲函数，用来模拟方式产生PWM值*/
{
	int pulsewidth;    						//定义脉宽变量

	pulsewidth = (v_iAngle * 11) + 500;			//将角度转化为500-2480 的脉宽值

	GPIO_SetBits(Servo_J2_PORT, Servo_J2_PIN );		//将舵机接口电平置高
	Delay_us(pulsewidth);					//延时脉宽值的微秒数

	GPIO_ResetBits(Servo_J2_PORT, Servo_J2_PIN );	//将舵机接口电平置低
	Delay_ms(20 - pulsewidth/1000);			//延时周期内剩余时间
}


void Servo_J3(int v_iAngle)/*定义一个脉冲函数，用来模拟方式产生PWM值*/
{
	int pulsewidth;    						//定义脉宽变量

	pulsewidth = (v_iAngle * 11) + 500;			//将角度转化为500-2480 的脉宽值

	GPIO_SetBits(Servo_J3_PORT, Servo_J3_PIN );		//将舵机接口电平置高
	Delay_us(pulsewidth);					//延时脉宽值的微秒数

	GPIO_ResetBits(Servo_J3_PORT, Servo_J3_PIN );	//将舵机接口电平置低
	Delay_ms(20 - pulsewidth/1000);			//延时周期内剩余时间
}


void Servo_J4(int v_iAngle)/*定义一个脉冲函数，用来模拟方式产生PWM值*/
{
	int pulsewidth;    						//定义脉宽变量

	pulsewidth = (v_iAngle * 11) + 500;			//将角度转化为500-2480 的脉宽值

	GPIO_SetBits(Servo_J4_PORT, Servo_J4_PIN );		//将舵机接口电平置高
	Delay_us(pulsewidth);					//延时脉宽值的微秒数

	GPIO_ResetBits(Servo_J4_PORT, Servo_J4_PIN );	//将舵机接口电平置低
	Delay_ms(20 - pulsewidth/1000);			//延时周期内剩余时间
}


void Servo_J5(int v_iAngle)/*定义一个脉冲函数，用来模拟方式产生PWM值*/
{
	int pulsewidth;    						//定义脉宽变量

	pulsewidth = (v_iAngle * 11) + 500;			//将角度转化为500-2480 的脉宽值

	GPIO_SetBits(Servo_J5_PORT, Servo_J5_PIN );		//将舵机接口电平置高
	Delay_us(pulsewidth);					//延时脉宽值的微秒数

	GPIO_ResetBits(Servo_J5_PORT, Servo_J5_PIN );	//将舵机接口电平置低
	Delay_ms(20 - pulsewidth/1000);			//延时周期内剩余时间
}


void Servo_J6(int v_iAngle)/*定义一个脉冲函数，用来模拟方式产生PWM值*/
{
	int pulsewidth;    						//定义脉宽变量

	pulsewidth = (v_iAngle * 11) + 500;			//将角度转化为500-2480 的脉宽值

	GPIO_SetBits(Servo_J6_PORT, Servo_J6_PIN );		//将舵机接口电平置高
	Delay_us(pulsewidth);					//延时脉宽值的微秒数

	GPIO_ResetBits(Servo_J6_PORT, Servo_J6_PIN );	//将舵机接口电平置低
	Delay_ms(20 - pulsewidth/1000);			//延时周期内剩余时间
}


void front_detection()
{
	int i = 0;
  	//此处循环次数减少，为了增加小车遇到障碍物的反应速度
  	for(i=0; i <= 15; i++) 		//产生PWM个数，等效延时以保证能转到响应角度
  	{
    	Servo_J1(90);			//模拟产生PWM
  	}
}


void left_detection()
{
	int i = 0;
	for(i = 0; i <= 15; i++) 						//产生PWM个数，等效延时以保证能转到响应角度
	{
		Servo_J1(175);					//模拟产生PWM
	}
}


void right_detection()
{
	int i = 0;
	for(i = 0; i <= 15; i++) 						//产生PWM个数，等效延时以保证能转到响应角度
	{
		Servo_J1(5);						//模拟产生PWM
	}
}

