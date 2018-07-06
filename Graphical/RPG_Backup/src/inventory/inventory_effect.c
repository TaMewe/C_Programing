/*
** EPITECH PROJECT, 2018
** inventory_effect
** File description:
** inventory_effect
*/

#include "rpg.h"

void wood_background_moving(sfRenderWindow *window, inv_t *inv)
{
	static sfSprite *bg = NULL;
	static sfTexture *text = NULL;
	static int only_one = 0;
	sfVector2f move = {0, -0.5};
	sfVector2f start = {0, 0};

	(void)inv;
	if (bg == NULL)
		bg = sfSprite_create();
	if (text == NULL)
		text = sfTexture_createFromFile("Sprite/Parallax/bg_inv.png", NULL);
	if (only_one == 0)
		sfSprite_setTexture(bg, text, sfTrue);
	draw_sprite(window, bg, 1);
	if (sfSprite_getPosition(bg).y > -1080)
		sfSprite_move(bg, move);
	else
		sfSprite_setPosition(bg, start);
	only_one++;
}

sfIntRect set_hitbox(inv_t *inv)
{
	sfIntRect rect;

	rect.width = inv->rect.width * inv->sca.x;
	rect.height = inv->rect.height * inv->sca.y;
	rect.top = inv->vec.y;
	rect.left = inv->vec.x;
	return (rect);
}

int button_sca(sfRenderWindow *window, inv_t *button, int type)
{
	sfVector2f scale = {3.5, 3.5};
	sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
	sfIntRect area;

	button = take_to_inv(button, type);
	area = set_hitbox(button);
	if (sfIntRect_contains(&area, mouse.x, mouse.y) == sfTrue) {
		sfSprite_setScale(button->spr, scale);
		return (1);
	}
	sfSprite_setScale(button->spr, button->sca);
	return (0);
}

void apply_sca(sfRenderWindow *window, inv_t *inv)
{
	button_sca(window, inv, inv_item);
	button_sca(window, inv, inv_magic);
	button_sca(window, inv, inv_stat);
}
