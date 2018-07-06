/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** C GRAPH PROG
*/

#include "rpg.h"

GUI_t *create_button(char *filepath1, char *filepath2, sfVector2f position)
{
	GUI_t *button = malloc(sizeof(GUI_t));
	sfVector2f origin;

	button->type = button_type;
	button->sprite = sfSprite_create();
	button->texture = sfTexture_createFromFile(filepath1, NULL);
	button->survol = sfTexture_createFromFile(filepath2, NULL);
	button->rect = set_rect(0, 0, 62, 26);
	button->position = position;
	origin = set_vector(button->rect.width / 2, button->rect.height / 2);
	button->scale = set_vector(3, 3);
	sfSprite_setTexture(button->sprite, button->texture, sfTrue);
	sfSprite_setTextureRect(button->sprite, button->rect);
	sfSprite_setPosition(button->sprite, button->position);
	sfSprite_setScale(button->sprite, button->scale);
	sfSprite_setOrigin(button->sprite, origin);
	button->next = NULL;
	return (button);
}

int survol_button(sfRenderWindow *window, GUI_t *button)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
	sfIntRect area;

	while (button != NULL) {
		if (button->type == button_type) {
			area = set_area(button);
			if (sfIntRect_contains(&area, mouse.x, mouse.y) == sfTrue)
				sfSprite_setTexture(button->sprite, button->survol, sfTrue);
			else 
				sfSprite_setTexture(button->sprite, button->texture, sfTrue);
		}
		button = button->next;
	}
	return (0);
}


GUI_t *ini_fight_HUD()
{
	GUI_t *HUD = malloc(sizeof(GUI_t));

	HUD->type = HUD_type;
	HUD->button = -1;
	HUD->sprite = sfSprite_create();
	HUD->texture = sfTexture_createFromFile("Sprite/fight_screen/HUD_fight.png", NULL);
	HUD->rect = set_rect(0, 0, 542, 415);
	HUD->position = set_vector(0, 665);
	HUD->scale = set_vector(1, 1);
	sfSprite_setTexture(HUD->sprite, HUD->texture, sfTrue);
	sfSprite_setTextureRect(HUD->sprite, HUD->rect);
	sfSprite_setPosition(HUD->sprite, HUD->position);
	sfSprite_setScale(HUD->sprite, HUD->scale);
	HUD->next = NULL;
	return (HUD);
}

GUI_t *ini_button_list()
{
	GUI_t *HUD = ini_fight_HUD();
	GUI_t *add = HUD;
	sfVector2f pos = { 145, 755 };

	add->next = create_button("Sprite/fight_screen/attack.png",
				  "Sprite/fight_screen/shining_attack.png", pos);
	add->next->button = button_attack;
	add = add->next;
	pos = set_vector(395, 755);
	add->next = create_button("Sprite/fight_screen/guard.png",
				  "Sprite/fight_screen/shining_guard.png", pos);
	add->next->button = button_guard;
	pos = set_vector(145, 875);
	add = add->next;
	add->next = create_button("Sprite/fight_screen/magic.png",
				  "Sprite/fight_screen/shining_magic.png", pos);
	add->next->button = button_magic;
	pos = set_vector(395, 875);
	add = add->next;
	add->next = create_button("Sprite/fight_screen/item.png",
				  "Sprite/fight_screen/shining_item.png", pos);
	add->next->button = button_item;
	pos = set_vector(270, 995);
	add = add->next;
	add->next = create_button("Sprite/fight_screen/flee.png",
				  "Sprite/fight_screen/shining_flee.png", pos);
	add->next->button = button_flee;
	return (HUD);
}
