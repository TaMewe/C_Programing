/*
** EPITECH PROJECT, 2018
** Animation of the movement
** File description:
** Animation of principal character
*/
#include "rpg.h"

void anim_right(hero_t *hero, int x)
{
	if (x > 0) {
		hero->rect.top = 64;
		if (x % 24 == 0) {
			hero->rect.left += 32;
			if (hero->rect.left == 225)
				hero->rect.left += 32;
			if (hero->rect.left == 289)
				hero->rect.left = 193;
		}
	}
}

void anim_left(hero_t *hero, int x)
{
	if (x < 0) {
		hero->rect.top = 32;
		if (x % 24 == 0) {
			hero->rect.left += 32;
			if (hero->rect.left == 225)
				hero->rect.left += 32;
			if (hero->rect.left == 289)
				hero->rect.left = 193;
		}
	}
}

void anim_up(hero_t *hero, int y)
{
	if (y < 0) {
		hero->rect.top = 96;
		if (y % 24 == 0) {
			hero->rect.left += 32;
			if (hero->rect.left == 225)
				hero->rect.left += 32;
			if (hero->rect.left == 289)
				hero->rect.left = 193;
		}
	}
}

void anim_down(hero_t *hero, int y)
{
	if (y > 0) {
		hero->rect.top = 0; 
		if (y % 24 == 0) {
			hero->rect.left += 32;
			if (hero->rect.left == 225)
				hero->rect.left += 32;
			if (hero->rect.left == 289)
				hero->rect.left = 193;
		}
	}
}

void anim_move(hero_t *hero, int x, int y)
{
	anim_left(hero, x);
	anim_right(hero, x);
	anim_up(hero, y);
	anim_down(hero, y);
	if (x == 0 && y == 0)
		hero->rect.left = 225;
	sfSprite_setTextureRect(hero->sprite, hero->rect);
}
