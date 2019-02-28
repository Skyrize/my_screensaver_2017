/*
** EPITECH PROJECT, 2017
** my_screensaver_2017
** File description:
** (places circles precisely for opt2)
*/
#include "include/my.h"

void place_rounds_2(objs_t *tab, int i)
{
	if (i <= 6 && i >= 4) {
		sfSprite_setPosition(tab[i].sp,
			(sfVector2f){1253 , 825 - (i - 4) * 260});
	} else if (i <= 13 && i >= 11) {
		sfSprite_setPosition(tab[i].sp,
			(sfVector2f){687 , 825 - (i - 11) * 260});
	} else if (i <= 19 && i >= 18) {
		sfSprite_setPosition(tab[i].sp,
			(sfVector2f){120 , 825 - (i - 18) * 260});
	}
}

void place_rounds(objs_t *tab, int i)
{
	if (i <= 3 && i >= 0) {
		sfSprite_setPosition(tab[i].sp,
			(sfVector2f){1536 , 825 - i * 260});
	} else if (i <= 10 && i >= 7) {
		sfSprite_setPosition(tab[i].sp,
			(sfVector2f){970 , 825 - (i - 7) * 260});
	} else if (i <= 17 && i >= 14) {
		sfSprite_setPosition(tab[i].sp,
			(sfVector2f){403 , 825 - (i - 14) * 260});
	}
	place_rounds_2(tab, i);
}

void place_circles_2(objs_t *tab, int i)
{
	if (i <= 6 && i >= 4) {
		sfSprite_setPosition(tab[i].sp,
			(sfVector2f){1228 , 800 - (i - 4) * 260});
	} else if (i <= 13 && i >= 11) {
		sfSprite_setPosition(tab[i].sp,
			(sfVector2f){662 , 800 - (i - 11) * 260});
	} else if (i <= 19 && i >= 18) {
		sfSprite_setPosition(tab[i].sp,
			(sfVector2f){95 , 800 - (i - 18) * 260});
	}
}

void place_circles(objs_t *tab, int i)
{
	if (i <= 3 && i >= 0) {
		sfSprite_setPosition(tab[i].sp,
			(sfVector2f){1511 , 800 - i * 260});
	} else if (i <= 10 && i >= 7) {
		sfSprite_setPosition(tab[i].sp,
			(sfVector2f){945 , 800 - (i - 7) * 260});
	} else if (i <= 17 && i >= 14) {
		sfSprite_setPosition(tab[i].sp,
			(sfVector2f){378 , 800 - (i - 14) * 260});
	}
	place_circles_2(tab, i);
}
