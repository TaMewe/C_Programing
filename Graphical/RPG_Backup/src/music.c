/*
** EPITECH PROJECT, 2018
** music
** File description:
** music
*/

#include "rpg.h"

void stop_map_music(object_t *object)
{
	object->map->play = 0;
	sfMusic_stop(object->map->Town);
}
