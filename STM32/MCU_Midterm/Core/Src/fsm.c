/*
 * fsm.c
 *
 *  Created on: Nov 5, 2022
 *      Author: 84336
 */
#include "fsm.h"

void fsm_simple_buttons_run() {
	switch (status) {
	case INIT:
		Led7SEGOff();

		if (IsButtonRESETPressed() == 1) {
			status = RESET_PRESSED;
		}

		if (IsButtonINCPressed() == 1 || IsButtonDECPressed() == 1) {
			status = INIT;
		}
		break;

	case RESET_PRESSED:
		Display7SEG(0);
		counter = 0;

		if (IsButtonRESETPressed() == 1 || IsButtonDECPressed() == 1) {
			status = RESET_PRESSED;
		}
		if (IsButtonINCPressed() == 1) {
			status = INC_PRESSED;
		}
		break;

	case INC_PRESSED:
		Display7SEG(counter);

		if (IsButtonINCPressed() == 1) {
			counter++;
			if (counter >= 10) {
				counter = 0;
			}
			Display7SEG(counter);
			status = INC_PRESSED;
			}

		if (IsButtonRESETPressed() == 1) {
			status = RESET_PRESSED;
		}

		if (IsButtonDECPressed() == 1) {
			status = DEC_PRESSED;
		}
		break;

	case DEC_PRESSED:
		Display7SEG(counter);

		if (IsButtonDECPressed() == 1) {
			counter--;
			if (counter < 0) {
				counter = 9;
			}
			Display7SEG(counter);
				}

		if (IsButtonRESETPressed() == 1) {
			status = RESET_PRESSED;
		}
		if (IsButtonINCPressed() == 1) {
			status = INC_PRESSED;
		}
	default:
		break;
	}
}

