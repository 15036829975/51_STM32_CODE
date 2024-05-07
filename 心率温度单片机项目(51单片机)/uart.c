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

//����æ��־
bit busy;
//���ڽṹ�����
COMx_Define	COM1;
//���ջ���������
unsigned char 	xdata RX1_Buffer[COM_RX1_Lenth];//���ܻ�����
unsigned short	 RX_frameTimeOut = DEFAULT_RX_TIMEOUT; //֡���ճ�ʱ

void uart_int(void) interrupt 4 using 1
{
    //����һ���ֽ�����ж�
    if(RI)
    {
        RI = 0;
        if(COM1.B_RX_OK == 0)
        {
            //�жϽ��յĻ������Ƿ���
            if(COM1.RX_Cnt >= COM_RX1_Lenth)
            {
                //���������1��
                COM1.B_RX_OK = 1;
            }
            else
            {
                //�����ܵ�����������ջ��档
                RX1_Buffer[COM1.RX_Cnt++] = SBUF;
		//������֡���ݵ�ʱ����������
                COM1.RX_TimeOut = RX_frameTimeOut;
            }
        }
    }
    //����һ���ֽ�����ж�
    if(TI)
    {
        TI = 0;             //Clear transmit interrupt flag
        //�������æ��־λ
        busy = 0;           //Clear transmit busy flag
    }
}

/*
*uart_init
*���ڳ�ʼ��
*baud �趨�� ������
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
    //ʹ�ö�ʱ��2����Ϊ����
    TL2 = RCAP2L = (65536-(UART_FOSC/32/baud)); //Set auto-reload vaule
    TH2 = RCAP2H = (65536-(UART_FOSC/32/baud)) >> 8;
    T2CON = 0x34;			//Timer2 start run
    ES = 1; 				//Enable UART interrupt
    EA = 1; 				//Open master interrupt switch
}

/*
*uart_write2buff
*���͵����ֺ���
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
*����ָ�����ȵ��ַ�
*bufs ���͵�����
*len Ҫ�����ĳ���
*/
void uart_send(unsigned char *bufs,unsigned char len)
{
    if (len != SERIAL_AUTO_LEN)//����SERIAL_AUTO_LEN���Ϊ255��������͵��ַ������Ȳ�����255�����ǰ��û�д����ַ����ȷ���
    {
        while (len--)//�ȴ��������
        {
            uart_write2buff(*bufs);//���͵����ַ�
            bufs ++;//ָ���1
        }
    }
    else//����ֳ����ڻ򳬹�255�������û�д���ֳ�����
    {
        for (; *bufs != 0;	bufs++)  uart_write2buff(*bufs);//���ַ�������ͳ�ȥ
    }
}
/*
*uart_recv_wait
*�ȴ������յ�������
*wait_ms �ȴ���ʱ�䣬����ֱ�ӷ���0
*frame_timeout_ms ���յ�����֡����֮���ʱ������
*/
unsigned char uart_recv_wait(unsigned short wait_ms, unsigned short frame_timeout_ms)
{
    COM1.RX_TimeOut = wait_ms;
    COM1.B_RX_OK = 0;
    RX_frameTimeOut = frame_timeout_ms;

    do
    {
        delay_ms(1);
        if(COM1.RX_TimeOut > 0)		//��ʱ����
        {
            //ÿ1���룬����Ƿ���ճ�ʱ����ɱ�־
            if(--COM1.RX_TimeOut == 0 || COM1.B_RX_OK == 1)
            {
                unsigned char ret;

                ret = COM1.RX_Cnt;
                COM1.RX_Cnt = 0;
                //���ؽ��յ��ֽ���
                return ret;
            }
        }
    }
    while(1);

    return 0;
}

/*
*uart_recv_check
*��鴮�ڵĽ��ջ������Ƿ����յ����ݡ�
*����ֵ:
*UART_RXOK��ʾ����������ɣ�
*UART_RXING ��ʾ���ڽ������ݣ�
*UART_RXNONE ��ʾû�н��յ����ݣ�
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


