/*
** EPITECH PROJECT, 2017
** my_screensaver_2017
** File description:
** (init part 2)
*/
#include "include/my.h"

void check_coordinates_rounds(int r, int i, int j, framebuffer_t *framebuffer)
{
	if ((pow((i - r), 2) + pow((j - r), 2)) <= pow(r, 2))
		my_put_pixel(framebuffer, j, i, (sfColor){0, 206, 209, 255});
}

framebuffer_t *simple_rounds(void)
{
	int r = 100;
	framebuffer_t *framebuffer = framebuffer_create(r * 2, r * 2);

	for (int i = 0 ; i < r * 2 ; i++) {
		for (int j = 0 ; j < r * 2 ; j++) {
			check_coordinates_rounds(r, i, j, framebuffer);
		}
	}
	return (framebuffer);
}

void simple_rounds_init(objs_t *tab, int i, framebuffer_t *framebuffer)
{
	tab[i].tx = sfTexture_create(200, 200);
	place_rounds(tab, i);
	sfTexture_updateFromPixels(tab[i].tx,
		framebuffer->pixels, framebuffer->width,
		framebuffer->height, 0, 0);
	sfSprite_setTexture(tab[i].sp, tab[i].tx, sfTrue);
	sfSprite_setColor(tab[i].sp, (sfColor){0, 206, 209, 0});
}

objs_t *init_my_othtab(void)
{
	objs_t *tab = malloc(sizeof(objs_t) * 20);
	framebuffer_t *framebuffer;

	if (tab == NULL)
		exit (84);
	for (int i = 0 ; i < 20 ; i++) {
		tab[i].sp = sfSprite_create();
		tab[i].state = 0;
		framebuffer = simple_rounds();
		simple_rounds_init(tab, i, framebuffer);
	}
	free(framebuffer);
	return (tab);
}

void look_for_balise(int nb, int i,
	graph_fnct_t *pointer, objs_t *tab)
{
	framebuffer_t *framebuffer;

	for (int j = 0 ; j < nb ; j++) {
		if (pointer[j].balise == nb) {
			framebuffer = pointer[j].init_f();
			pointer[j].init_tab(tab, i, framebuffer);
		}
	}
	free(framebuffer);
}
