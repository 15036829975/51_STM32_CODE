 /**
    * @brief  GPIO源文件
    * @param  
    * @retval
    */

#include "stm32f10x.h"
#include "stm32f10x_pwr.h"
#include "stm32f10x_bkp.h"
#include "bsp.h"



void MOTOR_GPIO_Init(void)
{		
	/*定义一个GPIO_InitTypeDef类型的结构体*/
	GPIO_InitTypeDef GPIO_InitStructure;

	/*开启外设时钟*/
	RCC_APB2PeriphClockCmd(Motor_RCC, ENABLE); 

	/*选择要控制的GPIOB引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = Left_MotoA_Pin | Left_MotoB_Pin | Right_MotoA_Pin | Right_MotoB_Pin;	

	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	/*调用库函数，初始化GPIOB*/
  	GPIO_Init(Motor_Port, &GPIO_InitStructure);		  

	/* 低电平	*/
	GPIO_SetBits(Motor_Port, Left_MotoA_Pin | Left_MotoB_Pin | Right_MotoA_Pin | Right_MotoB_Pin);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB  | RCC_APB2Periph_AFIO, ENABLE);  //使能GPIO外设和AFIO复用功能模块时钟
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);  //禁能jtag
 
}



void Servo_GPIO_Init(void)
{		
	/*定义一个GPIO_InitTypeDef类型的结构体*/
	GPIO_InitTypeDef GPIO_InitStructure;

	PWR_BackupAccessCmd(ENABLE);//允许修改RTC 和后备寄存器
	RCC_LSEConfig(RCC_LSE_OFF);//关闭外部低速外部时钟信号功能 后，PC13 PC14 PC15 才可以当普通IO用。
	BKP_TamperPinCmd(DISABLE);//关闭入侵检测功能，也就是 PC13，也可以当普通IO 使用
	PWR_BackupAccessCmd(DISABLE);//禁止修改后备寄存器

#ifdef USE_SERVO_J1
	/*开启外设时钟*/
	RCC_APB2PeriphClockCmd(Servo_J1_RCC, ENABLE); 
	/*选择要控制的引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = Servo_J1_PIN;	
	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*调用库函数，初始化PORT*/
  	GPIO_Init(Servo_J1_PORT, &GPIO_InitStructure);		  
#endif

#ifdef USE_SERVO_J2
	/*开启外设时钟*/
	RCC_APB2PeriphClockCmd(Servo_J2_RCC, ENABLE); 
	/*选择要控制的引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = Servo_J2_PIN;	
	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*调用库函数，初始化PORT*/
  	GPIO_Init(Servo_J2_PORT, &GPIO_InitStructure);		  
#endif

#ifdef USE_SERVO_J3
	/*开启外设时钟*/
	RCC_APB2PeriphClockCmd(Servo_J3_RCC, ENABLE); 
	/*选择要控制的引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = Servo_J3_PIN;	
	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*调用库函数，初始化PORT*/
  	GPIO_Init(Servo_J3_PORT, &GPIO_InitStructure);		  
#endif

#ifdef USE_SERVO_J4
	/*开启外设时钟*/
	RCC_APB2PeriphClockCmd(Servo_J4_RCC, ENABLE); 
	/*选择要控制的引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = Servo_J4_PIN;	
	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*调用库函数，初始化Servo_J4_PORT*/
  	GPIO_Init(Servo_J4_PORT, &GPIO_InitStructure);		  
#endif

#ifdef USE_SERVO_J5
	/*开启外设时钟*/
	RCC_APB2PeriphClockCmd(Servo_J5_RCC, ENABLE); 
	/*选择要控制的引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = Servo_J5_PIN;	
	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*调用库函数，初始化Servo_J5_PORT*/
  	GPIO_Init(Servo_J5_PORT, &GPIO_InitStructure);		  
#endif

#ifdef USE_SERVO_J6
	/*开启外设时钟*/
	RCC_APB2PeriphClockCmd(Servo_J6_RCC, ENABLE); 
	/*选择要控制的引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = Servo_J6_PIN;	
	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*调用库函数，初始化Servo_J1_PORT*/
  	GPIO_Init(Servo_J6_PORT, &GPIO_InitStructure);		  
#endif
 
}


void Colorful_GPIO_Init(void)
{
	/*定义一个GPIO_InitTypeDef类型的结构体*/
	GPIO_InitTypeDef GPIO_InitStructure;

	/*开启外设时钟*/
	RCC_APB2PeriphClockCmd(Colorful_Red_RCC, ENABLE); 
	/*选择要控制的引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = Colorful_Red_PIN;	
	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*调用库函数，初始化Servo_J4_PORT*/
  	GPIO_Init(Colorful_Red_PORT, &GPIO_InitStructure);		  

	/*开启外设时钟*/
	RCC_APB2PeriphClockCmd(Colorful_Green_RCC, ENABLE); 
	/*选择要控制的引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = Colorful_Green_PIN;	
	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*调用库函数，初始化Servo_J4_PORT*/
  	GPIO_Init(Colorful_Green_PORT, &GPIO_InitStructure);		  

	/*开启外设时钟*/
	RCC_APB2PeriphClockCmd(Colorful_Blue_RCC, ENABLE); 
	/*选择要控制的引脚*/															   
  	GPIO_InitStructure.GPIO_Pin = Colorful_Blue_PIN;	
	/*设置引脚模式为通用推挽输出*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*设置引脚速率为50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*调用库函数，初始化Servo_J4_PORT*/
  	GPIO_Init(Colorful_Blue_PORT, &GPIO_InitStructure);		  
}

 /**
    * @brief  开启巡线的GPIO口
    * @param  
    * @retval
    */

	void LineWalking_GPIO_Init(void)
	{
		GPIO_InitTypeDef GPIO_InitStructure;
		
#ifdef USE_LINE_L1
		RCC_APB2PeriphClockCmd(LineWalk_L1_RCC,ENABLE);
		
		GPIO_InitStructure.GPIO_Mode= GPIO_Mode_IPU;  //上拉输入
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
      * @brief  避障传感器GPIO初始化
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
      * @brief  寻光GPIO初始化
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
	