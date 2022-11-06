/*
 * fsm2.c
 *
 *  Created on: Nov 5, 2022
 *      Author: 84336
 */
#include "fsm2.h"

void fsm2_run() {
	switch (status) {
	case NO_BUTTON_PRESSED:
		if (timer1_flag == 1) {
			counter--;
			if (counter <= 0) {
				counter = 0;
			}
			Display7SEG(counter);
		}
		break;
	default:
		break;
	}
}

