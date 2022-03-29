#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "LED/led.h"
#include "KEY/key.h"

int main(void)
{
    HAL_Init();                     //初始化HAL库   
    Stm32_Clock_Init(384,25,2,8);   //设置时钟,180Mhz
    delay_init(192);                //初始化延时函数
    uart_init(115200);              //初始化USART
    LED_Init();                     //初始化LED 
    KEY_Init();                     //初始化按键
   
		delay_ms(1500);

		while(1)
		{
		}
}
