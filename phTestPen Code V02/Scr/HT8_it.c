

#include "HT8_it.h"
#include "System_Init.h"

/**
  * @brief external Interruption 0 routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
void __attribute((interrupt(0x04))) INT0_ISR(void)
{
	/* user define */
}

/**
  * @brief compare Interruption routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
#ifdef HT66F0185
void __attribute((interrupt(0x08))) COMP_ISR(void)
{
	/* user define */
}
#endif

/**
  * @brief timer0 Interruption routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
void __attribute((interrupt(0x0C))) Timer0_ISR(void)
{
	/* user define */
}

/**
  * @brief timer1 or timer2 Interruption routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
//void __attribute((interrupt(0x10))) Timer1_2_ISR(void)
//{
//	/* user define */
//}

/**
  * @brief LVD or EEPROM Interruption routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
void __attribute((interrupt(0x14))) LVD_EEPROM_ISR(void)
{
	/* user define */
}
/**
*  中位值平均滤波
* @param pData:没有滤波的数据 
* @param nSize:数据大小 
* @return:滤波数值
*/
 u16 MedianFilter(u16* pData,u8 nSize)
{
   u16 max,min;
    u8 i;
    u16 sum;
    if(nSize>2)
    {
        max = pData[0];
        min = max;
        sum = 0;
        for( i=0;i<nSize;i++)
        {
            sum += pData[i];            
            if(pData[i]>max)
            {
                max = pData[i];   //一个循环之后max就是最大的值
            }

            if(pData[i]<min)
            {
                min = pData[i];   //一个循环之后min就是最小的值
            }
        }

        sum = sum-max-min;       //去掉最大的值和最小的值
        return (sum*10/(nSize-2)); //对N-2个数求平均值          
    }

    return 0;
}

static  sysTick_Type systick __attribute__((at(0x180)));

void ad_entry_tab(u16 adVal)
{
	 static u8 count = 0; 
	   systick.ad[count] = adVal;	
	   count++;
	   count = count%10;
}

/**
  * @brief ADC Interruption routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
//void __attribute((interrupt(0x18))) ADC_ISR(void)
//{   
//
//	float Voltage;
//	u16 temp =0;
//	temp = ADC_READ_VALUE();
//    ad_entry_tab(temp);
//    
//	phParms.initFlag_count.HBit.bitl++;    
//    if(	phParms.initFlag_count.HBit.bitl<10)
//    	return;
//    
//	/* user define */
////	Voltage = ((MedianFilter(systick.ad,5))*281.8)/4096.00;
//	Voltage = ((MedianFilter(systick.ad,10))*2401.00)/4096.00;
//	phParms.Voltage = Voltage;  
//
//}
//void __attribute((interrupt(0x18))) ADC_ISR(void)
//{   
//	 static vu16 g_nADC_ISR_Value;   //AD conversion value
//
//	float Voltage;
//	if(phParms.initFlag_count.HBit.bitl>=10)
//	{
//    	phParms.initFlag_count.HBit.bitl = 10;
//    	Voltage -= Voltage/10.0;
//	}
//	phParms.initFlag_count.HBit.bitl++;
//	/* user define */
//	while(_adbz==1);
//    Voltage += ADC_READ_VALUE();       
//	Voltage = ((Voltage)*2401)/4096.00;
//	phParms.Voltage = Voltage;     
//	phParms.Voltage = phParms.Voltage/10;     
//	phParms.Voltage = phParms.Voltage*10;     
//
//}
#define times 1
void __attribute((interrupt(0x18))) ADC_ISR(void)
{   

    float Voltage;
	static u16 count = 0;
	count++;
    ad_entry_tab(ADC_READ_VALUE());
    if(count<20)
     return;
    Voltage = systick.ad[0]+systick.ad[1]+systick.ad[2]+systick.ad[3]+systick.ad[4]
    		 +systick.ad[5]+systick.ad[6]+systick.ad[7]+systick.ad[8]+systick.ad[9];
/*    if(count<times)return;  */      
	Voltage = Voltage*240.1/4096.00;
	phParms.Voltage = Voltage;     
	phParms.Voltage = phParms.Voltage/10*10;     

}

/**
  * @brief timebase0 Interruption routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
void __attribute((interrupt(0x1C))) TB0_ISR(void)
{
	/* user define */
}


/**
  * @brief timebase1 Interruption routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
void __attribute((interrupt(0x20))) TB1_ISR(void)
{
	/* user define */
}


/**
  * @brief external Interruption 1 routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
void __attribute((interrupt(0x24))) INT1_ISR(void)
{
	/* user define */
}

/******************* (C) COPYRIGHT 2018 Holtek Semiconductor Inc *****END OF FILE****/