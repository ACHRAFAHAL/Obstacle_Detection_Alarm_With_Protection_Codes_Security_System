/*
 * encoder.h
 *
 *  Created on: Nov 18, 2024
 *      Author: Ali
 */

#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "main.h"
#include "code.h"

#define ENCODER_MAX_VALUE 15
#define ENCODER_MIN_VALUE 0

typedef struct encoder{
	TIM_HandleTypeDef* htim;
	int32_t max_value;
	int32_t min_value;
}ENCODER;

void encoder_init(TIM_HandleTypeDef* htim_param, int32_t min, int32_t max);
int32_t encoder_read();
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#endif /* INC_ENCODER_H_ */
