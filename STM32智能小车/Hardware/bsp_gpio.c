 /**
    * @brief  GPIOԴ�ļ�
    * @param  
    * @retval
    */

#include "stm32f10x.h"
#include "stm32f10x_pwr.h"
#include "stm32f10x_bkp.h"
#include "bsp.h"



void MOTOR_GPIO_Init(void)
{		
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;

	/*��������ʱ��*/
	RCC_APB2PeriphClockCmd(Motor_RCC, ENABLE); 

	/*ѡ��Ҫ���Ƶ�GPIOB����*/															   
  	GPIO_InitStructure.GPIO_Pin = Left_MotoA_Pin | Left_MotoB_Pin | Right_MotoA_Pin | Right_MotoB_Pin;	

	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	/*���ÿ⺯������ʼ��GPIOB*/
  	GPIO_Init(Motor_Port, &GPIO_InitStructure);		  

	/* �͵�ƽ	*/
	GPIO_SetBits(Motor_Port, Left_MotoA_Pin | Left_MotoB_Pin | Right_MotoA_Pin | Right_MotoB_Pin);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB  | RCC_APB2Periph_AFIO, ENABLE);  //ʹ��GPIO�����AFIO���ù���ģ��ʱ��
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);  //����jtag
 
}



void Servo_GPIO_Init(void)
{		
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;

	PWR_BackupAccessCmd(ENABLE);//�����޸�RTC �ͺ󱸼Ĵ���
	RCC_LSEConfig(RCC_LSE_OFF);//�ر��ⲿ�����ⲿʱ���źŹ��� ��PC13 PC14 PC15 �ſ��Ե���ͨIO�á�
	BKP_TamperPinCmd(DISABLE);//�ر����ּ�⹦�ܣ�Ҳ���� PC13��Ҳ���Ե���ͨIO ʹ��
	PWR_BackupAccessCmd(DISABLE);//��ֹ�޸ĺ󱸼Ĵ���

#ifdef USE_SERVO_J1
	/*��������ʱ��*/
	RCC_APB2PeriphClockCmd(Servo_J1_RCC, ENABLE); 
	/*ѡ��Ҫ���Ƶ�����*/															   
  	GPIO_InitStructure.GPIO_Pin = Servo_J1_PIN;	
	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*���ÿ⺯������ʼ��PORT*/
  	GPIO_Init(Servo_J1_PORT, &GPIO_InitStructure);		  
#endif

#ifdef USE_SERVO_J2
	/*��������ʱ��*/
	RCC_APB2PeriphClockCmd(Servo_J2_RCC, ENABLE); 
	/*ѡ��Ҫ���Ƶ�����*/															   
  	GPIO_InitStructure.GPIO_Pin = Servo_J2_PIN;	
	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*���ÿ⺯������ʼ��PORT*/
  	GPIO_Init(Servo_J2_PORT, &GPIO_InitStructure);		  
#endif

#ifdef USE_SERVO_J3
	/*��������ʱ��*/
	RCC_APB2PeriphClockCmd(Servo_J3_RCC, ENABLE); 
	/*ѡ��Ҫ���Ƶ�����*/															   
  	GPIO_InitStructure.GPIO_Pin = Servo_J3_PIN;	
	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*���ÿ⺯������ʼ��PORT*/
  	GPIO_Init(Servo_J3_PORT, &GPIO_InitStructure);		  
#endif

#ifdef USE_SERVO_J4
	/*��������ʱ��*/
	RCC_APB2PeriphClockCmd(Servo_J4_RCC, ENABLE); 
	/*ѡ��Ҫ���Ƶ�����*/															   
  	GPIO_InitStructure.GPIO_Pin = Servo_J4_PIN;	
	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*���ÿ⺯������ʼ��Servo_J4_PORT*/
  	GPIO_Init(Servo_J4_PORT, &GPIO_InitStructure);		  
#endif

#ifdef USE_SERVO_J5
	/*��������ʱ��*/
	RCC_APB2PeriphClockCmd(Servo_J5_RCC, ENABLE); 
	/*ѡ��Ҫ���Ƶ�����*/															   
  	GPIO_InitStructure.GPIO_Pin = Servo_J5_PIN;	
	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*���ÿ⺯������ʼ��Servo_J5_PORT*/
  	GPIO_Init(Servo_J5_PORT, &GPIO_InitStructure);		  
#endif

#ifdef USE_SERVO_J6
	/*��������ʱ��*/
	RCC_APB2PeriphClockCmd(Servo_J6_RCC, ENABLE); 
	/*ѡ��Ҫ���Ƶ�����*/															   
  	GPIO_InitStructure.GPIO_Pin = Servo_J6_PIN;	
	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*���ÿ⺯������ʼ��Servo_J1_PORT*/
  	GPIO_Init(Servo_J6_PORT, &GPIO_InitStructure);		  
#endif
 
}


void Colorful_GPIO_Init(void)
{
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;

	/*��������ʱ��*/
	RCC_APB2PeriphClockCmd(Colorful_Red_RCC, ENABLE); 
	/*ѡ��Ҫ���Ƶ�����*/															   
  	GPIO_InitStructure.GPIO_Pin = Colorful_Red_PIN;	
	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*���ÿ⺯������ʼ��Servo_J4_PORT*/
  	GPIO_Init(Colorful_Red_PORT, &GPIO_InitStructure);		  

	/*��������ʱ��*/
	RCC_APB2PeriphClockCmd(Colorful_Green_RCC, ENABLE); 
	/*ѡ��Ҫ���Ƶ�����*/															   
  	GPIO_InitStructure.GPIO_Pin = Colorful_Green_PIN;	
	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*���ÿ⺯������ʼ��Servo_J4_PORT*/
  	GPIO_Init(Colorful_Green_PORT, &GPIO_InitStructure);		  

	/*��������ʱ��*/
	RCC_APB2PeriphClockCmd(Colorful_Blue_RCC, ENABLE); 
	/*ѡ��Ҫ���Ƶ�����*/															   
  	GPIO_InitStructure.GPIO_Pin = Colorful_Blue_PIN;	
	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*���ÿ⺯������ʼ��Servo_J4_PORT*/
  	GPIO_Init(Colorful_Blue_PORT, &GPIO_InitStructure);		  
}

 /**
    * @brief  ����Ѳ�ߵ�GPIO��
    * @param  
    * @retval
    */

	void LineWalking_GPIO_Init(void)
	{
		GPIO_InitTypeDef GPIO_InitStructure;
		
#ifdef USE_LINE_L1
		RCC_APB2PeriphClockCmd(LineWalk_L1_RCC,ENABLE);
		
		GPIO_InitStructure.GPIO_Mode= GPIO_Mode_IPU;  //��������
		GPIO_InitStructure.GPIO_Pin= LineWalk_L1_PIN;
		GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
		GPIO_Init(LineWalk_L2_PORT, &GPIO_InitStructure);
		
#endif
	
#ifdef USE_LINE_L2
		RCC_APB2PeriphClockCmd(LineWalk_L2_RCC,ENABLE);
		
		GPIO_InitStructure.GPIO_Mode= GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Pin= LineWalk_L2_PIN;
		GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
		GPIO_Init(LineWalk_L2_PORT, &GPIO_InitStructure);
		
#endif		
#ifdef USE_LINE_R1
		RCC_APB2PeriphClockCmd(LineWalk_R1_RCC,ENABLE);
		
		GPIO_InitStructure.GPIO_Mode= GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Pin= LineWalk_R1_PIN;
		GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
		GPIO_Init(LineWalk_R1_PORT, &GPIO_InitStructure);
		
#endif
#ifdef USE_LINE_R2
		RCC_APB2PeriphClockCmd(LineWalk_R2_RCC,ENABLE);
		
		GPIO_InitStructure.GPIO_Mode= GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Pin= LineWalk_R2_PIN;
		GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;
		GPIO_Init(LineWalk_R2_PORT, &GPIO_InitStructure);
		
#endif
	}

	 /**
      * @brief  ���ϴ�����GPIO��ʼ��
      * @param  
      * @retval
      */
	
	void IRAvoid_GPIO_Init(void)
	{
		GPIO_InitTypeDef GPIO_InitStructure;
		
	#ifdef USE_IRAVOID_L1
		
		RCC_APB2PeriphClockCmd(IRAvoid_L1_RCC,ENABLE);
		GPIO_InitStructure.GPIO_Pin=IRAvoid_L1_PIN;
		GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init(IRAvoid_L1_PORT, &GPIO_InitStructure);
		
	#endif	
		
	#ifdef USE_IRAVOID_R1
		
		RCC_APB2PeriphClockCmd(IRAvoid_L1_RCC,ENABLE);
		GPIO_InitStructure.GPIO_Pin=IRAvoid_R1_PIN;
		GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init(IRAvoid_R1_PORT, &GPIO_InitStructure);
	#endif			
	}
	
	 /**
      * @brief  Ѱ��GPIO��ʼ��
      * @param  
      * @retval
      */
	void LightSeeking_GPIO_Init(void)
	{
		GPIO_InitTypeDef GPIO_InitStructure;
#ifdef USE_LIGHTSEEKING_L1
		
		
		RCC_APB2PeriphClockCmd(LightSeek_L1_RCC | RCC_APB2Periph_AFIO,ENABLE);
		GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
		
		GPIO_InitStructure.GPIO_Pin=LightSeek_L1_PIN;
		GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init(LightSeek_L1_PORT,&GPIO_InitStructure);
#endif	
		
#ifdef USE_LIGHTSEEKING_R1
		
		RCC_APB2PeriphClockCmd(LightSeek_R1_RCC,ENABLE);
    GPIO_InitStructure.GPIO_Pin=LightSeek_R1_PIN;
		GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init(LightSeek_R1_PORT,&GPIO_InitStructure);

#endif
	}
	
	
	
	void  Ultrasonic_GPIO_Init(void)
	{
	   GPIO_InitTypeDef GPIO_InitStructure;
#ifdef  USE_ULTRASONIC
	  RCC_APB2PeriphClockCmd(TRIG_RCC | RCC_APB2Periph_AFIC,ENABLE);
		GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
		GPIO_InitStructure.GPIO_Pin=TRIG_PIN;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
  
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

  	GPIO_Init(TRIG_PORT, &GPIO_InitStructure);		 
	  GPIO_ResetBits(TRIG_PORT, TRIG_PIN);


	  RCC_APB2PeriphClockCmd(ECHO_RCC, ENABLE); 
														   
  	GPIO_InitStructure.GPIO_Pin = ECHO_PIN;	

  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   
 
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	
  	GPIO_Init(ECHO_PORT, &GPIO_InitStructure);
		
		
#endif
}
	