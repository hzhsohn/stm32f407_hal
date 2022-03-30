#include "stm32f4xx_hal.h"
#include "pwm.h"

TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim9;

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

//-----------------------------------------
//
void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim)
{
  GPIO_InitTypeDef GPIO_Initure; // GPIO初始化结构变量--
  if(htim->Instance == TIM2)
  {
    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_Initure.Pin=GPIO_PIN_3;           
    GPIO_Initure.Mode=GPIO_MODE_AF_PP;  	
    GPIO_Initure.Pull=GPIO_PULLUP;         
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;     
    GPIO_Initure.Alternate= GPIO_AF1_TIM2;	
    HAL_GPIO_Init(GPIOB,&GPIO_Initure);
  }
	else if(htim->Instance == TIM3)
  {
    __HAL_RCC_GPIOB_CLK_ENABLE();	
    GPIO_Initure.Pin=GPIO_PIN_5;           
    GPIO_Initure.Mode=GPIO_MODE_AF_PP;  	
    GPIO_Initure.Pull=GPIO_PULLUP;         
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;     
    GPIO_Initure.Alternate= GPIO_AF2_TIM3;	
    HAL_GPIO_Init(GPIOB,&GPIO_Initure);
  }
  else if(htim->Instance == TIM4)
  {
    __HAL_RCC_GPIOB_CLK_ENABLE();	
    GPIO_Initure.Pin=GPIO_PIN_8;           
    GPIO_Initure.Mode=GPIO_MODE_AF_PP;  	
    GPIO_Initure.Pull=GPIO_PULLUP;         
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;     
    GPIO_Initure.Alternate= GPIO_AF2_TIM4;	
    HAL_GPIO_Init(GPIOB,&GPIO_Initure);
  }
  else if(htim->Instance == TIM9)
  {
    __HAL_RCC_GPIOE_CLK_ENABLE();	
    GPIO_Initure.Pin = GPIO_PIN_5;           
    GPIO_Initure.Mode=GPIO_MODE_AF_PP;  	
    GPIO_Initure.Pull=GPIO_PULLUP;         
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;     
    GPIO_Initure.Alternate= GPIO_AF3_TIM9;	
    HAL_GPIO_Init(GPIOE,&GPIO_Initure);
  }
}


void PWM_TIM2_Init(void)
{
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;
	
  __HAL_RCC_TIM2_CLK_ENABLE();

  htim2.Instance = TIM2;
  htim2.Init.Prescaler = PWM_TIM_DIV;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 65535;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	

  HAL_TIM_PWM_Init(&htim2);

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig);

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 31276;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2);
 
  HAL_TIM_MspPostInit(&htim2);
  
  HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(TIM2_IRQn);
	
}


void PWM_TIM3_Init(void)
{

  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  __HAL_RCC_TIM3_CLK_ENABLE();	
	
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = PWM_TIM_DIV;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 65535;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

  HAL_TIM_PWM_Init(&htim3);

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig);

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 31276;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_2);
 
  HAL_TIM_MspPostInit(&htim3);
  
  HAL_NVIC_SetPriority(TIM3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(TIM3_IRQn);
}


void PWM_TIM4_Init(void)
{
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  __HAL_RCC_TIM4_CLK_ENABLE();	
	
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = PWM_TIM_DIV;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 65535;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

  HAL_TIM_PWM_Init(&htim4);

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig);

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 31276;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_3);
 
  HAL_TIM_MspPostInit(&htim4);
  
  HAL_NVIC_SetPriority(TIM4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(TIM4_IRQn);
}


void PWM_TIM9_Init(void)
{
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  __HAL_RCC_TIM9_CLK_ENABLE();	

  htim9.Instance = TIM9;
  htim9.Init.Prescaler = PWM_TIM_DIV;
  htim9.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim9.Init.Period = 65535;
  htim9.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;

  HAL_TIM_PWM_Init(&htim9);

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  HAL_TIMEx_MasterConfigSynchronization(&htim9, &sMasterConfig);

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 31276;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  HAL_TIM_PWM_ConfigChannel(&htim9, &sConfigOC, TIM_CHANNEL_1);
 
  HAL_TIM_MspPostInit(&htim9);
  
  HAL_NVIC_SetPriority(TIM1_BRK_TIM9_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(TIM1_BRK_TIM9_IRQn);
}


void PWM_TIM2_Set(int arr,int pwmval)
{
		__HAL_TIM_SetAutoreload(&htim2 , arr);
		__HAL_TIM_SetCompare(&htim2 , TIM_CHANNEL_2 , pwmval);
		HAL_TIM_PWM_Start_IT(&htim2 , TIM_CHANNEL_2);
}

void PWM_TIM3_Set(int arr,int pwmval)
{
		__HAL_TIM_SetAutoreload(&htim3 , arr);
		__HAL_TIM_SetCompare(&htim3 , TIM_CHANNEL_2 , pwmval);
		HAL_TIM_PWM_Start_IT(&htim3 , TIM_CHANNEL_2);
}

void PWM_TIM4_Set(int arr,int pwmval)
{
		__HAL_TIM_SetAutoreload(&htim4 , arr);
		__HAL_TIM_SetCompare(&htim4 , TIM_CHANNEL_3 , pwmval);
		HAL_TIM_PWM_Start_IT(&htim4 , TIM_CHANNEL_3);
}

void PWM_TIM9_Set(int arr,int pwmval)
{
		__HAL_TIM_SetAutoreload(&htim9 , arr);
		__HAL_TIM_SetCompare(&htim9 , TIM_CHANNEL_1 , pwmval);
		HAL_TIM_PWM_Start_IT(&htim9 , TIM_CHANNEL_1);
}

void PWM_TIM2_Stop()
{
HAL_TIM_PWM_Stop_IT(&htim2 , TIM_CHANNEL_2);
}
void PWM_TIM3_Stop()
{
HAL_TIM_PWM_Stop_IT(&htim3 , TIM_CHANNEL_2);
}
void PWM_TIM4_Stop()
{
HAL_TIM_PWM_Stop_IT(&htim4 , TIM_CHANNEL_3);
}
void PWM_TIM9_Stop()
{
HAL_TIM_PWM_Stop_IT(&htim9 , TIM_CHANNEL_1);
}

void TIM2_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&htim2);
}

void TIM3_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&htim3);
}

void TIM4_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&htim4);
}

void TIM1_BRK_TIM9_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&htim9);
}
