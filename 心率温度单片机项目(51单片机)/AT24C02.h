//EEPROM
sbit sda=P1^3;
sbit scl=P1^4;


void delay()
{ ;; }
void start()  //开始信号
{	
	sda=1;
	delay();
	scl=1;
	delay();
	sda=0;
	delay();
}

void stop()   //停止
{
	sda=0;
	delay();
	scl=1;
	delay();
	sda=1;
	delay();
}

void respons()  //应答
{
	uchar i;
	scl=1;
	delay();
	while((sda==1)&&(i<250))i++;
	scl=0;
	delay();
}

void initeeprom()
{
	sda=1;
	delay();
	scl=1;
	delay();
}

void write_byte(uchar date)
{
	uchar i,temp;
	temp=date;


	for(i=0;i<8;i++)
	{
		temp=temp<<1;
		scl=0;
	    delay();
		sda=CY;
		delay();
		scl=1;
		delay();
	//	scl=0;
     //   delay();
	}
	scl=0;
	delay();
	sda=1;
	delay();
}

uchar read_byte()
{
	uchar i,k;
	scl=0;
	delay();
	sda=1;
	delay();
	for(i=0;i<8;i++)
	{
		scl=1;
		delay();	
		k=(k<<1)|sda;
		scl=0;
		delay();	
	}

	return k;
}



void write_add(uchar address,uchar date)
{
	start();
	write_byte(0xa0);
	respons();
	write_byte(address);
	respons();
	write_byte(date);
	respons();
	stop();
}

uchar read_add(uchar address)
{
	uchar date;

	start();
	write_byte(0xa0);
	respons();
	write_byte(address);
	respons();
	start();
	write_byte(0xa1);
	respons();
	date=read_byte();
	stop();
	return date;
}

