
#include	"System_Init.h"

/**
  * @brief clear RAM function.
  * @param[in] none.
  * @retval  none.
  */
void ClrRam(void)   //Clear RAM 
{
	_bp=0;
	_mp1=0x80;
	for(_tblp=0;_tblp<128;_tblp++)	//clear bank0
	{
		_iar1=0;
		_mp1++;	
	}
	_bp=1;
	_mp1=0x80;
	for(_tblp=0;_tblp<128;_tblp++)	//clear bank1
	{
		_iar1=0;
		_mp1++;	
	}
	_bp=0;
}


/**
  * @brief system initialization function.
  * @param[in] none.
  * @retval  none.
  */
void SysInit(void)
{
	_smod = 0b00000011;		//_idlen=1,_hlclk=1;set Fsys = FH
	_ctrl = 0;
/*	_wdtc = 0b01010111;		//enable WDT */
	_wdtc=0b10101000;						//Disable WDT/AD/CP
	_cpc  = 0b00001000;
	
	_sledc0 = 0b11111111;	//source current select level3(max)
	_sledc1 = 0b00111111;
	_ifs   = 0;				//pin shared set default value
	_tmpc  = 0;				//disble timer output
	_simc0 = 0b11100000;	//disable SPI IIC
	_simc1 = 0b10000001;
	_acerl = 0;           	//disable ADC

	/* IO Port initialize */
	_pac = 0xff;
	_pbc = 0xff;
	_pcc = 0xff;
	_pdc = 0xff;
}

/******************* (C) COPYRIGHT 2018 Holtek Semiconductor Inc *****END OF FILE****/