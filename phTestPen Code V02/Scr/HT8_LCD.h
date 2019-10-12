/**
  ******************************************************************************
  * @file HT8_LCD.h
  * @brief The header file of the LCD driver.
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

#ifndef	_HT8_LCD_H_
#define _HT8_LCD_H_

#include "HT66F0185.h"
#include "HT8_RAM.h"

/************* COM mapping setting **************/
//#define		com0	_pc2
//#define		com1	_pc5
//#define		com2	_pa1
//#define		com3	_pa3

#define		COM0	_pc2
#define		COM0C	_pcc2
#define		COM1	_pc5
#define		COM1C	_pcc5
#define		COM2	_pa1
#define		COM2C	_pac1
#define		COM3	_pa3
#define		COM3C	_pac3
/* end */

/************* SEG mapping setting **************/
//#define		seg0	_pb5
//#define		seg1	_pb6
//#define		seg2	_pb2
//#define		seg3	_pb1
//#define		seg4	_pc1
//#define		seg5	_pc0
//#define		seg6	_pa4
//#define		seg7	_pd2

#define		SEG0	_pb2
#define		SEG0C	_pbc2

#define		SEG1	_pb1
#define		SEG1C	_pbc1

#define		SEG2	_pc1
#define		SEG2C	_pcc1

#define		SEG3	_pc0
#define		SEG3C	_pcc0

#define		SEG4	_pa4
#define		SEG4C	_pac4

#define		SEG5	_pd2
#define		SEG5C	_pdc2

#define		SEG6	_pb5
#define		SEG6C	_pbc5

#define		SEG7	_pb6
#define		SEG7C	_pbc6
/* end */

void LCD_Init(void);
void LcdComScan(void);
void LcdSegScan(void);
void CopyRam(void);
void LcdUpdate(u16 g_u16Num);
void LcdError(void);
void LcdEnd(void);
void Lcd____(void);
void LcdNull(void);

#endif

/******************* (C) COPYRIGHT 2018 Holtek Semiconductor Inc *****END OF FILE****/