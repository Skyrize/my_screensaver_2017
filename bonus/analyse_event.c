/*
** EPITECH PROJECT, 2017
** my_screensaver_2017
** File description:
** (analyse_events)
*/
#include "include/my.h"

void analyse_events_opt1(my_w_t *window, int j)
{
	if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
		sfSprite_move(window->tab[j].sp, (sfVector2f){2, 0});
	}
	if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
		sfSprite_move(window->tab[j].sp, (sfVector2f){-2, 0});
	}
}

void analyse_events(my_w_t *window)
{
	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
		if (window->event.type == sfEvtClosed
			|| sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
			sfRenderWindow_close(window->window);
	}
}
