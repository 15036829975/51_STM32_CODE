#ifndef __UART_H_
#define __UART_H_

typedef struct
{
    unsigned char 	RX_Cnt;			//�����ֽڼ���
    unsigned short	RX_TimeOut;		//���ճ�ʱ
    unsigned char	B_RX_OK;		//���տ����
} COMx_Define;

#define DEFAULT_RX_TIMEOUT 50   //���ճ�ʱʱ��

#define	COM_RX1_Lenth	120

#define UART_RXNONE 0
#define UART_RXING 1
#define UART_RXOK 2

#define SERIAL_AUTO_LEN 					0xFF

#define UART_FOSC MAIN_Fosc      //System frequency

#define UART_B115200						115200
#define UART_B38400							38400
#define UART_B9600							9600

extern unsigned char xdata RX1_Buffer[COM_RX1_Lenth];

void uart_init(unsigned int baud);
void uart_write2buff(unsigned char dat);	//д�뷢�ͻ��壬ָ��+1
void uart_send(unsigned char *bufs,unsigned char  len);
unsigned char uart_recv_wait(unsigned short wait_ms, unsigned short frame_timeout_ms);
unsigned char uart_recv_check(void);
#endif /*__UART_H_*/


