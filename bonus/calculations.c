/*
** EPITECH PROJECT, 2017
** my_screensaver_2017
** File description:
** (calculations for different screensavers)
*/
#include "include/my.h"

void check_coordinates(int r, int i, int j, framebuffer_t *framebuffer)
{
	if ((pow((i - r), 2) + pow((j - r), 2)) <= pow(r, 2)
	&& (pow((i - r), 2) + pow((j - r), 2)) > 12000)
		my_put_pixel(framebuffer, j, i, (sfColor){0, 0, 205, 255});
}

framebuffer_t *simple_circles(void)
{
	int r = 125;
	framebuffer_t *framebuffer = framebuffer_create(r * 2, r * 2);

	for (int i = 0 ; i < r * 2 ; i++) {
		for (int j = 0 ; j < r * 2 ; j++) {
			check_coordinates(r, i, j, framebuffer);
		}
	}
	return (framebuffer);
}

void simple_circles_init(objs_t *tab, int i, framebuffer_t *framebuffer)
{
	tab[i].tx = sfTexture_create(250, 250);
	place_circles(tab, i);
	sfTexture_updateFromPixels(tab[i].tx,
		framebuffer->pixels, framebuffer->width,
		framebuffer->height, 0, 0);
	sfSprite_setTexture(tab[i].sp, tab[i].tx, sfTrue);
}

void simple_squares_init(objs_t *tab, int i, framebuffer_t *framebuffer)
{
	tab[i].tx = sfTexture_create(100, 100);
	tab[i].speed = (sfVector2f){0,
		-0.8 - ((float)rand()/(float)RAND_MAX) * 1.5};
	tab[i].position = (sfVector2f){(float)(rand()%1980), 1080};
	sfTexture_updateFromPixels(tab[i].tx,
		framebuffer->pixels, framebuffer->width,
		framebuffer->height, 0, 0);
	sfSprite_setTexture(tab[i].sp, tab[i].tx, sfTrue);
	sfSprite_setPosition(tab[i].sp, tab[i].position);
	if (i % 3 == 0 || i % 3 == 1) {
		sfSprite_setColor(tab[i].sp,
			(sfColor){150 + rand()%104, 0, 0, 255});
		}
}

framebuffer_t *simple_squares(void)
{
	framebuffer_t *framebuffer = framebuffer_create(100, 100);
	int x = 0;
	int y = 0;
	int size = 30;

	for (int i = 0 ; i < size ; i++) {
		for (int j = 0 ; j < size ; j++) {
			my_put_pixel(framebuffer, x, y, sfYellow);
			x++;
		}
		x = 100;
		y += 1;
	}
	return (framebuffer);
}
