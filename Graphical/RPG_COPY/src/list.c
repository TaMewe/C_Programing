/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** C GRAPH PROG 2018
*/

#include "../include/my.h"
#include "../include/struct.h"

void add_to_hero_list(hero_t *list, hero_t *add, int type)
{
	add->type = type;
	add->next = NULL;
	
	while (list->next != NULL)
		list = list->next;
	list->next = add;	
}

hero_t take_to_hero_list(hero_t *list, int type)
{
	while (list->type != type)
		list = list->next;
	return (list);
}

void draw_hero_list(sfRenderWindow *window, hero_t *list)
{
	while (list->next != NULL) {
		sfRenderWindow_drawSprite(window, list->sprite, NULL);
		list = list->next;
	}
}
