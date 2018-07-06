/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** C GRAPH PROG
*/

#include "rpg.h"

GUI_t *take_to_gui_list(GUI_t *list, int button)
{
	while (list->button != button)
		list = list->next;
	return (list);
}
