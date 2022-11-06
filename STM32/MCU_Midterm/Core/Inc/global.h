/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: 84336
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "display7seg.h"
#include "fsm.h"

#define INIT				1
#define RESET_PRESSED 		2
#define INC_PRESSED			3
#define DEC_PRESSED			4

#define INC_KEEP 			13
#define DEC_KEEP 			14

#define NO_BUTTON_PRESSED 	5

extern int status, counter;

#endif /* INC_GLOBAL_H_ */
