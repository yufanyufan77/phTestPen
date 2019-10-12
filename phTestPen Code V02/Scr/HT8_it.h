/**
  ******************************************************************************
  * @file HT8_it.h
  * @brief This file  contains the headers of the interrupt handlers.
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

#ifndef _HT8_it_h_
#define _HT8_it_h_
#include "HT8_MCU_IP_SEL.h"

/* interrupt control */
#define	EMI_ENABLE()			(_emi = 1)
#define	EMI_DISABLE()			(_emi = 0)

#define	MF0E_ENABLE()			(_mf0e = 1)
#define	MF0E_DISABLE()			(_mf0e = 0)
#define	MF0F_CLEAR_FLAG()		(_mf0f = 0)

#define	MF1E_ENABLE()			(_mf1e = 1)
#define	MF1E_DISABLE()			(_mf1e = 0)
#define	MF1F_CLEAR_FLAG()		(_mf1f = 0)

#define	MF2E_ENABLE()			(_mf2e = 1)
#define	MF2E_DISABLE()			(_mf2e = 0)
#define	MF2F_CLEAR_FLAG()		(_mf2f = 0)

#endif

/******************* (C) COPYRIGHT 2018 Holtek Semiconductor Inc *****END OF FILE****/