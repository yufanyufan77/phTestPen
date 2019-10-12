
#include "HT8_LCD.h"

/*const unsigned char	Trans_Segment[]= {0xf5,0x60,0xb6,0xf2,0x63,0xd3,0xd7,0x70,0xf7,0xf3};  //display 0-9*/

const unsigned char	Trans_Segment[]= {0xeb,0x60,0xc7,0xe5,0x6c,
									    0xad,0xaF,0xe0,0xeF,0xed,
									    0,0x8f/*E*/,0x0e/*r*/,0x04/*-*/,0x8f/*E*/
									    ,0xea/*n*/,0x67/*-d*/};		
/**
  * @brief LCD initialization.
  * @param[in] none.
  * @retval  none.
  */
void LCD_Init(void)
{
//	_slcdc0 = 0b01111111;	//LCDEN=1,100uA
//	_slcdc1 = 0b11000011;	//select  scom2~5	sseg0~1
//	_slcdc2 = 0b10000000;	//select  sseg13
//	_slcdc3 = 0b01100110;	//select  sseg19~20	sseg15~16
//	_slcdc4 = 0b00000001;	//select  sseg22
	
	_slcdc0 = 0b01111111;	//LCDEN=1,100uA
/*	_slcdc0 = 0b01011111;// COM3 COM2 COM1 COM0*/
	_slcdc1 = 0b11110000;//SEG4 SEG5 
	_slcdc2 = 0b10000000;//SEG13
	_slcdc3 = 0b01101110;// SEG20 SEG19 SEG17 SEG16 SEG15
	_slcdc4 = 0b00000000;//
	
	//SEG and COM set output mode and initialized to 0
	COM0 = 0;
	COM1 = 0;
	COM2 = 0;
	COM3 = 0;
	SEG0 = 0;
	SEG1 = 0;
	SEG2 = 0;
	SEG3 = 0;
	SEG4 = 0;
	SEG5 = 0;
	SEG6 = 0;
	SEG7 = 0;
	COM0C = 0;
	COM1C = 0;
	COM2C = 0;
	COM3C = 0;
	SEG0C = 0;
	SEG1C = 0;
	SEG2C = 0;
	SEG3C = 0;
	SEG4C = 0;
	SEG5C = 0;
	SEG6C = 0;
	SEG7C = 0;
	
	g_u16Num = 0;
}


/**
  * @brief LCD COM pin scan.
  * @param[in] none.
  * @retval  none.
  */
void LcdComScan(void)
{
	COM0 = 0; COM1 = 0; COM2 = 0; COM3 = 0;  //LCD output set 0
	SEG0 = 0; SEG1 = 0; SEG2 = 0; SEG3 = 0;
	SEG4 = 0; SEG5 = 0; SEG6 = 0; SEG7 = 0;
		
	switch(g_u8ScanCoun)
	{
		case 0  : case 1  : COM0=1; break;	//COM0 scan
		case 2  : case 3  : COM1=1; break;	//COM1 scan
		case 4  : case 5  : COM2=1; break;	//COM2 scan
		case 6  : case 7  : COM3=1; break;	//COM3 scan
		default : break;
	}
}



/**
  * @brief LCD SEG pin scan.
  * @param[in] none.
  * @retval  none.
  */
void LcdSegScan(void)
{
	_frame=~_frame;					//Switching scanning mode
			
	/* SEG pin scan */
	if(g_u8DspRam[0].bits.bit0)		SEG0=1;
	if(g_u8DspRam[0].bits.bit4)		SEG1=1;
	if(g_u8DspRam[1].bits.bit0)		SEG2=1;
	if(g_u8DspRam[1].bits.bit4)		SEG3=1;
	if(g_u8DspRam[2].bits.bit0)		SEG4=1;
	if(g_u8DspRam[2].bits.bit4)		SEG5=1;
	if(g_u8DspRam[3].bits.bit0)		SEG6=1;
	if(g_u8DspRam[3].bits.bit4)		SEG7=1;
	
	if(g_u8ScanCoun%2)				//scan next COM,right shift 1 bit
	{
		g_u8DspRam[0].byte>>=1;	
		g_u8DspRam[1].byte>>=1;	
		g_u8DspRam[2].byte>>=1;	
		g_u8DspRam[3].byte>>=1;	
	}
}


/**
  * @brief copy data to DspRam structure.
  * @param[in] none.
  * @retval  none.
  */
void CopyRam(void)
{
	unsigned char i;
	for(i = 0; i < 4; i++)
	{
		g_u8DspRam[i].byte = g_u8SegBuf[i];
	}
}


/**
  * @brief look-up table and LCD update.
  * @param[in] Display number.
  * @retval  none.
  */
void LcdUpdate(u16 Num)
{
	if(Num/1000)
		g_u8SegBuf[0] = Trans_Segment[Num/1000];		//look up table for first number
	else
		g_u8SegBuf[0] = 0;		//look up table for first number
		
	g_u8SegBuf[1] = Trans_Segment[Num%1000/100]|0x10;	//look up table for second number
	g_u8SegBuf[2] = Trans_Segment[Num%100/10];		//look up table for third number
	g_u8SegBuf[3] = Trans_Segment[Num%10];		//look up table for third number;							//Do not display
}

//void LcdUpdate(char* str)
//{
//	g_u8SegBuf[0] = 0;		//look up table for first number		
//	g_u8SegBuf[1] = Trans_Segment[Num%1000/100]|0x10;	//look up table for second number
//	g_u8SegBuf[2] = Trans_Segment[Num%100/10];		//look up table for third number
//	g_u8SegBuf[3] = Trans_Segment[Num%10];		//look up table for third number;							//Do not display
//}

void LcdError(void)
{
	g_u8SegBuf[0] = Trans_Segment[13];		//look up table for first number		
	g_u8SegBuf[1] = Trans_Segment[11];	//look up table for second number
	g_u8SegBuf[2] = Trans_Segment[12];		//look up table for third number
	g_u8SegBuf[3] = Trans_Segment[12];		//look up table for third number;							//Do not display
}
void LcdEnd(void)
{
	g_u8SegBuf[0] = 0;						//look up table for first number
	g_u8SegBuf[1] = Trans_Segment[14];		//look up table for second number
	g_u8SegBuf[2] = Trans_Segment[15];		//look up table for third number
	g_u8SegBuf[3] = Trans_Segment[16];		//look up table for third number;	
}		
void Lcd____(void)
{
	g_u8SegBuf[0] = Trans_Segment[13];		//look up table for first number		
	g_u8SegBuf[1] = Trans_Segment[13];	//look up table for second number
	g_u8SegBuf[2] = Trans_Segment[13];		//look up table for third number
	g_u8SegBuf[3] = Trans_Segment[13];		//look up table for third number;							//Do not display
}
void LcdNull(void)
{
	g_u8SegBuf[0] = 0;		//look up table for first number		
	g_u8SegBuf[1] = 0;	//look up table for second number
	g_u8SegBuf[2] = 0;		//look up table for third number
	g_u8SegBuf[3] = 0;		//look up table for third number;							//Do not display
}

/******************* (C) COPYRIGHT 2018 Holtek Semiconductor Inc *****END OF FILE****/