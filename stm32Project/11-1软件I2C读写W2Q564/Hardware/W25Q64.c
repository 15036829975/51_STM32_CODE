#include "stm32f10x.h"                  // Device header
#include "W25Q64.h"
#include "MySPI.h"
#include "W25Q64_ins.h"

void W25Q64_Init(void)
{
	MySPI_Init();
}

void W25Q64_ReadID(uint8_t *MID,uint16_t *DID)
{
	MySPI_Start();
	MySPI_SwaByte(0x9F);
	*MID=MySPI_SwaByte(0xFF);
  *DID=MySPI_SwaByte(0xFF);
	*DID<<=8;
	*DID |= MySPI_SwaByte(0xFF);
  MySPI_Stop();
}
void W25Q64_WriteEnable(void)
{
	MySPI_Start();
	MySPI_SwaByte(W25Q64_WRITE_ENABLE);
	
}
void W25Q64_WaitBusy(void)
{
	uint32_t Timeout;
	Timeout=10000;
	MySPI_Start();
	MySPI_SwaByte(W25Q64_READ_STATUS_REGISTER_1);
	while(MySPI_SwaByte((W25Q64_DUMMY_BYTE&0x01)==0x01))
	{
		Timeout--;
		if(Timeout==0){break;}
    MySPI_Stop();

}}
void W25Q64_PageProgram(uint32_t Address,uint8_t *DataArray,uint16_t Count)
{
	uint16_t i;
	W25Q64_WriteEnable();
	
	MySPI_Start();
	MySPI_SwaByte(W25Q64_PAGE_PROGRAM);
	MySPI_SwaByte(Address >> 16);
	MySPI_SwaByte(Address >> 8);
	MySPI_SwaByte(Address);
	for(i=0;i<Count;i++)
	{
			MySPI_SwaByte(DataArray[i]);

	}
    MySPI_Stop();
    W25Q64_WaitBusy();
}
void W25Q64_SectorErase(uint32_t Address)
{
	W25Q64_WriteEnable();
	MySPI_Start();
	MySPI_SwaByte(W25Q64_SECTOR_ERASE_4KB);
	MySPI_SwaByte(Address >> 16);
	MySPI_SwaByte(Address >> 8);
	MySPI_SwaByte(Address);
	    MySPI_Stop();
    W25Q64_WaitBusy();
}
void W25Q64_ReadData(uint32_t Address,uint8_t *DataArray,uint32_t Count)
{
	uint32_t i;
	MySPI_Start();
	MySPI_SwaByte(W25Q64_READ_DATA);
	MySPI_SwaByte(Address >> 16);
	MySPI_SwaByte(Address >> 8);
	MySPI_SwaByte(Address);
	for(i=0;i<8;i++){DataArray[i]=MySPI_SwaByte(W25Q64_DUMMY_BYTE);}
	
    MySPI_Stop();
}
