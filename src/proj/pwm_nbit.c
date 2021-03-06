#include	"Timer_bitname.h"


#include "htc.h"
#include "define.h"
#include "pwm.h"
#include "timer.h"

void init_PWM(void);





/*************************************************************************************************
;
;函数名:	init_PWM
;
;函数功能: 	初始化 PWM 模块 ，用户通过修改相关寄存器进行PWM模块的初始化
;
;			
;
;入口参数:  无
;
;返回值: 	无
;
;备注说明: 	相关寄存器的某些位使用宏定义列出可选的功能组合，用户通过修改相关"宏名"来修改相应配置，
;			可通过"查找/搜索"找到对应的"宏名"来进行调整
;
*************************************************************************************************/
void init_PWM(void)
{
	T1PRLH = 0x00;	//PWM0/1周期寄存器的高2位	b<1:0>
	T1PRLL = 200;		//PWM0/1周期寄存器的低字节	b<7:0>
	
	EPR1 = 0x00;	//PWM1占空比重载寄存器高2位	 b<1:0>
	PRL1L = 100;	//PWM1占空比重载寄存器低字节	 b<7:0>
	
	EPR0 = 0x00;	//PWM0占空比重载寄存器高2位	 b<1:0>
	PRL0L = 50;		//PWM0占空比重载寄存器低字节	 b<7:0>

	TMR1H = 0x00;	//16位Timer1定时器/计数器高字节
	TMR1L = 0x00;	//16位Timer1定时器/计数器低字节
	 

	PWMFS = 1;		//PWM高低频模式选择位	1:PWM以高频模式输出		0:PWM以低频模式输出		(注意:  高频模式下比低频模式下PWM的驱动能力要小)
//	PWMFS = 0;
	
	CPIOD5 = 0;  	//PD5输入/输出设置		1:输入					0:输出
	PWM1OE = 1; 	//PWM1引脚输出使能位	1:PWM1 允许由 PD5 输出		0:PWM1 禁止输出
	PWM1EN = 1; 	//PWM1模块使能位		1:PWM1 模块允许 			0:PWM1 模块禁止

	CPIOD7 = 0;  	//PD7输入/输出设置		1:输入					0:输出
	PWM0OE = 1;		//PWM0引脚输出使能位	1:PWM0 允许由 PD7 输出		0:PWM0 禁止输出
	PWM0EN = 1; 	//PWM0模块使能位		1:PWM0 模块允许 			0:PWM0 模块禁止

	
	T1_CLK_SEL_FOSC();
	T1_CLK_DIV_1();

	TMR1ON = 1;

	
/*
	CPIOC0 = 1;							//禁止 CCP1 引脚输出驱动器
	
	PR2 = 24;							//用户根据需要修改	(PWM周期设置)	 100 = (24 + 1) * 4
	
	CCP1CONbits.P1M = P1M_PWM_MOD_0;	//用户根据需要修改	(增强型 PWM 输出配置位 )
	CCP1CONbits.CCP1M = CCP1M_PWM_C;	//用户根据需要修改	(ECCP1 模式选择位)

	CCPR1L = 0x00;						//用户根据需要修改	PWM 占空比高8位 (可取值:  0~255)		
	CCP1CONbits.DC1B = 0x00;			//用户根据需要修改	PWM 占空比最低2位有效位(可取值:  0~3)

	
	TRISC5 = 0;							//使能 CCP1 引脚输出驱动器

	TMR2IF = 0;
	T2CONbits.T2CKPS = T2CKP_DIV_1;		//用户根据需要修改	(Timer2 时钟预分频比选择位)

	TMR2ON = ENABLE;					//使能 Timer2
	
	STR1A = 1;							//P1A 引脚的 PWM 波形极性受 CCP1M<1:0> 控制

	*/
}
