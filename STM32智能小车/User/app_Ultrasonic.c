#include "stm32f10x.h"                  // Device header
#include "app_Ultrasonic.h"
#include "app_motor.h"
#include "bsp.h"


void app_ultrasonic_mode(void)
{
	int Len = 0;
	Len=bsp_getUltrasonicDistance();
	//printf("CSB:%d", Len);  	

	if(Len < 25)//��ֵΪ�����ϰ���ľ��룬���԰�ʵ���������   
    { 
	  Len = (u16)bsp_getUltrasonicDistance();
      while(Len < 25)//�ٴ��ж��Ƿ����ϰ��������ת������󣬼����ж�
      {    
	  	 Car_Stop();//ͣ��   
       Car_SpinRight(2600, 2600);
		Delay_ms(300);
        Len = (u16)bsp_getUltrasonicDistance();
      }
    }
    else 
	{
		Car_Run(2600); //���ϰ��ֱ��  		
	}
}

//�����������
void app_ultrasonic_servo_mode(void)
{
	int Len = 0;
	int LeftDistance = 0, RightDistance = 0;

	Len = (u16)bsp_getUltrasonicDistance();

    if(Len <= 30)//�������ϰ���ʱ
    {

		Car_Stop();//ͣ���������
		
		Angle_J1 = 180;		// ���
		Delay_ms(500); //�ȴ������λ
		Len = bsp_getUltrasonicDistance();			
		LeftDistance = Len;	  
	 
		Angle_J1 = 0;		// �ұ�
		Delay_ms(500); //�ȴ������λ
		Len = bsp_getUltrasonicDistance();					
		RightDistance = Len;


		Angle_J1 = 90;		//��λ
		Delay_ms(500); //�ȴ������λ

		if((LeftDistance < 22 ) &&( RightDistance < 22 ))//��������������ϰ��￿�ñȽϽ�
		{
			Car_SpinRight(3000, 2000);//��ת��ͷ
			Delay_ms(500); //�ȴ������λ
		}
		else if(LeftDistance >= RightDistance)//��߱��ұ߿տ�
		{      
			Car_SpinLeft(3000, 2000);//��ת
			Delay_ms(500); //�ȴ������λ
		}
		else//�ұ߱���߿տ�
		{
			Car_SpinRight(3000, 2000); //��ת
			Delay_ms(500); //�ȴ������λ
		}
    }
    else if(Len > 30)//�������ϰ���ʱ
    {
		Car_Run(3000); 	 //���ϰ��ֱ��     
    }
}
