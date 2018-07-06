/*
** EPITECH PROJECT, 2018
** ini_sprite.c
** File description:
** LORIS
*/

#include "rpg.h"

sfTexture *ini_tex(char *str)
{
	sfTexture *t = sfTexture_createFromFile(str, NULL);
	
	if (t == NULL) {
		my_puterror("ERROR: failed to load ");
		my_puterror(str);
		my_puterror("\n");
		return (NULL);		
	}
	return (t);
}

sfIntRect ini_rect(int top, int left, int width, int height)
{
	sfIntRect r = {top, left, width, height};

	return (r);
}

sfSprite *ini_sprite(sfTexture *path, sfVector2f pos, sfVector2f sca, sfVector2f o)
{
	sfSprite *sprite = sfSprite_create();

	sfSprite_setTexture(sprite, path, sfTrue);
	sfSprite_setPosition(sprite, pos);
	sfSprite_setScale(sprite, sca);
	sfSprite_setOrigin(sprite, o);
	return (sprite);
}
