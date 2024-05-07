
#ifndef __APP_MOTOR_H__
#define __APP_MOTOR_H__

#define  LeftMotor_Go()			{GPIO_SetBits(Motor_Port, Left_MotoA_Pin); GPIO_ResetBits(Motor_Port, Left_MotoB_Pin);}
#define  LeftMotor_Back()		{GPIO_ResetBits(Motor_Port, Left_MotoA_Pin); GPIO_SetBits(Motor_Port, Left_MotoB_Pin);}
#define  LeftMotor_Stop()		{GPIO_ResetBits(Motor_Port, Left_MotoA_Pin); GPIO_ResetBits(Motor_Port, Left_MotoB_Pin);}

#define  RightMotor_Go()		{GPIO_SetBits(Motor_Port, Right_MotoA_Pin); GPIO_ResetBits(Motor_Port, Right_MotoB_Pin);}
#define  RightMotor_Back()		{GPIO_ResetBits(Motor_Port, Right_MotoA_Pin); GPIO_SetBits(Motor_Port, Right_MotoB_Pin);}
#define  RightMotor_Stop()		{GPIO_ResetBits(Motor_Port, Right_MotoA_Pin); GPIO_ResetBits(Motor_Port, Right_MotoB_Pin);}

#define  LeftMotorPWM(Speed)	TIM_SetCompare2(TIM4, Speed);
#define  RightMotorPWM(Speed)	TIM_SetCompare1(TIM4, Speed);	


void Car_Run(int Speed);
void Car_Back(int Speed);
void Car_Left(int Speed);
void Car_Right(int Speed);
void Car_Stop(void);
void Car_SpinLeft(int LeftSpeed, int RightSpeed);
void Car_SpinRight(int LeftSpeed, int RightSpeed);


#endif


