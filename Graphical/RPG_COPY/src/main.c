/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "../include/my.h"
#include "../include/struct.h"

map_t *ini_map()
{
	map_t *map = malloc(sizeof(map_t));

	map->map_1d = NULL;
	map->map_2d = NULL;
	map->colision = NULL;
	map->map_c = NULL;
	map->map_d = NULL;
	map->blocks_1d = NULL;
	map->blocks_2d = NULL;
	map->text_tab = NULL;
	map->bg = malloc(sizeof(sfSprite *) * 3);
	for (int i = 0; i != 3; i++)
		map->bg[i] = sfSprite_create();
	map->text = sfTexture_createFromFile("Sprite/Parallax/sky.png", NULL);
	sfSprite_setTexture(map->bg[0], map->text, sfTrue);
	map->text = sfTexture_createFromFile("Sprite/Parallax/clouds_1.png", NULL);
	sfSprite_setTexture(map->bg[1], map->text, sfTrue);
	map->text = sfTexture_createFromFile("Sprite/Parallax/clouds_2.png", NULL);
	sfSprite_setTexture(map->bg[2], map->text, sfTrue);
	map->clock = sfClock_create();
	map->rect.top = 0;
	map->rect.left = 0;
	map->rect.width = 64;
	map->rect.height = 64;
	return (map);
}

int main(void)
{
	window_is_open();
	return (0);
}
