
#include "System_Init.h"
#include "HT8_RAM.h"
#include "HT8_LCD.h"
#include "CTM.h"
#include "HT8_MCU_IP_SEL.h"
#include "HT8_ADC.h"
#include "app.h"

/*sysTick_Type systick __attribute__((at(0x180)));*/
phParm_Type phParms;

void lcd_test(void)
{

	/* LCD display driver in CTM interrupt routine */
	GCC_CLRWDT(); 	//clear WDT
	g_u16Num += 1;		//display number
	LcdUpdate(g_u16Num);//update LCD
    GCC_DELAY(200000);    //wait system stable
    if(g_u16Num>9999) g_u16Num = 0;	
}


/**
  * @brief LCD driver main entry point.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
void main()
{
	sys_init();
	
	while(1)
	{
		key_scan();
        key_process();        
 		page_process();
		ADC_START();        //trigger A/D conversion
        GCC_DELAY(400);    //delay 2ms
		led_sleep_app();
	}
}