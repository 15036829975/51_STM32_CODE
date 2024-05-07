#include <reg52.h>	         //调用单片机头文件
#include "common.h"
#include "ADC0832.h"
#include "lcd1602.h"
#include "uart.h"
#include "DS18B20_One_1.h"
#define uchar unsigned char   //宏定义"uchar"代替"unsigned char"。
#define uint  unsigned int	  //宏定义"uint"用来定义无符号整型数。
#define false 0
#define true 1

//按键引脚定义
sbit key1 = P1^0;
sbit key2 = P1^1;
sbit key3 = P1^2;

sbit BEEP = P2^0;//蜂鸣器

// these variables are volatile because they are used during the interrupt service routine!
volatile unsigned int BPM;                   // used to hold the pulse rate
volatile unsigned long Signal;                // holds the incoming raw data
volatile unsigned int IBI = 600;             // holds the time between beats, must be seeded! 
volatile bit Pulse = false;     // true when pulse wave is high, false when it's low
volatile bit QS = false;        // becomes true when Arduoino finds a beat.
volatile int rate[10];                    // array to hold last ten IBI values
volatile unsigned long sampleCounter = 0;          // used to determine pulse timing
volatile unsigned long lastBeatTime = 0;           // used to find IBI
volatile int Peak =512;                      // used to find peak in pulse wave, seeded
volatile int Trough = 512;                     // used to find trough in pulse wave, seeded
volatile int thresh = 512;                // used to find instant moment of heart beat, seeded
volatile int amp = 100;                   // used to hold amplitude of pulse waveform, seeded
volatile bit firstBeat = true;        // used to seed rate array so we startup with reasonable BPM
volatile bit secondBeat = false;      // used to seed rate array so we startup with reasonable BPM


bit shuaxin=0;
uchar heartrate = 0;
uchar heartrateMax = 150,heartrateMin = 60;//心率上下限
short temperature = 0;//体温值
short temperatureMax = 380;//体温上限值

unsigned char setn = 0;

void Timer_Init(void)	//定时器初始化，定时50ms  
{
		TMOD |= 0x11;	  //定时器0、定时器1工作方式1
		TL0 = 0xCD;		//2ms
		TH0 = 0xF8;
		TR0 = 1;
		EA= 1;
		ET0 = 1;
	  TL1 = 0x00;		//20ms
		TH1 = 0xB8;
	  TR1 = 1;
	  ET1 = 1;
}

void display_set_value()//显示设置的上下限
{
		if(setn == 1)//心率上下限显示
		{
				lcd_write_char(3,1,heartrateMin/100+'0');
				lcd_write_char(4,1,heartrateMin%100/10+'0');
				lcd_write_char(5,1,heartrateMin%10+'0');
			
				lcd_write_char(13,1,heartrateMax/100+'0');
				lcd_write_char(14,1,heartrateMax%100/10+'0');
				lcd_write_char(15,1,heartrateMax%10+'0');
			
			  lcd_write_com(0x80+0x40+5);//心率下限位置
			  lcd_write_com(0x0f);//光标闪烁
		}
		else if(setn == 2)//心率上下限显示
		{
				lcd_write_char(3,1,heartrateMin/100+'0');
				lcd_write_char(4,1,heartrateMin%100/10+'0');
				lcd_write_char(5,1,heartrateMin%10+'0');
			
				lcd_write_char(13,1,heartrateMax/100+'0');
				lcd_write_char(14,1,heartrateMax%100/10+'0');
				lcd_write_char(15,1,heartrateMax%10+'0');
			
			  lcd_write_com(0x80+0x40+15);//心率上限位置
			  lcd_write_com(0x0f);//光标闪烁
		}
		else if(setn == 3)//温度上限
		{
			  lcd_write_char(6,1,temperatureMax/100+'0');
				lcd_write_char(7,1,temperatureMax%100/10+'0');
				lcd_write_char(9,1,temperatureMax%10+'0');
			
			  lcd_write_com(0x80+0x40+9);//温度上限位置
			  lcd_write_com(0x0f);//光标闪烁
		}
}

void keyscan()//按键扫描
{
		if(key1 == 0)//加键按下
		{
				delay_ms(10);//消抖
			  if(key1 == 0)
				{
						while(key1 == 0);
					  setn++;
					  if(setn > 3)//按下次数超过3次，退出设置
						{
								setn = 0;
							  lcd_write_com(0x0C);
							  lcd_write_str(0, 0, "  Heartrate:000 ");
								lcd_write_str(0, 1, "  Temp:00.0 C   ");
								lcd_write_char(11,1,0xdf);
						}
						if(setn == 1)//显示设置心率
						{
							  lcd_write_str(0, 0, "  SET THE HEART ");
								lcd_write_str(0, 1, "XL:000    XH:000");
						}
						if(setn == 3)//显示设置温度
						{
							  lcd_write_str(0, 0, "  SET THE TEMP  ");
								lcd_write_str(0, 1, "      00.0 C    ");
							  lcd_write_char(10,1,0xdf);
						}
						display_set_value();
				}
		}
		if(key2 == 0)//加键按下
		{
				delay_ms(100);//消抖
			  if(key2 == 0)
				{
					  if(setn == 1)
						{
								if(heartrateMax-heartrateMin>1)heartrateMin++;//上限必须大于下限，下限才能加
								display_set_value();//显示
						}
						if(setn == 2)
						{
								if(heartrateMax<120)heartrateMax++;//心率上限最大到120
								display_set_value();
						}
						if(setn == 3)
						{
								if(temperatureMax<999)temperatureMax++;//温度上限最大到999
								display_set_value();
						}
				}
		}
		if(key3 == 0)//减键按下
		{
				delay_ms(100);
			  if(key3 == 0)
				{
					  if(setn == 1)
						{
								if(heartrateMin>0)heartrateMin--;//心率下限最小到0
								display_set_value();//显示
						}
						if(setn == 2)
						{
								if(heartrateMax-heartrateMin>1)heartrateMax--;//上限必须大于下限，上限才能减
								display_set_value();
						}
						if(setn == 3)
						{
								if(temperatureMax>0)temperatureMax--;//温度上限最小到0
								display_set_value();//显示
						}
				}
		}
}

void main()
{
	  uint count=0;
	  char SEND_BUF[]="Heartrate:000,Temp:00.0C\r\n";
	
		lcd_init();//1602初始化
		Timer_Init();//定时器初始化
	  lcd_write_str(0, 0, "  Heartrate:000 ");
	  lcd_write_str(0, 1, "  Temp:00.0 C   ");
	  lcd_write_char(11,1,0xdf);
	  uart_init(9600);
		while(1)
		{
			  keyscan();//按键扫描
			  if(setn == 0)
				{
						if(count++>=1000)
						{
									count=0;
										//显示心率体温值
								lcd_write_char(12,0,heartrate/100+'0');
								lcd_write_char(13,0,heartrate%100/10+'0');
								lcd_write_char(14,0,heartrate%10+'0');
								lcd_write_char(7,1,temperature/100+'0');
								lcd_write_char(8,1,temperature%100/10+'0');
								lcd_write_char(10,1,temperature%10+'0');
							
							  SEND_BUF[10]=heartrate/100+'0';
								SEND_BUF[11]=heartrate%100/10+'0';
								SEND_BUF[12]=heartrate%10+'0';
								SEND_BUF[19]=temperature/100+'0';
								SEND_BUF[20]=temperature%100/10+'0';
								SEND_BUF[22]=temperature%10+'0';
							
							  uart_send(SEND_BUF,26);//串口发送
						}
		        if(((heartrate<=heartrateMin||heartrate>=heartrateMax)&&heartrate!=0)||(temperature>=temperatureMax))//心率温度超限报警
						BEEP = 0;
						else 
						BEEP = 1;
				}
				delay_ms(1);
		}
}  

// Timer 0中断子程序，每2MS中断一次，读取AD值，计算心率值
void Timer0_rountine(void) interrupt 1
{                       
  int N;
	unsigned char i;
	// keep a running total of the last 10 IBI values
  unsigned int runningTotal = 0;                  // clear the runningTotal variable    

	//EA=0;                                      // disable interrupts while we do this
	TL0 = 0xCD;		//2ms
	TH0 = 0xF8;
  Signal = Read_ADC0832(0)<<2;              // read the Pulse Sensor 
  sampleCounter += 2;                         // keep track of the time in mS with this variable
  N = sampleCounter - lastBeatTime;       // monitor the time since the last beat to avoid noise


    //  find the peak and trough of the pulse wave
  if(Signal < thresh && N > (IBI/5)*3){       // avoid dichrotic noise by waiting 3/5 of last IBI
    if (Signal < Trough){                        // T is the trough
      Trough = Signal;                         // keep track of lowest point in pulse wave 
    }
  }

  if(Signal > thresh && Signal > Peak){          // thresh condition helps avoid noise
    Peak = Signal;                             // P is the peak
  }                                        // keep track of highest point in pulse wave

  //  NOW IT'S TIME TO LOOK FOR THE HEART BEAT
  // signal surges up in value every time there is a pulse
  if (N > 250){                                   // avoid high frequency noise
    if ( (Signal > thresh) && (Pulse == false) && (N > (IBI/5)*3) ){        
      Pulse = true;                               // set the Pulse flag when we think there is a pulse
                     // turn on pin 13 LED
      IBI = sampleCounter - lastBeatTime;         // measure time between beats in mS
      lastBeatTime = sampleCounter;               // keep track of time for next pulse

      if(secondBeat){                        // if this is the second beat, if secondBeat == TRUE
        secondBeat = false;                  // clear secondBeat flag
        for(i=0; i<=9; i++){             // seed the running total to get a realisitic BPM at startup
          rate[i] = IBI;                      
        }
      }

      if(firstBeat){                         // if it's the first time we found a beat, if firstBeat == TRUE
        firstBeat = false;                   // clear firstBeat flag
        secondBeat = true;                   // set the second beat flag
        EA=1;                               // enable interrupts again
        return;                              // IBI value is unreliable so discard it
      }   



      for(i=0; i<=8; i++){                // shift data in the rate array
        rate[i] = rate[i+1];                  // and drop the oldest IBI value 
        runningTotal += rate[i];              // add up the 9 oldest IBI values
      }

      rate[9] = IBI;                          // add the latest IBI to the rate array
      runningTotal += rate[9];                // add the latest IBI to runningTotal
      runningTotal /= 10;                     // average the last 10 IBI values 
      BPM = 60000/runningTotal;               // how many beats can fit into a minute? that's BPM!
			if(BPM<=150 && BPM>=60)		//限制BPM最高显示值,最低显示值
			{
					heartrate	= BPM;
			}	
      else 	heartrate=0;	
      QS = true;                              // set Quantified Self flag 
      // QS FLAG IS NOT CLEARED INSIDE THIS ISR
    }                       
  }

  if (Signal < thresh && Pulse == true){   // when the values are going down, the beat is over
                // turn off pin 13 LED
    Pulse = false;                         // reset the Pulse flag so we can do it again
    amp = Peak - Trough;                           // get amplitude of the pulse wave
    thresh = amp/2 + Trough;                    // set thresh at 50% of the amplitude
    Peak = thresh;                            // reset these for next time
    Trough = thresh;
  }

  if (N > 2500){                           // if 2.5 seconds go by without a beat
    thresh = 512;                          // set thresh default
    Peak = 512;                               // set P default
    Trough = 512;                               // set T default
    lastBeatTime = sampleCounter;          // bring the lastBeatTime up to date        
    firstBeat = true;                      // set these to avoid noise
    secondBeat = false;                    // when we get the heartbeat back
  }

  //EA=1;                                   // enable interrupts when youre done!
}// end isr

void Timer1_rountine(void) interrupt 3
{
	  static uchar count2=0;
	  TL1 = 0x00;		//20ms
		TH1 = 0xB8;
		if (QS == true){
			QS = false; // reset the Quantified Self flag for next time
		}
		if(count2++>=25)//500ms读取一次温度
		{
			  count2 = 0 ;
				temperature = DS18B20_TF()*10;//获取温度
		}
}

