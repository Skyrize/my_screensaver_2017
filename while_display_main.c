/*
** EPITECH PROJECT, 2017
** my_screensaver_2017
** File description:
** (every operations does during display or redirectors to)
*/
#include "include/my.h"

void displayer(my_w_t *window, ctime_t *clocker, int nb)
{
	analyse_events(window);
	for (int i = 0 ; i < nb ; i++) {
		if (window->pointer[i].balise == nb) {
			sfRenderWindow_clear(window->window,
				window->pointer[i].color);
			window->pointer[i].move_display(window, clocker);
		}
	}
	sfRenderWindow_display(window->window);
}

void gettime(ctime_t *clocker)
{
	clocker->timer = sfClock_getElapsedTime(clocker->clock);
	clocker->seconds = clocker->timer.microseconds / 1000000.0;
}

void separate_operations(ctime_t *clocker, my_w_t *window, int nb)
{
	gettime(clocker);
	if (fmodf(clocker->seconds, 1.0/60.0) >= 0 &&
	fmodf(clocker->seconds, 1.0/60.0) < 0.01) {
		displayer(window, clocker, nb);
	}
}
