#ifndef _ONEWIRE_H_
#define _ONEWIRE_H_


unsigned char OneWire_Init(void);
void OneWire_SendBit(unsigned char Bit);
unsigned char OneWire_ReceiverBit(Bit);
void OneWire_SendByte(unsigned char Byte);
unsigned char OneWire_ReceiverByte(void);

#endif