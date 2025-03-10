/*
 * utils.c
 *
 *  Created on: Nov 18, 2024
 *      Author: Ali
 */

#include <stm32l4xx_hal.h>
#include "utils.h"
#include "encoder.h"
#include "main.h"
#include "tim.h"
#include "code.h"

static int i = 0;
static int x = 0;

static char* caracteres[CHARACTER_LIST_LENGTH] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

int is_equal(char** correct_code, char** test_code){
	return (correct_code[0]==test_code[0]) && (correct_code[1]==test_code[1]) && (correct_code[2]==test_code[2]);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == GPIO_PIN_15){
		printf("\r\nButton pressed !\r\n");
		enteredCode[i] = caracteres[encoder_read()];
		i++;
	}
}


void etape0(void){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
	ssd1315_Clear(SSD1315_COLOR_BLACK);

	char buffer[16] = {0};
	snprintf(buffer, 16, "ALARM OFF");
	ssd1315_Draw_String(0, 0, buffer, &Font_11x18); //Tailles disponibles : 7x10; 11x18; 16x26
	ssd1315_Refresh();
}

void etape1(void){
	i=0;
	enteredCode[0] = "X";
	enteredCode[1] = "X";
	enteredCode[2] = "X";
	while(i!=3){
		char CNT1[16] = {0};
		strcpy(CNT1, "CODE 1 : ");
		strcat(CNT1, caracteres[encoder_read()]);

		ssd1315_Clear(SSD1315_COLOR_BLACK);

		char buffer_cnt1[16] = {0};
		char buffer_caractere1_c1[16] = {0};
		char buffer_caractere2_c1[16] = {0};
		char buffer_caractere3_c1[16] = {0};
		snprintf(buffer_cnt1, 16, CNT1);
		snprintf(buffer_caractere1_c1, 16, enteredCode[0]);
		snprintf(buffer_caractere2_c1, 16, enteredCode[1]);
		snprintf(buffer_caractere3_c1, 16, enteredCode[2]);
		ssd1315_Draw_String(0, 0, buffer_cnt1, &Font_11x18);
		ssd1315_Draw_String(0, 20, buffer_caractere1_c1, &Font_11x18);
		ssd1315_Draw_String(10, 20, buffer_caractere2_c1, &Font_11x18);
		ssd1315_Draw_String(20, 20, buffer_caractere3_c1, &Font_11x18);
		ssd1315_Refresh();
	}
}

void etape2(void){
	i=0;
	enteredCode[0] = "X";
	enteredCode[1] = "X";
	enteredCode[2] = "X";
	while(i!=3){
		char CNT1[16] = {0};
		strcpy(CNT1, "CODE 2 : ");
		strcat(CNT1, caracteres[encoder_read()]);

		ssd1315_Clear(SSD1315_COLOR_BLACK);

		char buffer_cnt1[16] = {0};
		char buffer_caractere1_c1[16] = {0};
		char buffer_caractere2_c1[16] = {0};
		char buffer_caractere3_c1[16] = {0};
		snprintf(buffer_cnt1, 16, CNT1);
		snprintf(buffer_caractere1_c1, 16, enteredCode[0]);
		snprintf(buffer_caractere2_c1, 16, enteredCode[1]);
		snprintf(buffer_caractere3_c1, 16, enteredCode[2]);
		ssd1315_Draw_String(0, 0, buffer_cnt1, &Font_11x18);
		ssd1315_Draw_String(0, 20, buffer_caractere1_c1, &Font_11x18);
		ssd1315_Draw_String(10, 20, buffer_caractere2_c1, &Font_11x18);
		ssd1315_Draw_String(20, 20, buffer_caractere3_c1, &Font_11x18);
		ssd1315_Refresh();
	}
}

void etape3(void){
	i=0;
	enteredCode[0] = "X";
	enteredCode[1] = "X";
	enteredCode[2] = "X";
	while(i!=3){
		char CNT1[16] = {0};
		strcpy(CNT1, "CODE 3 : ");
		strcat(CNT1, caracteres[encoder_read()]);

		ssd1315_Clear(SSD1315_COLOR_BLACK);

		char buffer_cnt1[16] = {0};
		char buffer_caractere1_c1[16] = {0};
		char buffer_caractere2_c1[16] = {0};
		char buffer_caractere3_c1[16] = {0};
		snprintf(buffer_cnt1, 16, CNT1);
		snprintf(buffer_caractere1_c1, 16, enteredCode[0]);
		snprintf(buffer_caractere2_c1, 16, enteredCode[1]);
		snprintf(buffer_caractere3_c1, 16, enteredCode[2]);
		ssd1315_Draw_String(0, 0, buffer_cnt1, &Font_11x18);
		ssd1315_Draw_String(0, 20, buffer_caractere1_c1, &Font_11x18);
		ssd1315_Draw_String(10, 20, buffer_caractere2_c1, &Font_11x18);
		ssd1315_Draw_String(20, 20, buffer_caractere3_c1, &Font_11x18);
		ssd1315_Refresh();
	}
}

void etapeD(void){
	i=0;
	enteredCode[0] = "X";
	enteredCode[1] = "X";
	enteredCode[2] = "X";
	while(i!=3){
		char CNT1[16] = {0};
		strcpy(CNT1, "CODE D : ");
		strcat(CNT1, caracteres[encoder_read()]);

		ssd1315_Clear(SSD1315_COLOR_BLACK);

		char buffer_cnt1[16] = {0};
		char buffer_caractere1_c1[16] = {0};
		char buffer_caractere2_c1[16] = {0};
		char buffer_caractere3_c1[16] = {0};
		snprintf(buffer_cnt1, 16, CNT1);
		snprintf(buffer_caractere1_c1, 16, enteredCode[0]);
		snprintf(buffer_caractere2_c1, 16, enteredCode[1]);
		snprintf(buffer_caractere3_c1, 16, enteredCode[2]);
		ssd1315_Draw_String(0, 0, buffer_cnt1, &Font_11x18);
		ssd1315_Draw_String(0, 20, buffer_caractere1_c1, &Font_11x18);
		ssd1315_Draw_String(10, 20, buffer_caractere2_c1, &Font_11x18);
		ssd1315_Draw_String(20, 20, buffer_caractere3_c1, &Font_11x18);
		ssd1315_Refresh();
	}
}

void etapeE(void){
	i=0;
	enteredCode[0] = "X";
	enteredCode[1] = "X";
	enteredCode[2] = "X";
	while(i!=3){
		char CNT1[16] = {0};
		strcpy(CNT1, "CODE E : ");
		strcat(CNT1, caracteres[encoder_read()]);

		ssd1315_Clear(SSD1315_COLOR_BLACK);

		char buffer_cnt1[16] = {0};
		char buffer_caractere1_c1[16] = {0};
		char buffer_caractere2_c1[16] = {0};
		char buffer_caractere3_c1[16] = {0};
		snprintf(buffer_cnt1, 16, CNT1);
		snprintf(buffer_caractere1_c1, 16, enteredCode[0]);
		snprintf(buffer_caractere2_c1, 16, enteredCode[1]);
		snprintf(buffer_caractere3_c1, 16, enteredCode[2]);
		ssd1315_Draw_String(0, 0, buffer_cnt1, &Font_11x18);
		ssd1315_Draw_String(0, 20, buffer_caractere1_c1, &Font_11x18);
		ssd1315_Draw_String(10, 20, buffer_caractere2_c1, &Font_11x18);
		ssd1315_Draw_String(20, 20, buffer_caractere3_c1, &Font_11x18);
		ssd1315_Refresh();
	}
}

void setup(){
	printf("\r\n\r\n=====================================================================\r\n");
	encoder_init(&htim2, ENCODER_MIN_VALUE, ENCODER_MAX_VALUE);
}

void loop(){
	if (x!=1){
	etape0();
	}
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5)==0 || x==1){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
		etape1();
		while((i==3)){
			if(is_equal(code1, enteredCode)){
				etape2();
				if(is_equal(code2, enteredCode)){
					etape3();
					if(is_equal(code3, enteredCode)){
						x=0;
						break;
					}
				}
			}
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
			etapeD();
			if(is_equal(codeD, enteredCode)){
				x = 1;
				break;
			}else{
				while(1){
					HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
					etapeE();
					if(is_equal(codeE, enteredCode)){
						x=0;
						break;
					}
				}
				i=0;
			}
		}
	}
}
