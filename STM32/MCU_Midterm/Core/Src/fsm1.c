/*
 * fsm1.c
 *
 *  Created on: Nov 5, 2022
 *      Author: 84336
 */
#include "fsm1.h"

void fsm1_run() {
	switch (status) {
	case INC_KEEP:
		counter++;
		Display7SEG(counter);

		if (timer1_flag == 1) {
			if (IsButtonINCPressed() == 1) {
				counter++;
				if (counter > 9) {
					counter = 0;
				}
				Display7SEG(counter);
				SetTimer1(1000);
			}
		}

		if (IsButtonRESETPressed() == 1) {
			status = RESET_PRESSED;
		}

		if (IsButtonDECPressed() == 1) {
			status = DEC_PRESSED;
		}
		break;

	case DEC_KEEP:
		--counter;
		Display7SEG(counter);
		SetTimer2(1000);

		if (IsButtonRESETPressed() == 1) {
			status = RESET_PRESSED;
		}
		if (IsButtonINCPressed() == 1) {
			status = INC_PRESSED;
		}
		break;
	default:
		break;
	}
}
