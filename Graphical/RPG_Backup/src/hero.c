/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** C GRAPH PROG
*/

#include "rpg.h"

hero_t *ini_hero(char *filepath)
{
	hero_t *hero = malloc(sizeof(hero_t));
	
	hero->sprite = sfSprite_create();
	hero->texture = sfTexture_createFromFile(filepath, NULL);
	hero->position = set_vector(960, 576);
	hero->scale = set_vector(2.13, 2.13);
	hero->rect = set_rect(225, 0, 32, 32);
	hero->hp = malloc(sizeof(int) * 2);
	hero->mp = malloc(sizeof(int) * 2);
	hero->xp = malloc(sizeof(int) * 2);
	hero->lvl = 1;
	hero->stat = warrior_stat();
	hero->hp[0] = 100;
	hero->hp[1] = 100;
	hero->mp[0] = 50;
	hero->mp[1] = 50;
	hero->xp[0] = 0;
	hero->xp[1] = 30;
	sfSprite_setTexture(hero->sprite, hero->texture, sfTrue);
	sfSprite_setTextureRect(hero->sprite, hero->rect);
	sfSprite_setPosition(hero->sprite, hero->position);
	sfSprite_setScale(hero->sprite, hero->scale);
	return (hero);
}

void set_character(hero_t *hero, map_t *map)
{
	sfVector2f vec = sfSprite_getPosition(hero->sprite);
	int x = 0;
	int y = 0;

	if (map) {
	}
	x = vec.x / 64;
	y = vec.y / 64;
	map->colision[y][x] = 'P';
}
