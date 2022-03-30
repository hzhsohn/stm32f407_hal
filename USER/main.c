#include "sys.h"
#include "delay.h"
#include "USART/usart.h"
#include "LED/led.h"
#include "KEY/key.h"
#include "PWM/pwm.h"

#define Stm32f407_Clock  		stm32f40x41x_Clock_Init(336,8,2,7)  	//168Mhz; 
#define Stm32f429_Clock  		Stm32f42x_Clock_Init(384,25,2,8)  		//180Mhz; 

//IO输出初始化
typedef struct _IO_ADDR
{
  GPIO_TypeDef* GPIOx;//引脚组号
  uint16_t      uPin;   //引脚编号
}IO_ADDR;

//电机控制GPIO定义
#define MOTORC_ST		GPIO_PIN_0		//PG0--- 使能
#define MOTORC_MD1  GPIO_PIN_1		//PG1---
#define MOTORC_MD2  GPIO_PIN_2		//PG2
#define MOTORC_MD3  GPIO_PIN_3		//PG3
#define MOTORC_DR		GPIO_PIN_4		//PG4---方向
#define MOTORC_STP  GPIO_PIN_3		//PB3---pwm

IO_ADDR m_MotorGpio[] = {
  
  {GPIOG,MOTORC_ST},//使能
  {GPIOG,MOTORC_DR},//方向信号
  {GPIOG,MOTORC_MD1},//细分1
  {GPIOG,MOTORC_MD2},//细分2
  {GPIOG,MOTORC_MD3},//细分3
  
};

//电机方向信号IO设置
void Motor_IOInit()
{
	int i=0;
	
  GPIO_InitTypeDef GPIO_Initure;
  __HAL_RCC_GPIOA_CLK_ENABLE();  
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE(); 
  __HAL_RCC_GPIOD_CLK_ENABLE();  
	
  //输出初始化
  for(i = 0; i<20;i++)
  {
    GPIO_Initure.Pin = m_MotorGpio[i].uPin;
    GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP;  //推挽输出模式
    GPIO_Initure.Pull = GPIO_PULLUP;          //下拉
    GPIO_Initure.Speed = GPIO_SPEED_HIGH;     //高速
    
    HAL_GPIO_Init(m_MotorGpio[i].GPIOx,&GPIO_Initure);
    HAL_GPIO_WritePin(m_MotorGpio[i].GPIOx, m_MotorGpio[i].uPin,GPIO_PIN_SET);
  }
}

int main(void)
{
    HAL_Init();                     //初始化HAL库
		Stm32f407_Clock;
    delay_init(192);                //初始化延时函数
    uart_init(115200);              //初始化USART
    LED_Init();                     //初始化LED 
    KEY_Init();                     //初始化按键
		//delay_ms(1000);
		
		//Motor_IOInit();
		
		/*
	  PWM_TIM2_Init();
		PWM_TIM3_Init();
		PWM_TIM4_Init();
		PWM_TIM9_Init();
	
	  PWM_TIM2_Set(1000,50);
		PWM_TIM3_Set(2000,50);
		PWM_TIM4_Set(3000,50);
		PWM_TIM9_Set(4000,50);
	*/
		while(1)
		{
				
		}
}
