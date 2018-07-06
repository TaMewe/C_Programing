/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** C GRAPH PROG
*/

#include "rpg.h"

int event_close_window(sfRenderWindow *window, sfEvent event)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(window);
	return (0);
}

int event_key_pressed(window_t window, sfEvent event, object_t *object)
{
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
		if (object->pause == 0) {
			if (free_mode(window, object) == 1)
				object->pause = 1;
		}
		else
			object->pause = 0;
	}
	key_pressed(event, object->map, object->hero);
	return (0);
}

int event_click(window_t window, sfEvent event, object_t *object, GUI_t *HUD)
{
	if (event.type == sfEvtMouseButtonPressed &&
	    sfMouse_isButtonPressed(sfMouseLeft) == sfTrue &&
	    object->mob->hp[0] != 0) {
		function_attack(window, object->hero, object->mob, HUD);
	}
	return (0);
}
