
#include "stdint.h"
#include "sys.h"
#include "delay.h"
#include "FreeRTOSLib.h"
#include "USART/usart.h"
#include "LED/led.h"
#include "KEY/key.h"
#include "PWM/pwm.h"

//一只狗
IWDG_HandleTypeDef hiwdg;
//任务句柄--
TaskHandle_t hAppTask1; 
TaskHandle_t hAppTask2; 

//IO输出初始化
typedef struct _IO_ADDR
{
  GPIO_TypeDef* GPIOx;//引脚组号
  uint16_t      uPin;   //引脚编号
}IO_ADDR;

IO_ADDR m_MotorGpio[] = {
  
  {GPIOG,GPIO_PIN_0},//使能
  {GPIOG,GPIO_PIN_1},//方向信号
  {GPIOG,GPIO_PIN_2},//细分1
  {GPIOG,GPIO_PIN_3},//细分2
  
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
  for(i = 0; i<4;i++)
  {
    GPIO_Initure.Pin = m_MotorGpio[i].uPin;
    GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP;  //推挽输出模式
    GPIO_Initure.Pull = GPIO_PULLUP;          //下拉
    GPIO_Initure.Speed = GPIO_SPEED_HIGH;     //高速
    
    HAL_GPIO_Init(m_MotorGpio[i].GPIOx,&GPIO_Initure);
    HAL_GPIO_WritePin(m_MotorGpio[i].GPIOx, m_MotorGpio[i].uPin,GPIO_PIN_SET);
  }
}


void testTask( void *pvParameters )
{
	while(1)
	{		
		HAL_IWDG_Refresh(&hiwdg);
		vTaskDelay(10/configTICK_RATE_HZ);
	}
}	

void testTask2( void *pvParameters )
{
	while(1)
	{
		vTaskDelay(3000/configTICK_RATE_HZ);
	}
}	


int main(void)
{
    HAL_Init();                     								//初始化HAL库
		//在freeRTOSConfig.h里面也要设置CPU频率 configCPU_CLOCK_HZ
		Stm32f429_Clock_Init(384,25,2,8);  							//192Mhz; 
    delay_init(configCPU_CLOCK_HZ/1000000);         //初始化延时函数
    uart_init(115200);              								//初始化USART
    LED_Init();                     								//初始化LED 
    KEY_Init();                     								//初始化按键
	
		//vTaskDelay(3000/configTICK_RATE_HZ);
		//delay_ms(3000);
		
		//test 
		xTaskCreate( testTask, "test", ( uint16_t ) configMINIMAL_STACK_SIZE*2, NULL, 1, &hAppTask1 );
		xTaskCreate( testTask2, "test2", ( uint16_t ) configMINIMAL_STACK_SIZE*2, NULL, 2, &hAppTask2 );
		
		//hi狗来--
		HAL_IWDG_Init(&hiwdg);
		vTaskStartScheduler();
		while(1);
}
