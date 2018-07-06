/*
** EPITECH PROJECT, 2018
** window
** File description:
** window
*/

#include "../include/my.h"
#include "../include/struct.h"

const char *map1 = "map/first_zone_1d";
const char *map1_1 = "map/first_zone_2d";
const char *map2 = "map/second_zone_1d";
const char *map2_1 = "map/second_zone_2d";

window_t create_window(int width, int height, int bitsPerPixel)
{
	window_t window;

	window.mode.width = width;
	window.mode.height = height;
	window.mode.bitsPerPixel = bitsPerPixel;
	window.window = sfRenderWindow_create(window.mode, "My RPG", sfFullscreen, NULL);
	sfRenderWindow_setFramerateLimit(window.window, 60);
	return (window);
}

void key_pressed(sfEvent event, window_t window, map_t *map)
{
	if (event.type == sfEvtKeyPressed) {
		if (event.key.code == sfKeyEscape)
			sfRenderWindow_close(window.window);
	}
	if (event.type == sfEvtKeyPressed) {
		if (event.key.code == sfKeyA && my_strcmp(map->map_1d, (char *)map2) == 0) {
			map->map_1d = my_strcpy((char *)map2);
			map->map_2d = my_strcpy((char *)map2_1);
			map_creation(map);
		}
		if (event.key.code == sfKeyZ && my_strcmp(map->map_1d, (char *)map1) == 0) {
			map->map_1d = my_strcpy((char *)map1);
			map->map_2d = my_strcpy((char *)map1_1);
			map_creation(map);
		}
	}
}

void event_rpg(window_t window, map_t *map)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window.window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window.window);
		key_pressed(event, window, map);
	}
}

void draw_map(map_t *map, sfRenderWindow *window)
{
	sfVector2f vit_1 = {- 0.7, 0};
	sfVector2f vit_2 = {-0.5, 0};
	sfVector2f ini = {0, 0};
	sfTime time;

	if (my_strcmp(map->map_1d, (char *)map2)) {
		time = sfClock_getElapsedTime(map->clock);
		map->seconds = (time.microseconds / 1000000.0);
		sfSprite_move(map->bg[1], vit_1);
		sfSprite_move(map->bg[2], vit_2);
		if (sfSprite_getPosition(map->bg[1]).x < -1920)
			sfSprite_setPosition(map->bg[1], ini);
		if (sfSprite_getPosition(map->bg[2]).x < -1920)
			sfSprite_setPosition(map->bg[2], ini);
		for (int i = 0; i != 3; i++)
			sfRenderWindow_drawSprite(window, map->bg[i], NULL);
		if (map->seconds > 0.2) {
			map->rect.left += 64;
			sfClock_restart(map->clock);
		}
		if (map->rect.left >= 192)
			map->rect.left = 0;
	}
	for (int i = 0; map->map_c[i] != NULL; i++) {
		for (int j = 0; j != map->lar; j++) {
			sfRenderWindow_drawSprite(window, map->blocks_1d[i][j], NULL);
			sfRenderWindow_drawSprite(window, map->blocks_2d[i][j], NULL);
		}
	}
}

int window_is_open()
{
	window_t window = create_window(1920, 1080, 32);
	map_t *map = ini_map();

	map->map_1d = my_strcpy((char *)map1);
	map->map_2d = my_strcpy((char *)map1_1);
	map_creation(map);
	while (sfRenderWindow_isOpen(window.window)) {
		draw_map(map, window.window);
		sfRenderWindow_display(window.window);
		event_rpg(window, map);
		sfRenderWindow_clear(window.window, sfBlack);
	}
}
