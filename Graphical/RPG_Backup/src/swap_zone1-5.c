/*
** EPITECH PROJECT, 2018
** swap_zone
** File description:
** swap_zone
*/

#include "rpg.h"

void swap_1_to_2(map_t *map, hero_t *hero, const char **zone1, const char **zone2)
{
	sfVector2f vec = sfSprite_getPosition(hero->sprite);
	sfVector2f pos_s = {960, 896};

	if (my_strcmp(map->map_1d, (char *)zone1[0]) && vec.x == 1280 && vec.y == 384) {
		map->map_1d = my_strcpy((char *)zone2[0]);
		map->map_2d = my_strcpy((char *)zone2[1]);
		map->map_coli = my_strcpy((char *)zone2[2]);
		map_creation(map);
		sfSprite_setPosition(hero->sprite, pos_s);
		set_character(hero, map);
	}
}

void swap_2_to_1(map_t *map, hero_t *hero, const char **zone1, const char **zone2)
{
	sfVector2f vec = sfSprite_getPosition(hero->sprite);
	sfVector2f pos_s = {1216, 384};

	if (my_strcmp(map->map_1d, (char *)zone2[0]) && vec.x == 896 && vec.y == 896) {
		map->map_1d = my_strcpy((char *)zone1[0]);
		map->map_2d = my_strcpy((char *)zone1[1]);
		map->map_coli = my_strcpy((char *)zone1[2]);
		map_creation(map);
		sfSprite_setPosition(hero->sprite, pos_s);
		set_character(hero, map);
	}
}

void swap_1_to_tente(map_t *map, hero_t *hero, const char **zone1, const char **zone2)
{
	sfVector2f vec = sfSprite_getPosition(hero->sprite);
	sfVector2f pos_s = {896, 896};

	if (my_strcmp(map->map_1d, (char *)zone1[0]) && vec.y == 64 && vec.x == 896) {
		map->map_1d = my_strcpy((char *)zone2[0]);
		map->map_2d = my_strcpy((char *)zone2[1]);
		map->map_coli = my_strcpy((char *)zone2[2]);
		map_creation(map);
		sfSprite_setPosition(hero->sprite, pos_s);
		set_character(hero, map);
	}
}

void swap_tente_to_1(map_t *map, hero_t *hero, const char **zone1, const char **zone2)
{
	sfVector2f vec = sfSprite_getPosition(hero->sprite);
	sfVector2f pos_s = {768, 640};

	if (my_strcmp(map->map_1d, (char *)zone2[0]) && vec.y == 768 && vec.x == 960) {
		map->map_1d = my_strcpy((char *)zone1[0]);
		map->map_2d = my_strcpy((char *)zone1[1]);
		map->map_coli = my_strcpy((char *)zone1[2]);
		map_creation(map);
		sfSprite_setPosition(hero->sprite, pos_s);
		set_character(hero, map);
	}
}
