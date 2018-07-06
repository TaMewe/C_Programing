/*
** EPITECH PROJECT, 2018
** map_specificities
** File description:
** map_specificities
*/

#include "rpg.h"

void first_map_spe(window_t window, object_t *object, const char **zone_1)
{
	(void)window;
	(void)object;
	(void)zone_1;
//	if (my_strcmp(object->map->map_1d, (char *)zone_1[0])) {
//		if (object->map->play == 0 && window.use == 1) {
//			sfMusic_play(object->map->Town);
//			object->map->play = 1;
//		}
//	}
//	else
//		sfMusic_stop(object->map->Town);
}

void second_map_spe(window_t window, object_t *object, const char **zone_2)
{
	(void)window;
	(void)object;
	(void)zone_2;
//	if (my_strcmp(object->map->map_1d, (char *)zone_2[0])) {
//	}
}

void third_map_spe(window_t window, object_t *object, const char **zone_t)
{
	sfVector2f vec;

	(void)window;
	if (my_strcmp(object->map->map_1d, (char *)zone_t[0])) {
		vec = sfSprite_getPosition(object->hero->sprite);
		if ((vec.x == 448 && vec.y == 384) || (vec.x == 448 && vec.y == 448)) {
			if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
				object->hero->hp[0] = object->hero->hp[1];
				object->hero->mp[0] = object->hero->mp[1];
			}
		}
	}
}
