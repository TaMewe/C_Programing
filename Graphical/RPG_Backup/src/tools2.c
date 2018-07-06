/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** C GRAPH PROG
*/

#include "rpg.h"

sfIntRect set_area(GUI_t *object)
{
	sfIntRect area;
	int width = object->rect.width * object->scale.x;
	int height = object->rect.height * object->scale.y;

	area.top = sfSprite_getPosition(object->sprite).y - height / 2;
	area.left = sfSprite_getPosition(object->sprite).x - width / 2;
	area.height = height;
	area.width = width;
	return (area);
}

object_t *ini_object()
{
	object_t *object = malloc(sizeof(object_t));
	
	object->map = ini_map();
	object->hero = ini_hero("Sprite/hero_spritesheet1.png");
	object->mob = ini_mob();
	object->menu = malloc(sizeof(menu_t));
	object->inv = ini_inventory();
	ini_menu(object->menu);
	return (object);
}

int check_button(sfRenderWindow *window, GUI_t *HUD, int button)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
	sfIntRect area;
	
	HUD = take_to_gui_list(HUD, button);
	area = set_area(HUD);
	if (sfIntRect_contains(&area, mouse.x, mouse.y) == sfTrue)
		return (1);
	return (0);
}

sfIntRect part_jauge(sfIntRect rect, int *percent)
{
	sfIntRect part = rect;

	part.width = rect.width * percent[0] / percent[1];
	return (part);
}

void set_text(sfText *text, char *str, sfVector2f pos, sfColor color)
{
	sfText_setString(text, str);
	sfText_setColor(text, color);
	sfText_setPosition(text, pos);
}
