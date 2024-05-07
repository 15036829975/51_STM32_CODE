#include "reg52.h"
#include "common.h"
#include "uart.h"

/*Define UART parity mode*/
#define NONE_PARITY     0   //None parity
#define ODD_PARITY      1   //Odd parity
#define EVEN_PARITY     2   //Even parity
#define MARK_PARITY     3   //Mark parity
#define SPACE_PARITY    4   //Space parity

#define PARITYBIT NONE_PARITY   //Testing even parity

//发送忙标志
bit busy;
//串口结构体变量
COMx_Define	COM1;
//接收缓冲区变量
unsigned char 	xdata RX1_Buffer[COM_RX1_Lenth];//接受缓存区
unsigned short	 RX_frameTimeOut = DEFAULT_RX_TIMEOUT; //帧接收超时

void uart_int(void) interrupt 4 using 1
{
    //接收一个字节完成中断
    if(RI)
    {
        RI = 0;
        if(COM1.B_RX_OK == 0)
        {
            //判断接收的缓冲区是否满
            if(COM1.RX_Cnt >= COM_RX1_Lenth)
            {
                //接收完成置1。
                COM1.B_RX_OK = 1;
            }
            else
            {
                //将接受的数据填入接收缓存。
                RX1_Buffer[COM1.RX_Cnt++] = SBUF;
		//重置两帧数据的时间间隔变量。
                COM1.RX_TimeOut = RX_frameTimeOut;
            }
        }
    }
    //发送一个字节完成中断
    if(TI)
    {
        TI = 0;             //Clear transmit interrupt flag
        //清除发送忙标志位
        busy = 0;           //Clear transmit busy flag
    }
}

/*
*uart_init
*串口初始化
*baud 设定的 波特率
*/

void uart_init(unsigned int baud)
{
#if (PARITYBIT == NONE_PARITY)
    SCON = 0x50;			//8-bit variable UART
#elif (PARITYBIT == ODD_PARITY) || (PARITYBIT == EVEN_PARITY) || (PARITYBIT == MARK_PARITY)
    SCON = 0xda;			//9-bit variable UART, parity bit initial to 1
#elif (PARITYBIT == SPACE_PARITY)
    SCON = 0xd2;			//9-bit variable UART, parity bit initial to 0
#endif

    COM1.B_RX_OK = 0;
    //使用定时器2，作为串口
    TL2 = RCAP2L = (65536-(UART_FOSC/32/baud)); //Set auto-reload vaule
    TH2 = RCAP2H = (65536-(UART_FOSC/32/baud)) >> 8;
    T2CON = 0x34;			//Timer2 start run
    ES = 1; 				//Enable UART interrupt
    EA = 1; 				//Open master interrupt switch
}

/*
*uart_write2buff
*发送单个字函数
*/
void uart_write2buff(unsigned char dat)
{
    
    while (busy);			//Wait for the completion of the previous data is sent
    ACC = dat;				//Calculate the even parity bit P (PSW.0)
    if (P)					//Set the parity bit according to P
    {
#if (PARITYBIT == ODD_PARITY)
        TB8 = 0;			//Set parity bit to 0
#elif (PARITYBIT == EVEN_PARITY)
        TB8 = 1;			//Set parity bit to 1
#endif
    }
    else
    {
#if (PARITYBIT == ODD_PARITY)
        TB8 = 1;			//Set parity bit to 1
#elif (PARITYBIT == EVEN_PARITY)
        TB8 = 0;			//Set parity bit to 0
#endif
    }
    busy = 1;
    SBUF = ACC; 			//Send data to UART buffer
}
/*
*uart_send
*发送指定长度的字符
*bufs 发送的数据
*len 要发生的长度
*/
void uart_send(unsigned char *bufs,unsigned char len)
{
    if (len != SERIAL_AUTO_LEN)//这里SERIAL_AUTO_LEN最大为255，如果发送的字符串长度不超过255，都是按用户写入的字符长度发送
    {
        while (len--)//等待发送完成
        {
            uart_write2buff(*bufs);//发送单个字符
            bufs ++;//指针加1
        }
    }
    else//如果字长等于或超过255，不按用户写入字长发送
    {
        for (; *bufs != 0;	bufs++)  uart_write2buff(*bufs);//把字符逐个发送出去
    }
}
/*
*uart_recv_wait
*等待串口收到的数据
*wait_ms 等待的时间，超过直接返回0
*frame_timeout_ms 接收的两个帧数据之间的时间间隔。
*/
unsigned char uart_recv_wait(unsigned short wait_ms, unsigned short frame_timeout_ms)
{
    COM1.RX_TimeOut = wait_ms;
    COM1.B_RX_OK = 0;
    RX_frameTimeOut = frame_timeout_ms;

    do
    {
        delay_ms(1);
        if(COM1.RX_TimeOut > 0)		//超时计数
        {
            //每1毫秒，检查是否接收超时或完成标志
            if(--COM1.RX_TimeOut == 0 || COM1.B_RX_OK == 1)
            {
                unsigned char ret;

                ret = COM1.RX_Cnt;
                COM1.RX_Cnt = 0;
                //返回接收的字节数
                return ret;
            }
        }
    }
    while(1);

    return 0;
}

/*
*uart_recv_check
*检查串口的接收缓冲区是否有收到数据。
*返回值:
*UART_RXOK表示接收数据完成；
*UART_RXING 表示正在接收数据；
*UART_RXNONE 表示没有接收到数据；
*/
unsigned char uart_recv_check(void)
{
    if (COM1.B_RX_OK == 1)
    {
        return UART_RXOK;
    }
    if (COM1.RX_Cnt > 0)
    {
        return UART_RXING;
    }
    return UART_RXNONE;
}


