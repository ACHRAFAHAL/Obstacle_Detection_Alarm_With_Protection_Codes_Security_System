/*
 * ssd1315_physical_layer_i2c.c
 *
 *  Created on: 11 oct. 2023
 *      Author: antotauv
 */

#include "main.h"
#include <stdio.h>
#include <string.h>

void    LCD_IO_WriteCommand(uint8_t Cmd);
void    LCD_IO_WriteData(uint8_t Value);
void    LCD_IO_WriteMultipleData(uint8_t *pData, uint32_t Size);
void    LCD_Delay (uint32_t delay);

extern I2C_HandleTypeDef hi2c1;

int ssd1315_i2c_adress;

void LCD_IO_Init(){
	int status;
	HAL_I2C_Init(&hi2c1);
		for (int i=0;i<255;i++){
			status=HAL_I2C_Master_Transmit(&hi2c1,i,NULL,0,10);
			if(status==HAL_OK){
				printf("Found one display at 0x%x\r\n",i);
				ssd1315_i2c_adress=i;
				return;
			}
		}
	printf("Found no LCD in I2C bus \r\n");
}
void LCD_IO_WriteCommand(uint8_t Value){
	uint8_t command_buffer[2]={0x80,0};
	command_buffer[1]=Value;
	HAL_I2C_Master_Transmit(&hi2c1,ssd1315_i2c_adress,command_buffer,2,-1);
}

void    LCD_IO_WriteData(uint8_t Value){
	uint8_t data_buffer[2]={0xc0,0};
	data_buffer[1]=Value;
	HAL_I2C_Master_Transmit(&hi2c1,ssd1315_i2c_adress,data_buffer,2,-1);
}
void    LCD_IO_WriteMultipleData(uint8_t *pData, uint32_t Size){
	uint8_t data_buffer[1025];
	data_buffer[0]=0x40;
	memcpy(data_buffer+1,pData,Size+1);
	HAL_I2C_Master_Transmit(&hi2c1,ssd1315_i2c_adress,data_buffer,Size+1,-1);

}
void    LCD_Delay (uint32_t delay){
	HAL_Delay(delay);
}

