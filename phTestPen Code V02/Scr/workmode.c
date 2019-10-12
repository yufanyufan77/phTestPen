

#include	"workmode.h"
#include "System_Init.h"
#include "app.h"

void key_wakeup_check(void)
{	
	_pac7 = 1;
	_paps2 = 0;
	_paps3 = 0; //pa7 key1
	_pawu7 = 0;
app:	
	while(!_pa7);//等待抬起
	GCC_DELAY(20000);
	if(!_pa7)
	goto app;
}
void entry_sleep(void)
{
	_emi = 0;
	
	_pa&=0b11100101;//清除所有像素	 	PA1 PA3 PA4 
	_pb&=0b10011001;//PB1 PB2 PB5 PB6
	_pc&=0b11011000;//PC0 PC1 PC2 PC5				
	_pd&=0b11111011;//PD2
	
	_pawu7 = 1;//设置唤醒引脚
	ledOff();
	opampOff();
	_halt();
	_papu7 = 0;	
	key_wakeup_check();
	sys_init();
}

