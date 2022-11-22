/*
 * toggleLED.c
 *
 *  Created on: Nov 8, 2022
 *      Author: ACER
 */
#include "toggleLED.h"
#include "main.h"

int flag = 0;

void led1test(){
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	flag = 1;
}

void led2test(){
	HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
	flag = 2;
}

void led3test(){
	HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
	flag = 3;
}

void led4test(){
	HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin);
	flag = 4;
}

void led5test(){
	HAL_GPIO_TogglePin(LED_WHITE_GPIO_Port, LED_WHITE_Pin);
	flag = 5;
}
