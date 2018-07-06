/*
** EPITECH PROJECT, 2018
** map_alloc
** File description:
** map_alloc
*/

#include "rpg.h"
#include "struct.h"
#define mal 528

void free_old_text(map_t *map, int lar)
{
	for (int i = 0; map->map_c[i] != NULL; i++) {
		for (int j = 0; j != lar; j++) {
			sfTexture_destroy(map->rem_text[i][j]);
			sfTexture_destroy(map->for_text[i][j]);
		}
	}
}

void keep_other_address(map_t *map, int lar)
{
	for (int i = 0; map->map_c[i] != NULL; i++) {
		for (int j = 0; j != lar; j++) {
			map->for_text[i][j] = map->text_tab[i][j];
		}
	}
}

void keep_text_address(map_t *map, int lar)
{
	for (int i = 0; map->map_c[i] != NULL; i++) {
		for (int j = 0; j != lar; j++) {
			map->rem_text[i][j] = map->text_tab[i][j];
		}
	}
}

sfTexture ***alloc_text(char **map, const char *filepath, sfTexture ***item)
{
	int lon = 0;
	int lar = get_lar(filepath);

	for (int i = 0; map[i] != NULL; i++)
		lon++;
	item = malloc(sizeof(sfTexture**) * lon + 1);
	for (int i = 0; i != lon; i++) {
		item[i] = malloc(sizeof(sfTexture *) * lar);
	}
	return (item);
}

sfSprite ***alloc_item(char **map, const char *filepath, sfSprite ***item)
{
	int lon = 0;
	int lar = get_lar(filepath);

	for (int i = 0; map[i] != NULL; i++)
		lon++;
	item = malloc(sizeof(sfSprite **) * lon + 1);
	for (int i = 0; i != lon; i++) {
		item[i] = malloc(sizeof(sfSprite *) * lar);
		for(int j = 0; j != lar; j++) {
			item[i][j] = sfSprite_create();
		}
	}
	return (item);
}
