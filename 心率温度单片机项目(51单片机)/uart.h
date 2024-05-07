#ifndef __UART_H_
#define __UART_H_

typedef struct
{
    unsigned char 	RX_Cnt;			//接收字节计数
    unsigned short	RX_TimeOut;		//接收超时
    unsigned char	B_RX_OK;		//接收块完成
} COMx_Define;

#define DEFAULT_RX_TIMEOUT 50   //接收超时时间

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
void uart_write2buff(unsigned char dat);	//写入发送缓冲，指针+1
void uart_send(unsigned char *bufs,unsigned char  len);
unsigned char uart_recv_wait(unsigned short wait_ms, unsigned short frame_timeout_ms);
unsigned char uart_recv_check(void);
#endif /*__UART_H_*/


