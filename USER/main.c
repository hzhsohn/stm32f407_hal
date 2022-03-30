#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "LED/led.h"
#include "KEY/key.h"

#define Stm32f407_Clock  		stm32f40x41x_Clock_Init(336,8,2,7)  	//168Mhz; 
#define Stm32f429_Clock  		Stm32f42x_Clock_Init(384,25,2,8)  		//180Mhz; 


int main(void)
{
    HAL_Init();                     //初始化HAL库
		Stm32f407_Clock;
    delay_init(192);                //初始化延时函数
    uart_init(115200);              //初始化USART
    LED_Init();                     //初始化LED 
    KEY_Init();                     //初始化按键
   
		delay_ms(1500);

		while(1)
		{
		}
}
