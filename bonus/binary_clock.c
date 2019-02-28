/*
** EPITECH PROJECT, 2017
** my_screensaver_2017
** File description:
** (binary_clock gesture)
*/
#include "include/my.h"

void check_full_time(my_w_t *window, int i, int k)
{
	for (; window->pointer[1].othtab[i].state == 1 ; i++) {
		sfSprite_setColor(window->pointer[1].othtab[i].sp,
			(sfColor){0, 206, 209, 0});
		window->pointer[1].othtab[i].state = 0;
	}
	sfSprite_setColor(window->pointer[1].othtab[i].sp,
		(sfColor){0, 206, 209, 255});
	window->pointer[1].othtab[i].state = 1;
	for (int j = k ; j > 0 ; j--) {
		sfSprite_setColor(window->pointer[1].othtab[j].sp,
			(sfColor){0, 206, 209, 0});
		window->pointer[1].othtab[j].state = 0;
	}
}

void hours_gesture(my_w_t *window)
{
	if (window->pointer[1].othtab[15].state == 1
		&& window->pointer[1].othtab[17].state == 1)
		check_full_time(window, 18, 17);
	if (window->pointer[1].othtab[18].state == 1
		&& window->pointer[1].othtab[19].state == 1)
		check_full_time(window, 0, 19);
}

void minutes_gesture(my_w_t *window)
{
	if (window->pointer[1].othtab[8].state == 1
		&& window->pointer[1].othtab[10].state == 1)
		check_full_time(window, 11, 10);
	if (window->pointer[1].othtab[13].state == 1
		&& window->pointer[1].othtab[12].state == 1)
		check_full_time(window, 14, 13);
	hours_gesture(window);
}

void seconds_gesture(my_w_t *window)
{
	check_full_time(window, 0, 0);
	if (window->pointer[1].othtab[1].state == 1
		&& window->pointer[1].othtab[3].state == 1)
			check_full_time(window, 4, 3);
	if (window->pointer[1].othtab[5].state == 1
		&& window->pointer[1].othtab[6].state == 1)
		check_full_time(window, 7, 6);
	minutes_gesture(window);
}
