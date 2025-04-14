/*
 * alarm.c
 *
 *  Created on: Mar 10, 2025
 *      Author: fifam
 */


#include "stm32l4xx_hal.h"  // Adjust include as per your MCU family

extern TIM_HandleTypeDef htim2;

// Initialize Timer2 in PWM mode
void Alarm_Init(void) {
	// Configure TIM2 instance
	htim2.Instance = TIM2;
	htim2.Init.Prescaler = 71; // 72MHz/72 = 1MHz timer clock
	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim2.Init.Period = 999;   // For 1 kHz tone (1MHz/1000 - 1)
	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_PWM_Init(&htim2);

	TIM_OC_InitTypeDef sConfigOC = {0};
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 500;     // 50% duty cycle
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1);

	// Start PWM signal on TIM2 Channel 1
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
}

// Update the PWM frequency dynamically
void Alarm_UpdateFrequency(uint32_t frequency) {
	uint32_t timer_clock = 1000000; // After prescaler, timer clock is 1MHz
	uint32_t new_arr = (timer_clock / frequency) - 1;

	// Update the auto-reload register for the new period
	__HAL_TIM_SET_AUTORELOAD(&htim2, new_arr);

	// Update the compare register for 50% duty cycle
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, new_arr / 2);

}
