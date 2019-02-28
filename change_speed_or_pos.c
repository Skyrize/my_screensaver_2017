/*
** EPITECH PROJECT, 2017
** my_screensaver_2017
** File description:
** (speed or/and pos changer, depending on opt)
*/
#include "include/my.h"

void opt_2_move_display(my_w_t *window, ctime_t *clocker)
{
	for (int j = 0 ; j < 20 ; j++) {
		sfRenderWindow_drawSprite(window->window,
			window->tab[j].sp, NULL);
		sfRenderWindow_drawSprite(window->window,
			window->pointer[1].othtab[j].sp, NULL);
	}
	if (clocker->seconds >= 1.0 || sfKeyboard_isKeyPressed(sfKeySpace)) {
		seconds_gesture(window);
		sfClock_restart(clocker->clock);
	}
}

void replace_if_high(my_w_t *window, sfVector2f *pos, int j)
{
	if (pos->y < -100) {
		window->tab[j].position.x = (float)(rand()%1980);
		window->tab[j].speed.y = -0.8 -
		((float)rand()/(float)RAND_MAX) * 1.5;
		sfSprite_setPosition(window->tab[j].sp,
			window->tab[j].position);
	}
}

void opt_1_move_display(my_w_t *window, ctime_t *clocker)
{
	static int i = 0;
	sfVector2f pos = {0, 0};

	if (clocker->seconds >= 0.2) {
		i++;
		sfClock_restart(clocker->clock);
	}
	for (int j = 0 ; j < 100 && j < i ; j++) {
		analyse_events_opt1(window, j);
		sfSprite_move(window->tab[j].sp, window->tab[j].speed);
		pos = sfSprite_getPosition(window->tab[j].sp);
		replace_if_high(window, &pos, j);
		sfRenderWindow_drawSprite(window->window,
			window->tab[j].sp, NULL);
	}
}
