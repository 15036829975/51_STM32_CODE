#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "bsp_adc.h"

void Adc_Init(void)
{
	
	ADC_InitTypeDef ADC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1 , ENABLE ); //使能 ADC1 通道时钟
	RCC_ADCCLKConfig(RCC_PCLK2_Div6); //设置 ADC 分频因子 6

	//72M/6=12,ADC 最大时间不能超过 14M
	//PA0 作为模拟通道输入引脚
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;//模拟输入
	GPIO_Init(GPIOA, &GPIO_InitStructure); //初始化 GPIOA.1
	
	ADC_DeInit(ADC1);      //复位 ADC1,将外设 ADC1 的全部寄存器重设为缺省值
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;  //ADC 独立模式
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;     //单通道模式
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;     //单次转换模式
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;  //转换由软件而不是外部触发启动
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;    //ADC 数据右对齐
	ADC_InitStructure.ADC_NbrOfChannel = 1;    //顺序进行规则转换的 ADC 通道的数目
	ADC_Init(ADC1, &ADC_InitStructure);     //根据指定的参数初始化外设 ADCx
	ADC_Cmd(ADC1, ENABLE);     //使能指定的 ADC1
	ADC_ResetCalibration(ADC1);    //开启复位校准
	while(ADC_GetResetCalibrationStatus(ADC1));    //等待复位校准结束
	ADC_StartCalibration(ADC1);     //开启 AD 校准
	while(ADC_GetCalibrationStatus(ADC1));    //等待校准结束
	
}



 /**
    * @brief  获得实际电池分压前的电压
    * @param  
    * @retval
    */
   float  Get_Battery_Volotage(void)	
	{
		float temp;
		temp = Get_Measure_Volotage();
		temp= temp * 2.627f;  //temp*(20+10)/10;   3;  误差调节到2.827;
		return temp;
		
	}
	
	 /**
      * @brief  获测量原始电压值
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
    * @brief  获得ADC多次测量值
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
    * @brief  获得ADC值
    * @param  
    * @retval
    */
static u16 Get_Adc(u8 ch)
{
	//设置指定 ADC 的规则组通道，设置它们的转化顺序和采样时间
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );
	//通道 1,规则采样顺序值为 1,采样时间为 239.5 周期
	ADC_SoftwareStartConvCmd(ADC1, ENABLE); //使能软件转换功能
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//等待转换结束
	return ADC_GetConversionValue(ADC1); //返回最近一次 ADC1 规则组的转换结果
}
