/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: 84336
 */
#include "button.h"

int button1_flag = 0, button2_flag = 0, button3_flag = 0;
int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int KeyReg4 = NORMAL_STATE;
int KeyReg5 = NORMAL_STATE;
int KeyReg6 = NORMAL_STATE;
int KeyReg7 = NORMAL_STATE;

int KeyReg8 = NORMAL_STATE;
int KeyReg9 = NORMAL_STATE;
int KeyReg10 = NORMAL_STATE;
int KeyReg11 = NORMAL_STATE;

int TimerForKeyPress1 = 200;
int TimerForKeyPress2 = 200;
int TimerForKeyPress3 = 200;

void SubKeyProcess1() {
	button1_flag = 1;
}

void SubKeyProcess2() {
	button2_flag = 1;
}

void SubKeyProcess3() {
	button3_flag = 1;
}

int IsButtonRESETPressed () {
	if (button1_flag == 1) {
		button1_flag = 0;
		return 1;
	}
	return 0;
}

int IsButtonINCPressed () {
	if (button2_flag == 1) {
		button2_flag = 0;
		return 1;
	}
	return 0;
}

int IsButtonDECPressed () {
	if (button3_flag == 1) {
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void GetKeyInput1() {
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(BUTTON_RESET_GPIO_Port, BUTTON_RESET_Pin);
	if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)) {
		if (KeyReg3 != KeyReg2) {
			KeyReg3 = KeyReg2;
			if (KeyReg2 == PRESSED_STATE) {
				SubKeyProcess1();
				TimerForKeyPress1 = 200;
			}
		}
		else {
			TimerForKeyPress1--;
			if (TimerForKeyPress1 == 0) {
				KeyReg3 = NORMAL_STATE;
			}
		}
	}
}

void GetKeyInput2() {
	KeyReg4 = KeyReg5;
	KeyReg5 = KeyReg6;
	KeyReg6 = HAL_GPIO_ReadPin(BUTTON_INC_GPIO_Port, BUTTON_INC_Pin);
	if ((KeyReg4 == KeyReg5) && (KeyReg5 == KeyReg6)) {
		if (KeyReg7 != KeyReg6) {
			KeyReg7 = KeyReg6;
			if (KeyReg6 == PRESSED_STATE) {
				SubKeyProcess2();
				TimerForKeyPress2 = 200;
			}
		}
		else {
			TimerForKeyPress2--;
			if (TimerForKeyPress2 == 0) {
				KeyReg7 = NORMAL_STATE;
			}
		}
	}
}

void GetKeyInput3() {
	KeyReg8 = KeyReg9;
	KeyReg9 = KeyReg10;
	KeyReg10 = HAL_GPIO_ReadPin(BUTTON_DEC_GPIO_Port, BUTTON_DEC_Pin);
	if ((KeyReg8 == KeyReg9) && (KeyReg9 == KeyReg10)) {
		if (KeyReg11 != KeyReg10) {
			KeyReg11 = KeyReg10;
			if (KeyReg10 == PRESSED_STATE) {
				SubKeyProcess3();
				TimerForKeyPress3 = 200;
			}
		}
		else {
			TimerForKeyPress3--;
			if (TimerForKeyPress3 == 0) {
				KeyReg11 = NORMAL_STATE;
			}
		}
	}
}
