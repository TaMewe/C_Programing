/*
** EPITECH PROJECT, 2018
** menu.c
** File description:
** LORIS
*/

#include "rpg.h"

int ini_menu(menu_t *menu)
{
	menu->on_menu = 0;
	if (ini_music_menu(&menu->music) == 84)
		return (84);
	menu->clock = sfClock_create();
	if (final_fantasy(&menu->ff) == 84)
		return (84);
	if (bg(&menu->bg) == 84)
		return (84);
	if (cloud(&menu->cloud) == 84)
		return (84);
	if (leaf(&menu->leaf) == 84)
		return (84);
	return (0);
}

void clock_menu(menu_t *menu)
{
	menu->time = sfClock_getElapsedTime(menu->clock);
	menu->seconds = menu->time.microseconds / 1000000.0;
	if (menu->seconds >= 0.03) {
		menu->leaf.pos = leaf_clock(menu, menu->leaf.l, menu->leaf.pos, 1.4);
		menu->leaf.pos_b = leaf_clock(menu, menu->leaf.l_b, menu->leaf.pos_b, 2);
		menu->leaf.pos_c = leaf_clock(menu, menu->leaf.l_c, menu->leaf.pos_c, 8);
		menu->leaf.pos_d = leaf_clock(menu, menu->leaf.l_d, menu->leaf.pos_d, 4);
		menu->leaf.pos_e = leaf_clock(menu, menu->leaf.l_e, menu->leaf.pos_e, 7);
		menu->leaf.pos_f = leaf_clock(menu, menu->leaf.l_f, menu->leaf.pos_f, 5);
		menu->leaf.pos_g = leaf_clock(menu, menu->leaf.l_g, menu->leaf.pos_g, 3);
		menu->cloud.pos_a = cloud_clock(500, menu->cloud.a, menu->cloud.pos_a, 1);
		menu->cloud.pos_b = cloud_clock(950, menu->cloud.b, menu->cloud.pos_b, 2);
		menu->cloud.pos_c = cloud_clock(300, menu->cloud.c, menu->cloud.pos_c, 0.8);
		menu->cloud.pos_c_b = cloud_clock(300, menu->cloud.c_b, menu->cloud.pos_c_b, 0.8);
		menu->cloud.pos_c_c = cloud_clock(300, menu->cloud.c_c, menu->cloud.pos_c_c, 0.8);
		ff_clock(&menu->ff);
		sfClock_restart(menu->clock);
	}
}

void draw_menu(menu_t *menu, sfRenderWindow *window)
{
	clock_menu(menu);
	sfRenderWindow_drawSprite(window, menu->bg.p, NULL);
	sfRenderWindow_drawSprite(window, menu->cloud.a, NULL);
	sfRenderWindow_drawSprite(window, menu->cloud.b, NULL);
	sfRenderWindow_drawSprite(window, menu->cloud.c, NULL);
	sfRenderWindow_drawSprite(window, menu->cloud.c_b, NULL);
	sfRenderWindow_drawSprite(window, menu->cloud.c_c, NULL);
	sfRenderWindow_drawSprite(window, menu->bg.p_i, NULL);
	sfRenderWindow_drawSprite(window, menu->ff.s, NULL);
	sfRenderWindow_drawSprite(window, menu->leaf.l_b, NULL);
	sfRenderWindow_drawSprite(window, menu->leaf.l_g, NULL);
	sfRenderWindow_drawSprite(window, menu->leaf.l_f, NULL);
	sfRenderWindow_drawSprite(window, menu->leaf.l_e, NULL);
	sfRenderWindow_drawSprite(window, menu->leaf.l_d, NULL);
	sfRenderWindow_drawSprite(window, menu->leaf.l, NULL);
	sfRenderWindow_drawSprite(window, menu->leaf.l_c, NULL);
	sfRenderWindow_drawSprite(window, menu->bg.h, NULL);
	sfRenderWindow_drawSprite(window, menu->ff.l, NULL);
}

void sprite_destroy_menu(menu_t *menu)
{
	sfMusic_destroy(menu->music.sonic);
	sfClock_destroy(menu->clock);
	sfSprite_destroy(menu->bg.p);
	sfTexture_destroy(menu->bg.t_p);
	sfSprite_destroy(menu->leaf.l);
	sfSprite_destroy(menu->leaf.l_b);
	sfSprite_destroy(menu->leaf.l_c);
	sfSprite_destroy(menu->leaf.l_d);
	sfSprite_destroy(menu->leaf.l_e);
	sfSprite_destroy(menu->leaf.l_f);
	sfSprite_destroy(menu->leaf.l_g);
	sfSprite_destroy(menu->bg.h);
	sfSprite_destroy(menu->bg.p_i);
	sfTexture_destroy(menu->bg.t_p_i);
	sfTexture_destroy(menu->bg.t_h);
	sfTexture_destroy(menu->leaf.t_l);
	sfTexture_destroy(menu->cloud.t_a);
	sfSprite_destroy(menu->cloud.a);
	sprite_destroy(menu);
}

void sprite_destroy(menu_t *menu)
{
	sfSprite_destroy(menu->cloud.b);
	sfSprite_destroy(menu->cloud.c);
	sfSprite_destroy(menu->cloud.c_b);
	sfSprite_destroy(menu->cloud.c_c);
	sfSprite_destroy(menu->ff.s);
	sfTexture_destroy(menu->ff.t);
	sfSprite_destroy(menu->ff.l);
	sfTexture_destroy(menu->ff.t_l);
	free(menu);
}
