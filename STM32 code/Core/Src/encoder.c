/*
 * encoder.c
 *
 *  Created on: Nov 18, 2024
 *      Author: Ali
 */

#include "encoder.h"
#include "utils.h"

static ENCODER encoder;

void encoder_init(TIM_HandleTypeDef* htim_param, int32_t min, int32_t max){
	encoder.htim = htim_param;
	encoder.max_value = max;
	encoder.min_value = min;

	HAL_TIM_Encoder_Start(encoder.htim, TIM_CHANNEL_ALL);
	encoder.htim->Instance->CNT=0;
}

int32_t encoder_read(){
	int32_t cnt = encoder.htim->Instance->CNT;
	if(cnt >= encoder.max_value){
		//encoder.htim->Instance->CNT = encoder.max_value;
		return encoder.max_value;
	}
	if(cnt <= encoder.min_value){
		//encoder.htim->Instance->CNT = encoder.min_value;
		return encoder.min_value;
	}
	return cnt;
}


