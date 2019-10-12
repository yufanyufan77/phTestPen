
#include	"CTM.h"
#include "System_Init.h"


/**
  * @brief CTM initialization function.
  * 2ms even.
  * @param[in] none.
  * @retval  none.
  */
void CTMInit(void)
{
	_tm2c0 = 0b00000000;	//f=fh/4=8/4MHz=2MHz,t=1/f=1/2us
	_tm2c1 = 0b11000001;	//select timer/counter mode,CCRA match clear counter
	_tm2al = 4000 & 0xff;	//CCRA low byte,16bit timer,time out 4000*0.5us = 2000us = 2ms
	_tm2ah = 4000 >> 8;		//CCRA high byte
	_mf1e = 1;				//enable multi-function1 interrupt
	_mf1f = 0;				//clear  multi-function1 interrupt flag
	_t2ae = 1;				//enable CTM CCRA interrupt
	_t2af = 0;				//clear CTM CCRA interrupt flag
	_t2on = 1;
}



/**
  * @brief CTM CCRA interrupt routine.
  * 2ms even,use for LCD scan and update.
  * @param[in] none.
  * @retval  none.
  */
void __attribute((interrupt(0x10))) CTM_DSP_ISR(void)
{
	static sysTick_Type systick __attribute__((at(0x180)));
	static u8 sec=0;
	
	if (!_t2af)					//CTM 2ms time out flag
		return;	
		_t2af = 0;
		
		LcdComScan();			//LCD COM scan
		LcdSegScan();			//LCD SEG scan
		
		g_u8ScanCoun++; 		//next bit
		if (g_u8ScanCoun > 7) 
		{
			g_u8ScanCoun = 0; 	//LCD scan finished
			CopyRam(); 			//copy display data to DspRam
		}
		
	if(systick.checkVoltTick)
		systick.checkVoltTick--;
	if(systick.clock)
	{
		sec++;
		if(sec>250)
		{
			sec = 0;
			systick.clock--;
		}
	}
	if(systick.keyTick)
		systick.keyTick--;
	if(systick.pageTick)
		systick.pageTick--;
	if(systick.ledTick)
		systick.ledTick--;
		
	
}

/******************* (C) COPYRIGHT 2018 Holtek Semiconductor Inc *****END OF FILE****/