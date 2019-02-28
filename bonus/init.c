/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** (initializing part)
*/
#include "include/my.h"

objs_t *init_my_objs(int nb, graph_fnct_t *pointer)
{
	objs_t *tab = malloc(sizeof(objs_t) * pointer[nb - 1].tab_length);

	for (int i = 0 ; i < pointer[nb - 1].tab_length ; i++) {
		tab[i].sp = sfSprite_create();
		look_for_balise(nb, i, pointer, tab);
	}
	return (tab);
}

graph_fnct_t *init_pointer(void)
{
	graph_fnct_t *pointer = malloc(sizeof(graph_fnct_t) * 2);

	pointer[0].balise = 1;
	pointer[0].tab_length = 100;
	pointer[0].s_name = "campfire.ogg";
	pointer[0].color = (sfColor){0, 0, 0, 0};
	pointer[0].init_f = &simple_squares;
	pointer[0].init_tab = &simple_squares_init;
	pointer[0].move_display = &opt_1_move_display;
	pointer[1].balise = 2;
	pointer[1].tab_length = 20;
	pointer[1].s_name = "tick.ogg";
	pointer[1].color = (sfColor){0, 0, 70, 255};
	pointer[1].init_f = &simple_circles;
	pointer[1].init_tab = &simple_circles_init;
	pointer[1].move_display = &opt_2_move_display;
	pointer[1].othtab = init_my_othtab();
	return (pointer);
}

my_w_t init_my_window(int nb)
{
	my_w_t window;

	window.pointer = init_pointer();
	window.tab = init_my_objs(nb, window.pointer);
	window.sound = sfMusic_createFromFile(window.pointer[nb - 1].s_name);
	if (nb == 1) {
		sfMusic_play(window.sound);
	}
	window.window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
		"Screen.Saver", sfFullscreen | sfClose, NULL);
	sfRenderWindow_setMouseCursorVisible(window.window, sfFalse);
	return (window);
}

ctime_t init_timer(void)
{
	ctime_t clock;

	clock.clock = sfClock_create();
	clock.seconds = 0;
	return (clock);
}

void destroy_and_free(my_w_t *window, ctime_t *clocker, int nb)
{
	sfClock_destroy(clocker->clock);
	for (int i = 0 ; i < window->pointer[nb - 1].tab_length ; i++) {
		sfSprite_destroy(window->tab[i].sp);
		sfTexture_destroy(window->tab[i].tx);
	}
	if (nb == 2) {
		for (int i = 0 ; i < 20 ; i++) {
			sfSprite_destroy(window->pointer[1].othtab[i].sp);
			sfTexture_destroy(window->pointer[1].othtab[i].tx);
		}
		free(window->pointer[1].othtab);
	}
	sfMusic_destroy(window->sound);
	free(window->tab);
	free(window->pointer);
	sfRenderWindow_destroy(window->window);
}
