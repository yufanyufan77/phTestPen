
#include "HT8_EEPROM.h"


/**
  * @brief EEPROM write function.
  * @param[in] The data you want to write to EEPROM.
  * It can be 0x00~0xff.
  * @param[in] Specifies EEPROM address.
  * It can be 0x00~0x3f for HT66F0175,0x00~0x7f for HT66F0185.
  * @retval None
  */
void EEPROM_Write(u8 Data,u8 adr)
{
	/*config EEPROM init*/
	_dmbp0 = 1;			
	_emi = 0;		//disable global interrupt
	_mp1 = 0x40;
	
	/*config EEPROM address*/
	_eea = adr;	
	/*Write data*/
	_eed = Data;	
		
	/*config EEPROM Write mode*/
	_iar1 |= 0x08;
	_iar1 |= 0x04;
		
	/* waitting for EEPROM write finishing */
	while(_iar1 & 0x04);
	_iar1 = 0;
	_dmbp0 = 0;
	_emi = 1;		//enable global interrupt			
	return;
}
	

/**
  * @brief EEPROM read function.
  * @param[in] Specifies EEPROM address that you want to read.
  * It can be 0x00~0x3f for HT66F0175,0x00~0x7f for HT66F0185.
  * @retval EEPROM data.
  */
u8 EEPROM_Read(u8 adr)
{
	/* config EEPROM init */
	u8 EP_Read_Data;
	_dmbp0 = 1;
	_mp1 = 0x40;
	
	/*config EEPROM address*/
	_eea = adr;
	
	/*config EEPROM Read mode*/
	_iar1 |= 0x02;
	_iar1 |= 0x01;
	
	/* waitting for EEPROM Read finishing */
	while(_iar1 & 0x01);
	_iar1 = 0;
	_dmbp0 = 0;
		
	EP_Read_Data = _eed;		//Read data
	return EP_Read_Data;			
}

/******************* (C) COPYRIGHT 2018 Holtek Semiconductor Inc *****END OF FILE****/