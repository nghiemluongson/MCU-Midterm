/*
 * software_timer.c
 *
 *  Created on: Nov 4, 2022
 *      Author: 84336
 */
#include "software_timer.h"

int timer1_counter = 0, timer1_flag = 0;
int timer2_counter = 0, timer2_flag = 0;
int timer3_counter = 0, timer3_flag = 0;
int timer4_counter = 0, timer4_flag = 0;

void SetTimer1 (int duration) {
	timer1_counter = duration / TICK;
	timer1_flag = 0;
}

void SetTimer2 (int duration) {
	timer2_counter = duration / TICK;
	timer2_flag = 0;
}

void SetTimer3 (int duration) {
	timer3_counter = duration / TICK;
	timer3_flag = 0;
}

void SetTimer4 (int duration) {
	timer4_counter = duration / TICK;
	timer4_flag = 0;
}

void TimerRun () {
	if (timer1_counter > 0) {
		timer1_counter--;
		if (timer1_counter <= 0) {
			timer1_flag = 1;
		}
	}

	if (timer2_counter > 0) {
		timer2_counter--;
		if (timer2_counter <= 0) {
			timer2_flag = 1;
		}
	}

	if (timer3_counter > 0) {
		timer3_counter--;
		if (timer3_counter <= 0) {
			timer3_flag = 1;
		}
	}

	if (timer4_counter > 0) {
			timer4_counter--;
			if (timer4_counter <= 0) {
				timer4_flag = 1;
			}
		}
}


