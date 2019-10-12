

#ifndef	_APP_H_
#define	_APP_H_

#include	"ht66f0185.h"
#include	"HT8_RAM.h"
#define opampInit() \
	{               \
		_papu6 = 1; \
		_pac6 = 0;  \
		_paps2 = 1; \
		_paps3 = 1; \
		 _pa6 = 1;	}
#define ledOn() _pc4 = 1
#define ledOff() _pc4 = 0
#define opampOn() _pa6 = 1
#define opampOff() _pa6 = 0
//按键接口初始化
void key_port_init(void);
//按键处理
void key_process(void);
//按键扫描
void key_scan(void);
void ADC_Init_App(void);
void page_process(void);
void sys_init(void);
void led_sleep_app(void);


#endif
