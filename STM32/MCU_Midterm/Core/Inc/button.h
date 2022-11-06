/*
 * button.h
 *
 *  Created on: Nov 4, 2022
 *      Author: 84336
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE 	GPIO_PIN_SET
#define PRESSED_STATE 	GPIO_PIN_RESET

int IsButtonRESETPressed ();
int IsButtonINCPressed ();
int IsButtonDECPressed ();
void GetKeyInput ();

#endif /* INC_BUTTON_H_ */
