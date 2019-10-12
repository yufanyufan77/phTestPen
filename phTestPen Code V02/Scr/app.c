#include <HT66F0185.H>

#include "HT8_MCU_IP_SEL.h"
#include "System_Init.h"
#include "HT8_RAM.h"
#include "HT8_LCD.h"
#include "HT8_ADC.h"
#include "HT8_EEPROM.h"
#include "workmode.h"
#include "CTM.h"
#include "app.h"
#include "workmode.h"

static u8 check_voltage(u16 times);

static volatile sysTick_Type systick __attribute__((at(0x180)));

#define key1 _pa7
#define key2 _pb4
#define DebounceTimes 10
#define longpressTimes (5 * 90 * 3)
#define wakeupTimes (2 * 60 * 3)
#define ledTimes 30 * 500

#define main_page 0
#define massure_page 1
#define cal_page 2
#define error_page 3
#define end_page 4
#define ad_page 5
#define press_key_page 6
#define error_cal_page 7
#define flicker_page 8 //闪烁页面

#define error_key 1
#define error_cal 2

#define checkCount 100 //检查次数
#define changeVolt 10  //电压波动范围
/*****************************************ADC部分start*********************************************/

void ADC_Init_App(void)
{
	/* Init ADC peripheral,specify ADC clock,reference Voltage and 
        data alignment type in HT8_ADC.h */
	ADC_Init();

	/* ADC channel select */
	ADC_SelectChannel(ADC_CH0);

	/* enable ADC IP */
	ADC_ENABLE();

	/* enable ADC interrupt */
	ADC_CLEAR_ISR_FLAG();
	ADC_ISR_ENABLE();

	/* enable global interrupt */
	EMI_ENABLE();

	GCC_DELAY(2000); //wait system stable
}




/*****************************************ADC部分end***********************************************/

/*****************************************按键唤醒start*********************************************/

//按键唤醒

/*****************************************按键唤醒end***********************************************/

/*****************************************eeprom start*********************************************/

//	unsigned char phK_4V ;//酸度电压
//	unsigned char phK_9V ;//碱度电压
//	unsigned char phK_6V ;//中性电压
//读取系统参数
void read_sysParam(void)
{
	phParms.initFlag_count.HBit.bith = EEPROM_Read(0);
	phParms.phK_4V.Bit8s[0] = EEPROM_Read(1);
	phParms.phK_4V.Bit8s[1] = EEPROM_Read(2);
	phParms.phK_6V.Bit8s[0] = EEPROM_Read(3);
	phParms.phK_6V.Bit8s[1] = EEPROM_Read(4);
	phParms.phK_9V.Bit8s[0] = EEPROM_Read(5);
	phParms.phK_9V.Bit8s[1] = EEPROM_Read(6);
}
//写系统参数
void write_sysParam(void)
{
	EEPROM_Write(phParms.initFlag_count.HBit.bith, 0);
	EEPROM_Write(phParms.phK_4V.Bit8s[0], 1);
	EEPROM_Write(phParms.phK_4V.Bit8s[1], 2);
	EEPROM_Write(phParms.phK_6V.Bit8s[0], 3);
	EEPROM_Write(phParms.phK_6V.Bit8s[1], 4);
	EEPROM_Write(phParms.phK_9V.Bit8s[0], 5);
	EEPROM_Write(phParms.phK_9V.Bit8s[1], 6);
}
//碱性：918 950mv  中性：686 1230mv  酸性：401 1500mv
//写系统参数
void sysParam_init(void)
{

	read_sysParam();

	if (phParms.initFlag_count.HBit.bith == 6)
		return;
	phParms.initFlag_count.HBit.bith = 6;
//	phParms.phK_4V.Bit16s = 1380; //258
//	phParms.phK_6V.Bit16s = 1230; //633
//	phParms.phK_9V.Bit16s = 1080;
	phParms.phK_4V.Bit16s = 1500; //258
	phParms.phK_6V.Bit16s = 1230; //633
	phParms.phK_9V.Bit16s = 918;
	write_sysParam();
}

/*****************************************eeprom end***********************************************/

/*****************************************按键处理start*********************************************/
//按键接口初始化
void key_port_init(void)
{
	//pb4 key2、pa7 key1
	_pbpu4 = 1;
	_pbc4 = 1;
	_pbps2 = 0;
	_pbps3 = 0; //pb4 key2
	_papu7 = 0;
	_pac7 = 1;
	_paps2 = 0;
	_paps3 = 0; //pa7 key1
}
u8 read_key(void)
{
	u8 key_val = 0;
	key_val = key2;
	key_val = (key_val << 1) | key1;
	return ((~key_val) & 0x03);
}
//按键扫描
void key_scan(void)
{
	static u8 state = 0;
	static u8 key_val = 0;

	switch (state)
	{
	case 0: //没有按下
		if (read_key())
		{
			state = 1;
			systick.keyTick = DebounceTimes;
		}
		key_val = 0;
		break;

	case 1: //去抖动
		if (systick.keyTick)
			break;
		if ((key_val = read_key()))
		{
			state = 2;			  //按键按下
			systick.keyTick = longpressTimes; //长按定时
			break;
		}
		state = 0;
		break;
	case 2: //等待抬起
		if (read_key() == 0x03)
		{

			systick.key_val = 5;
			//返回错误
			break;
		}

		if (!read_key())
		{
			state = 4;
			systick.keyTick = DebounceTimes;
			break;
		}

		if (systick.keyTick)
			break;
		key_val = key_val + 2;
		systick.key_val = key_val;
		state = 3;
		break;
	case 3: //长按
		if (!read_key())
		{
			key_val = 0;
			state = 4;
			systick.keyTick = DebounceTimes;
			break;
		}
		break;
	case 4: //抬起
		if (systick.keyTick)
			break;
		systick.key_val = key_val;
		state = 0;
		break;
	}
}
//按键处理
void key_process(void)
{


	if (systick.error)
	{

		switch (systick.error)
		{
		case error_cal:
			phParms.page = error_page;
			break;
		case error_key:
			phParms.page = error_page;
			break;
		}
	}

	if (systick.key_val)
	{

		systick.ledTick = ledTimes;
		systick.clock = wakeupTimes;
		ledOn();
		systick.error = 0;
	}
		
	switch (systick.key_val)
	{
	case 1: //key1按下
	case 3: //key1长按下
		GCC_DELAY(20000);
		entry_sleep();
		break;
#if debug
	case 2: //key2按下
		if(phParms.page == main_page || phParms.page == massure_page)
			phParms.page = ad_page;
		else
		{
			phParms.page = main_page;
			break;
		}
		break;
	case 6: //有按键按下
		//phParms.page = press_key_page;
		break;
#endif
		break;
	case 4: //key2长按下 校准
		phParms.page = cal_page;
		break;
	case 5: //key1 key2同时按下
		phParms.page = error_page;
		break;
	}

	systick.key_val = 0;
}

//自动校准
//返回值：0：电压不稳校验失败 1：校验成功 2：正在校验
u8 auto_standardize(void)
{
	u8 volt_state;
	volt_state = check_voltage(500 * 10);
	switch (volt_state)
	{
	case 0: //电压不稳定
		// phParms.error = error_cal;
		phParms.page = error_cal_page;
		return 0;
	case 1: //电压稳定
		phParms.page = end_page;
		break;
	case 2: //正在检测电压
		return 2;

	default:
		break;
	}

	if (phParms.Voltage > 1300) //酸性校准
	{
		systick.cal_flag = 1;
		phParms.phK_4V.Bit16s = phParms.Voltage;
	}
	if (phParms.Voltage > 1150 && phParms.Voltage < 1300) //中性校准
	{
		systick.cal_flag = 2;
		phParms.phK_6V.Bit16s = phParms.Voltage;
	}
	if (phParms.Voltage < 1150) //碱性校准
	{
		systick.cal_flag = 3;
		phParms.phK_9V.Bit16s = phParms.Voltage;
	}
	write_sysParam();
	return 1;
}
/*****************************************按键处理end***********************************************/

/*****************************************页面处理start*******************************************/

//碱性：918 950mv  中性：686 1230mv  酸性：401 1500mv

//酸性显示
void dis_ph0(void)
{
	float ph_val = 0;
	u16 temp = 0;
	
	ph_val = (285.00 / (phParms.phK_4V.Bit16s - phParms.phK_6V.Bit16s)) * (phParms.Voltage - phParms.phK_6V.Bit16s);
	if (ph_val >= 686)
		ph_val = 686;
	ph_val = 686 - ph_val;
	
	if(ph_val>660)
		ph_val=686;
	if(ph_val<413 && ph_val>390)
		ph_val=401;
	
	LcdUpdate(ph_val);
}
//碱性显示
void dis_ph14(void)
{
	float ph_val = 0;
	ph_val = 686 + 232.00 / (phParms.phK_6V.Bit16s - phParms.phK_9V.Bit16s) * (phParms.phK_6V.Bit16s - phParms.Voltage);
	if (ph_val >= 1400)
		ph_val = 1400;
	
	if(ph_val<700)
		ph_val=686;
	if(ph_val<932&&ph_val>906)
		ph_val=918;
	
	LcdUpdate(ph_val);
}
//中性显示
void dis_ph7(void)
{
	LcdUpdate(686);
}

//监测电压波动
//0：不稳定
//1：稳定
//2：正在监测

static u8 check_voltage(u16 times)
{
	static sys_bits temp_flag;
	static u16 volt = 0;
	static u8 count = 0;

	if (temp_flag.bits.bit0 == 0) //开启一个times*2ms定时、来检测电压稳定性
	{
		systick.checkVoltTick = times;
		volt = phParms.Voltage;
		temp_flag.bits.bit0 = 1;
	}

	if ((phParms.Voltage + changeVolt >= volt && phParms.Voltage <= volt + changeVolt))
	{
		volt = phParms.Voltage;
		if (++count > checkCount)
		{
			count = 0;
			temp_flag.Bit8s = 0;
			return 1;
		}
	}
	else
	{
		count = 0;
	}

	if (systick.checkVoltTick == 0)
	{
		temp_flag.bits.bit0 = 0;

		if (count >= checkCount)
		{
			count = 0;
			return 1;
		}
		else
		{
			count = 0;
			return 0;
		}
	}

	return 2;
}

//显示 ph值
void dis_phVal(void)
{
	if (phParms.phK_6V.Bit16s == phParms.Voltage)
	{
		dis_ph7();
	}
	else if (phParms.phK_6V.Bit16s < phParms.Voltage)
	{
		dis_ph0();
	}
	else if (phParms.phK_6V.Bit16s > phParms.Voltage)
	{
		dis_ph14();
	}
}

//显示 ph值
void dis_cal_phVal(void)
{
	if (systick.cal_flag == 1)
	{
		LcdUpdate(401);
	}
	else if (systick.cal_flag == 2)
	{
		LcdUpdate(686);
	}
	else if (systick.cal_flag == 3)
	{
		LcdUpdate(918);
	}
}

void page_process(void)
{
	static sys_bits temp_flag;

	switch (phParms.page)
	{
	case main_page: //主界面
		//如果波动比较频繁，显示0.00
		temp_flag.Bit8s = check_voltage(250);
		switch (temp_flag.Bit8s)
		{
		case 2:				//正在监测
		case 0:				//不稳定
			break;
		case 1: //稳定
			phParms.page = massure_page;
			temp_flag.HBit.bith = 0;
			dis_phVal(); //update LCD
			break;
		}
		break;

	case massure_page:
		temp_flag.HBit.bitl = check_voltage(250);
		switch (temp_flag.HBit.bitl)
		{
		case 0: //不稳定			
			temp_flag.HBit.bith++;
			if(temp_flag.HBit.bith>20)
			phParms.page = main_page;
			break;
		case 1: //稳定
			temp_flag.HBit.bith=0;
			if (!systick.pageTick)
			{
				systick.pageTick = 250;
				dis_phVal(); //update LCD
			}
			break;
		case 2: //正在监测
			break;
		}
		break;

	case cal_page: //校准、标定
		temp_flag.HBit.bitl = auto_standardize();
		switch (temp_flag.HBit.bitl)
		{
		case 0: //电压不稳定，校准失败
			phParms.page = error_cal_page;
			systick.pageTick = 2 * 500;
			Lcd____();
			break;
		case 1: //标定完成
			phParms.page = flicker_page;
			systick.pageTick = 2 * 250;
			temp_flag.Bit8s = 0;
			dis_cal_phVal();
			break;
		case 2: //正在标定
			LcdUpdate(phParms.Voltage);
			break;
		}
		break;

	case error_page:
		Lcd____();
		break;

	case flicker_page:
		//闪4下
		if (!systick.pageTick)
		{
			systick.pageTick = 2 * 250;
			temp_flag.HBit.bith = !temp_flag.HBit.bith ;
			if (temp_flag.HBit.bith )
				LcdNull();
			else
				dis_cal_phVal();
			temp_flag.HBit.bitl++;
		}
		if(temp_flag.HBit.bitl<8)
			break;
			
		phParms.page = end_page;
		systick.pageTick = 500;
		LcdEnd();
		break;

	case end_page:
		if (!systick.pageTick)
		{
			phParms.page = main_page;
		}
		//等待一秒下
		break;

	case error_cal_page:
		if (!systick.pageTick)
		{
			phParms.page = main_page;
		}
		break;

#if debug
	case press_key_page:
		Lcd____();
		break;
	case ad_page:
		if (systick.checkVoltTick == 0)
		{
			temp_flag.HBit.bitl++;
			systick.checkVoltTick = 500;
		}
		if (temp_flag.HBit.bitl >= 4)
			temp_flag.HBit.bitl = 0;

		if (temp_flag.HBit.bitl == 0)
			LcdUpdate(phParms.Voltage);
		if (temp_flag.HBit.bitl == 1)
			LcdUpdate(phParms.phK_4V.Bit16s);
		if (temp_flag.HBit.bitl == 2)
			LcdUpdate(phParms.phK_6V.Bit16s);
		if (temp_flag.HBit.bitl == 3)
			LcdUpdate(phParms.phK_9V.Bit16s);
		if (temp_flag.HBit.bitl == 4)
			dis_phVal();;
		break;
#endif
	}
}

/*****************************************页面end*********************************************/

/*****************************************系统初始化start*******************************************/

void led_init(void)
{
	_pcpu4 = 1;
	_pcc4 = 0;
	_pcps2 = 1;
	_pcps3 = 1;
}

void led_sleep_app(void)
{
	if (!systick.ledTick)
		ledOff();

	if (!systick.clock)
		entry_sleep();
}

/*****************************************系统初始化end*********************************************/

/*****************************************系统初始化start*******************************************/


void sys_init(void)
{
	ClrRam();		 //clear RAM
	SysInit();		 //system initialization
	LCD_Init();		 //LCD initialization
	ADC_Init_App();  //AD接口初始化
	CTMInit();		 //CTM initialization
	key_port_init(); //按键接口初始化
	sysParam_init();
	ledOn();
	opampInit();	 //运放电源接口初始化
	opampOn();		 //打开运放电源
	_emi = 1; //enable global interrupt
	systick.clock = wakeupTimes;
	systick.ledTick = ledTimes;
	phParms.page = main_page;
	LcdUpdate(700); //update LCD
}

/*****************************************系统初始化end*********************************************/
