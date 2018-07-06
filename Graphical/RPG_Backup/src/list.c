/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** C GRAPH PROG 2018
*/

#include "rpg.h"
 

void draw_button_list(sfRenderWindow *window, GUI_t *list)
{
	while (list != NULL) {
		sfRenderWindow_drawSprite(window, list->sprite, NULL);
		list = list->next;
	}
}
