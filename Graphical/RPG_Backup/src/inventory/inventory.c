/*
** EPITECH PROJECT, 2018
** inventory
** File description:
** inventory
*/

#include "rpg.h"

inv_t *take_to_inv(inv_t *list, int type)
{
	while (list->type != type)
		list = list->next;
	return (list);
}

inv_t *ini_button_inv(char *filepath, int type, sfVector2f vec)
{
	inv_t *inv = malloc(sizeof(inv_t));

	inv->type = type;
	inv->spr = sfSprite_create();
	inv->text = sfTexture_createFromFile(filepath, NULL);
	inv->rect = set_rect(0, 0, 79, 25);
	inv->vec = vec;
	inv->sca = set_vector(3, 3);
	sfSprite_setTexture(inv->spr, inv->text, sfTrue);
	sfSprite_setTextureRect(inv->spr, inv->rect);
	sfSprite_setPosition(inv->spr, inv->vec);
	sfSprite_setScale(inv->spr, inv->sca);
	inv->next = NULL;
	return (inv);
}

inv_t *ini_HUD_inv(void)
{
	inv_t *inv = malloc(sizeof(inv_t));

	inv->type = contour_hud;
	inv->spr = sfSprite_create();
	inv->text = sfTexture_createFromFile("Sprite/Inventory/Inventory.png", NULL);
	inv->rect = set_rect(0, 0, 640, 480);
	inv->vec = set_vector(480, 200);
	inv->sca = set_vector(1.5, 1.5);
	inv->next = NULL;
	sfSprite_setTexture(inv->spr, inv->text, sfTrue);
	sfSprite_setTextureRect(inv->spr, inv->rect);
	sfSprite_setPosition(inv->spr, inv->vec);
	sfSprite_setScale(inv->spr, inv->sca);
	return (inv);
}

inv_t *ini_inventory(void)
{
	inv_t *inv = ini_HUD_inv();
	inv_t *add = inv;
	sfVector2f vec = {550, 300};

	add->next = ini_button_inv("Sprite/Inventory/Item_Button.png", inv_item, vec);
	add = add->next;
	vec = set_vector(850, 300);
	add->next = ini_button_inv("Sprite/Inventory/Magic_Button.png", inv_magic, vec);
	add = add->next;
	vec = set_vector(550, 500);
	add->next = ini_button_inv("Sprite/Inventory/Stat_Button.png", inv_stat, vec);
	return (inv);
}

void draw_inv(sfRenderWindow *window, inv_t *inv)
{
	while (inv != NULL) {
		draw_sprite(window, inv->spr, 1);
		inv = inv->next;
	}
}
