#include "stm32f10x.h"
#include "bsp.h"



/*ʹ�ö�ʱ��1����*/
int Angle_J1 = 0;
int Angle_J2 = 0;
int Angle_J3 = 0;
int Angle_J4 = 0;
int Angle_J5 = 0;
int Angle_J6 = 0;



void Servo_J1(int v_iAngle)/*����һ�����庯��������ģ�ⷽʽ����PWMֵ*/
{
	int pulsewidth;    						//�����������

	pulsewidth = (v_iAngle * 11) + 500;			//���Ƕ�ת��Ϊ500-2480 ������ֵ

	GPIO_SetBits(Servo_J1_PORT, Servo_J1_PIN );		//������ӿڵ�ƽ�ø�
	Delay_us(pulsewidth);					//��ʱ����ֵ��΢����

	GPIO_ResetBits(Servo_J1_PORT, Servo_J1_PIN );	//������ӿڵ�ƽ�õ�
	Delay_ms(20 - pulsewidth/1000);			//��ʱ������ʣ��ʱ��
}


void Servo_J2(int v_iAngle)/*����һ�����庯��������ģ�ⷽʽ����PWMֵ*/
{
	int pulsewidth;    						//�����������

	pulsewidth = (v_iAngle * 11) + 500;			//���Ƕ�ת��Ϊ500-2480 ������ֵ

	GPIO_SetBits(Servo_J2_PORT, Servo_J2_PIN );		//������ӿڵ�ƽ�ø�
	Delay_us(pulsewidth);					//��ʱ����ֵ��΢����

	GPIO_ResetBits(Servo_J2_PORT, Servo_J2_PIN );	//������ӿڵ�ƽ�õ�
	Delay_ms(20 - pulsewidth/1000);			//��ʱ������ʣ��ʱ��
}


void Servo_J3(int v_iAngle)/*����һ�����庯��������ģ�ⷽʽ����PWMֵ*/
{
	int pulsewidth;    						//�����������

	pulsewidth = (v_iAngle * 11) + 500;			//���Ƕ�ת��Ϊ500-2480 ������ֵ

	GPIO_SetBits(Servo_J3_PORT, Servo_J3_PIN );		//������ӿڵ�ƽ�ø�
	Delay_us(pulsewidth);					//��ʱ����ֵ��΢����

	GPIO_ResetBits(Servo_J3_PORT, Servo_J3_PIN );	//������ӿڵ�ƽ�õ�
	Delay_ms(20 - pulsewidth/1000);			//��ʱ������ʣ��ʱ��
}


void Servo_J4(int v_iAngle)/*����һ�����庯��������ģ�ⷽʽ����PWMֵ*/
{
	int pulsewidth;    						//�����������

	pulsewidth = (v_iAngle * 11) + 500;			//���Ƕ�ת��Ϊ500-2480 ������ֵ

	GPIO_SetBits(Servo_J4_PORT, Servo_J4_PIN );		//������ӿڵ�ƽ�ø�
	Delay_us(pulsewidth);					//��ʱ����ֵ��΢����

	GPIO_ResetBits(Servo_J4_PORT, Servo_J4_PIN );	//������ӿڵ�ƽ�õ�
	Delay_ms(20 - pulsewidth/1000);			//��ʱ������ʣ��ʱ��
}


void Servo_J5(int v_iAngle)/*����һ�����庯��������ģ�ⷽʽ����PWMֵ*/
{
	int pulsewidth;    						//�����������

	pulsewidth = (v_iAngle * 11) + 500;			//���Ƕ�ת��Ϊ500-2480 ������ֵ

	GPIO_SetBits(Servo_J5_PORT, Servo_J5_PIN );		//������ӿڵ�ƽ�ø�
	Delay_us(pulsewidth);					//��ʱ����ֵ��΢����

	GPIO_ResetBits(Servo_J5_PORT, Servo_J5_PIN );	//������ӿڵ�ƽ�õ�
	Delay_ms(20 - pulsewidth/1000);			//��ʱ������ʣ��ʱ��
}


void Servo_J6(int v_iAngle)/*����һ�����庯��������ģ�ⷽʽ����PWMֵ*/
{
	int pulsewidth;    						//�����������

	pulsewidth = (v_iAngle * 11) + 500;			//���Ƕ�ת��Ϊ500-2480 ������ֵ

	GPIO_SetBits(Servo_J6_PORT, Servo_J6_PIN );		//������ӿڵ�ƽ�ø�
	Delay_us(pulsewidth);					//��ʱ����ֵ��΢����

	GPIO_ResetBits(Servo_J6_PORT, Servo_J6_PIN );	//������ӿڵ�ƽ�õ�
	Delay_ms(20 - pulsewidth/1000);			//��ʱ������ʣ��ʱ��
}


void front_detection()
{
	int i = 0;
  	//�˴�ѭ���������٣�Ϊ������С�������ϰ���ķ�Ӧ�ٶ�
  	for(i=0; i <= 15; i++) 		//����PWM��������Ч��ʱ�Ա�֤��ת����Ӧ�Ƕ�
  	{
    	Servo_J1(90);			//ģ�����PWM
  	}
}


void left_detection()
{
	int i = 0;
	for(i = 0; i <= 15; i++) 						//����PWM��������Ч��ʱ�Ա�֤��ת����Ӧ�Ƕ�
	{
		Servo_J1(175);					//ģ�����PWM
	}
}


void right_detection()
{
	int i = 0;
	for(i = 0; i <= 15; i++) 						//����PWM��������Ч��ʱ�Ա�֤��ת����Ӧ�Ƕ�
	{
		Servo_J1(5);						//ģ�����PWM
	}
}

