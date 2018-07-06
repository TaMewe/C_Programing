/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** C GRAPH PROG
*/

#include "rpg.h"

static int x = 0;
static int y = 0;
static const int speed = 8;

void key_left(hero_t *hero, map_t *map)
{
	sfVector2f move = { -speed, 0 };

	if (x == 0 && map->colision[map->y][map->x - 1] == '0') {
		if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
			sfSprite_move(hero->sprite, move);
			x = x - speed;
			map->colision[map->y][map->x] = '0';
			map->colision[map->y][map->x - 1] = 'P';
		}
	}

	else if (x < 0 && x != -64) {
		sfSprite_move(hero->sprite, move);
		x = x - speed;
	}

	else if (x == -64) {
		x = 0;
	}

}

void key_right(hero_t *hero, map_t *map)
{
	sfVector2f move = { speed, 0 };

	if (x == 0 && map->colision[map->y][map->x + 1] == '0') {
		if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
			sfSprite_move(hero->sprite, move);
			x = x + speed;
			map->colision[map->y][map->x] = '0';
			map->colision[map->y][map->x + 1] = 'P';
		}
	}

	else if (x > 0 && x != 64) {
		sfSprite_move(hero->sprite, move);
		x = x + speed;
	}

	else if (x == 64) {
		x = 0;
	}
}

void key_up(hero_t *hero, map_t *map)
{
	sfVector2f move = { 0, -speed };

	if (y == 0 && map->colision[map->y - 1][map->x] == '0') {
		if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
			sfSprite_move(hero->sprite, move);
			y = y - speed;
			map->colision[map->y][map->x] = '0';
			map->colision[map->y - 1][map->x] = 'P';
		}
	}

	else if (y < 0 && y != -64) {
		sfSprite_move(hero->sprite, move);
		y = y - speed;
	}

	else if (y == -64) {
		y = 0;
	}
}

void key_down(hero_t *hero, map_t *map)
{
	sfVector2f move = { 0, speed };

	if (map->y == 15 && y == 0)
		return;
	if (y == 0 && map->colision[map->y + 1][map->x] == '0') {
		if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
			sfSprite_move(hero->sprite, move);
			y = y + speed;
			map->colision[map->y][map->x] = '0';
			map->colision[map->y + 1][map->x] = 'P';
		}
	}

	else if (y > 0 && y != 64) {
		sfSprite_move(hero->sprite, move);
		y = y + speed;
	}

	else if (y == 64) {
		y = 0;
	}
}

void move_control(hero_t *hero, map_t *map)
{
	for (int i = 0; map->colision[i] != NULL; i++) {
                for (int j = 0; j != map->lar; j++) {
                        if (map->colision[i][j] == 'P') {
			        map->x = j;
                                map->y = i;
                        }
	        }
        }
	if (y == 0) {
		key_right(hero, map);
		key_left(hero, map);
	}
	if (x == 0) {
		key_up(hero, map);
		key_down(hero, map);
	}
	anim_move(hero, x, y);
	hero->position = sfSprite_getPosition(hero->sprite);
}
