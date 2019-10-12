/**
  ******************************************************************************
  * @file HT8_RAM.h
  * @brief The header file of the RAM.
  * @author Holtek Semiconductor Inc.
  * @version V1.0.0
  * @date 2018-12-20
  ******************************************************************************
  * @attention
  *
  * Firmware Disclaimer Information
  *
  * 1. The customer hereby acknowledges and agrees that the program technical documentation, including the
  *    code, which is supplied by Holtek Semiconductor Inc., (hereinafter referred to as "HOLTEK") is the
  *    proprietary and confidential intellectual property of HOLTEK, and is protected by copyright law and
  *    other intellectual property laws.
  *
  * 2. The customer hereby acknowledges and agrees that the program technical documentation, including the
  *    code, is confidential information belonging to HOLTEK, and must not be disclosed to any third parties
  *    other than HOLTEK and the customer.
  *
  * 3. The program technical documentation, including the code, is provided "as is" and for customer reference
  *    only. After delivery by HOLTEK, the customer shall use the program technical documentation, including
  *    the code, at their own risk. HOLTEK disclaims any expressed, implied or statutory warranties, including
  *    the warranties of merchantability, satisfactory quality and fitness for a particular purpose.
  *
  * <h2><center>Copyright (C) Holtek Semiconductor Inc. All rights reserved</center></h2>
  ************************************************************************************************************/


/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef	_HT8_RAM_H_
#define	_HT8_RAM_H_

#include "HT8_Type.h"

typedef	struct	{
		unsigned char	bit0 : 1;
		unsigned char	bit1 : 1;
		unsigned char	bit2 : 1;
		unsigned char	bit3 : 1;
		unsigned char	bit4 : 1;
		unsigned char	bit5 : 1;
		unsigned char	bit6 : 1;
		unsigned char	bit7 : 1;	
		} _8bit;
		
typedef	union {
		_8bit	bits;
		unsigned char byte;	
		}_byte8;


								
volatile	extern		_byte8		g_u8DspRam[4]; 		//
volatile 	extern		u8 			g_u8SegBuf[4]; 		//
volatile	extern 		u8 			g_u8ScanCoun;		//delay counter
volatile 	extern		u16 		g_u16Num;			//display data,0~999

#endif

/******************* (C) COPYRIGHT 2018 Holtek Semiconductor Inc *****END OF FILE****/