/**
  ******************************************************************************
  * @file System_Init.h
  * @brief The header file of the system initialization.
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

#ifndef	_SYSTEM_INIT_H_
#define	_SYSTEM_INIT_H_

#include	"ht66f0185.h"
#include	"HT8_RAM.h"


typedef struct {
	unsigned char bit0 : 1;
	unsigned char bit1 : 1;
	unsigned char bit2 : 1;
	unsigned char bit3 : 1;
	unsigned char bit4 : 1;
	unsigned char bit5 : 1;
	unsigned char bit6 : 1;
	unsigned char bit7 : 1;
} sys_1bit;

typedef struct {
	unsigned char bitl : 4;
	unsigned char bith : 4;
} sys_HBit;


typedef union {
	u8 Bit8s;
	sys_1bit bits;
	sys_HBit HBit;
} sys_bits;

typedef union {
	u16 Bit16s;
	u8 Bit8s[2];
} sys_16bits;

typedef struct phParm
{
	sys_bits initFlag_count ;  //初始化标志位和自家次数
	sys_16bits phK_4V ;//酸度电压
	sys_16bits phK_9V ;//碱度电压
	sys_16bits phK_6V ;//中性电压
	u16 Voltage; 
	u8 page; 
}phParm_Type;


typedef struct systicks
{ 
	u8 key_val ;//键值
	u8 error;
	u16 ad[20]; 
	u8 cal_flag; 
	u16 clock; 
	u16 checkVoltTick; 
	u16 keyTick;
	u16 pageTick; 
	u16 ledTick; 
}sysTick_Type;

extern phParm_Type phParms;
void ClrRam(void);   //Clear RAM 
void SysInit(void);

#define  debug  		0
#endif

/******************* (C) COPYRIGHT 2018 Holtek Semiconductor Inc *****END OF FILE****/