/*
** EPITECH PROJECT, 2017
** my_screensaver_2017
** File description:
** (main.c my_screensaver)
*/
#include <stdlib.h>
#include <math.h>
#include "include/my.h"

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y,
		  sfColor color)
{
	int i = (y * framebuffer->width + x) * 4;

	framebuffer->pixels[i] = color.r;
	framebuffer->pixels[i + 1] = color.g;
	framebuffer->pixels[i + 2] = color.b;
	framebuffer->pixels[i + 3] = color.a;
}

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
	framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));
	unsigned int i = 0;

	framebuffer->width = width;
	framebuffer->height = height;
	framebuffer->pixels = malloc(width * height * 32 / 4);
	while (i < (width * height * 32 / 4)) {
		framebuffer->pixels[i] = 0;
		i++;
	}
	return (framebuffer);
}

void create_Window(int nb)
{
	my_w_t window = init_my_window(nb);
	ctime_t clocker = init_timer();

	while (sfRenderWindow_isOpen(window.window)) {
		separate_operations(&clocker, &window, nb);
	}
	destroy_and_free(&window, &clocker, nb);
}

int check_arg(char *str)
{
	if (my_strlen(str) == 2 && str[0] == '-' && str[1] == 'd') {
		my_printf("1: Yellow and red squares simulating a firecamp");
		my_printf(" screen-saver, controlable with left and right ar");
		my_printf("row keys.\n2: Blue binary clock; ");
		my_printf("press space to add time.\n");
		return (0);
	} else if (my_strlen(str) == 2 && str[0] == '-' && str[1] == 'h') {
		my_printf("animation rendering in a CSFML window.\n\n");
		my_printf("USAGE\n ./my_screensaver\t[OPTIONS] animation_id\n");
		my_printf(" animation_id\tID of the animation to process (bet");
		my_printf("ween 1 and 2).\n\nOPTIONS\n -d\t\tprintf the des");
		my_printf("cription of all the animations and quit.\n -h\t\t");
		my_printf("printf the usage and quit.\n\nUSER INTERACTIONS\n");
		my_printf(" FOR 1ST ANIMATION:\tleft and right arrows to con");
		my_printf("trol the fire.\n FOR 2ND:\tspace to add time.\n");
		return (0);
	}
	my_printf("./my_screensaver:  bad arguments:  0 given but 1");
	my_printf(" is required\nretry with -h\n");
	return (84);
}

int main(int ac, char **av)
{
	srand(time(NULL));
	if (ac != 2) {
		my_printf("./my_screensaver:  bad arguments:  0 given but 1");
		my_printf(" is required\nretry with -h\n");
		return (84);
	} else {
		if ((av[1][0] == '1' || av [1][0] == '2')
		&& my_strlen(av[1]) == 1) {
			create_Window(my_getnbr(av[1]));
			return (0);
		}
		return (check_arg(av[1]));
	}
	return (0);
}
