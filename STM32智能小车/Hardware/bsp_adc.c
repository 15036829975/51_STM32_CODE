#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "bsp_adc.h"

void Adc_Init(void)
{
	
	ADC_InitTypeDef ADC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1 , ENABLE ); //ʹ�� ADC1 ͨ��ʱ��
	RCC_ADCCLKConfig(RCC_PCLK2_Div6); //���� ADC ��Ƶ���� 6

	//72M/6=12,ADC ���ʱ�䲻�ܳ��� 14M
	//PA0 ��Ϊģ��ͨ����������
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;//ģ������
	GPIO_Init(GPIOA, &GPIO_InitStructure); //��ʼ�� GPIOA.1
	
	ADC_DeInit(ADC1);      //��λ ADC1,������ ADC1 ��ȫ���Ĵ�������Ϊȱʡֵ
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;  //ADC ����ģʽ
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;     //��ͨ��ģʽ
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;     //����ת��ģʽ
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;  //ת��������������ⲿ��������
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;    //ADC �����Ҷ���
	ADC_InitStructure.ADC_NbrOfChannel = 1;    //˳����й���ת���� ADC ͨ������Ŀ
	ADC_Init(ADC1, &ADC_InitStructure);     //����ָ���Ĳ�����ʼ������ ADCx
	ADC_Cmd(ADC1, ENABLE);     //ʹ��ָ���� ADC1
	ADC_ResetCalibration(ADC1);    //������λУ׼
	while(ADC_GetResetCalibrationStatus(ADC1));    //�ȴ���λУ׼����
	ADC_StartCalibration(ADC1);     //���� AD У׼
	while(ADC_GetCalibrationStatus(ADC1));    //�ȴ�У׼����
	
}



 /**
    * @brief  ���ʵ�ʵ�ط�ѹǰ�ĵ�ѹ
    * @param  
    * @retval
    */
   float  Get_Battery_Volotage(void)	
	{
		float temp;
		temp = Get_Measure_Volotage();
		temp= temp * 2.627f;  //temp*(20+10)/10;   3;  �����ڵ�2.827;
		return temp;
		
	}
	
	 /**
      * @brief  �����ԭʼ��ѹֵ
      * @param  
      * @retval
      */
	float Get_Measure_Volotage(void)
{
	u16 adcx;
	float temp;

	adcx=Get_Adc_Average(ADC_Channel_0, 10);
	temp=(float)adcx*(3.3/4096);
	return temp;
}
 /**
    * @brief  ���ADC��β���ֵ
    * @param  
    * @retval
    */
static u16 Get_Adc_Average(u8 ch, u8 times)
{
	u32 temp_val=0;
	u8 t;
	for(t=0;t<times;t++)
	{ 
		temp_val+=Get_Adc(ch);
		Delay_ms(5);
	}
	return temp_val/times;
}

 /**
    * @brief  ���ADCֵ
    * @param  
    * @retval
    */
static u16 Get_Adc(u8 ch)
{
	//����ָ�� ADC �Ĺ�����ͨ�����������ǵ�ת��˳��Ͳ���ʱ��
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );
	//ͨ�� 1,�������˳��ֵΪ 1,����ʱ��Ϊ 239.5 ����
	ADC_SoftwareStartConvCmd(ADC1, ENABLE); //ʹ�����ת������
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//�ȴ�ת������
	return ADC_GetConversionValue(ADC1); //�������һ�� ADC1 �������ת�����
}
