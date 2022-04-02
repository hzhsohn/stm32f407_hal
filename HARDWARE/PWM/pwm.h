#ifndef _PWM_H
#define _PWM_H
#include "stm32f4xx_hal.h"

/*
使用

*/

//分频系数,192000000是主频
#define PWM_TIM_CLOCK      (4000000)
#define PWM_TIM_DIV     	 (192000000/PWM_TIM_CLOCK)


void PWM_TIM2_Init(void);
void PWM_TIM3_Init(void);
void PWM_TIM4_Init(void);
void PWM_TIM9_Init(void);

void PWM_TIM2_Set(int period,int pwmval);
void PWM_TIM3_Set(int period,int pwmval);
void PWM_TIM4_Set(int period,int pwmval);
void PWM_TIM9_Set(int period,int pwmval);

void PWM_TIM2_Stop(void);
void PWM_TIM3_Stop(void);
void PWM_TIM4_Stop(void);
void PWM_TIM9_Stop(void);
	
#endif

