/*
** EPITECH PROJECT, 2018
** map
** File description:
** map
*/

#include "../include/my.h"
#include "../include/struct.h"
#define mal 1000

char **alloc_map(char **map, const char *filepath)
{
	int fd = open(filepath, O_RDONLY);
	char *buffer = malloc(sizeof(char) * mal);
	int lon = 0;
	int lar	= 0;

	read(fd, buffer, mal);
	buffer[mal - 1] = '\0';
	for (int i = 0; (buffer[i] > 19 && buffer[i] < 123) || buffer[i] == '\n'; i++) {
		if (buffer[i] == '\n')
			lon++;
	}
	for (int i = 0; buffer[i] != '\n'; i++)
		lar++;
	map = malloc(sizeof(char *) * lon + 1);
	for (int i = 0; i != lon; i++) {
		map[i] = malloc(sizeof(char) * lar + 1);
		map[i][lar] = '\0';
	}
	map[lon] = NULL;
	free(buffer);
	close(fd);
	return (map);
}

int get_lar(const char *filepath)
{
	int fd = open(filepath, O_RDONLY);
	char *buffer = malloc(sizeof(char) * mal);
	int lar = 0;

	read(fd, buffer, mal);
	for (int i = 0; buffer[i] != '\n'; i++)
		lar++;
	free(buffer);
	close(fd);
	return (lar);
}

char **map_filling(const char *filepath)
{
	char **map = NULL;
	int fd = open(filepath, O_RDONLY);
	char *buffer = malloc(sizeof(char) * mal);
	int lar = get_lar(filepath);
	int k = 0;

	map = alloc_map(map, filepath);
	read(fd, buffer, mal);
	for (int i = 0; map[i] != NULL; i++, k++) {
		for (int j = 0; j != lar; j++, k++)
			map[i][j] = buffer[k];
	}
	free(buffer);
	close(fd);
	return (map);
}

void map_creation(map_t *map_s)
{
	static int only_after = 0;
	char *first = my_strcpy((char *)map_s->map_1d);
	char *second = my_strcpy((char *)map_s->map_2d);
	int lar = get_lar(first);
	int *axe = malloc(sizeof(int) * 2);
	int lon = 0;

	if (only_after > 0) {
		for (int i = 0; map_s->map_c[i] != NULL; i ++)
			lon++;
		for (int i = 0; i != lon; i++) {
			for(int j = 0; j != lar; j++) {
				sfSprite_destroy(map_s->blocks_1d[i][j]);
				sfSprite_destroy(map_s->blocks_2d[i][j]);
				sfTexture_destroy(map_s->text_tab[i][j]);
			}
			free(map_s->map_c[i]);
			free(map_s->map_d[i]);
		}
	}
	map_s->map_c = map_filling(first);
	map_s->map_d = map_filling(second);
	map_s->blocks_2d = alloc_item(map_s->map_d, second);
	map_s->blocks_1d = alloc_item(map_s->map_c, first);
	map_s->text_tab = alloc_text(map_s->map_c, first);
	for (int i = 0; map_s->map_c[i] != NULL; i++) {
		axe[0] = i;
		for (int j = 0; j != lar; j++) {
			axe[1] = j;
			fill_sprite(map_s->blocks_1d, map_s->map_c, axe, map_s->text_tab);
			fill_sprite_2(map_s->blocks_2d, map_s->map_d, axe, map_s->text_tab);
		}
	}
	map_s->lar = lar;
	text_fire(map_s);
	free(axe);
	free(first);
	free(second);
	only_after++;
	return ;
}

sfTexture ***alloc_text(char **map, const char *filepath)
{
	int lon = 0;
	int lar = get_lar(filepath);
	sfTexture ***item;

	for (int i = 0; map[i] != NULL; i++)
		lon++;
	item = malloc(sizeof(sfTexture**) * lon);
	for (int i = 0; i != lon; i++) {
		item[i] = malloc(sizeof(sfTexture *) * lar);
	}
	return (item);
}

sfSprite ***alloc_item(char **map, const char *filepath)
{
	int lon = 0;
	int lar = get_lar(filepath);
	sfSprite ***item;

	for (int i = 0; map[i] != NULL; i++)
		lon++;
	item = malloc(sizeof(sfSprite **) * lon);
	for (int i = 0; i != lon; i++) {
		item[i] = malloc(sizeof(sfSprite *) * lar);
		for(int j = 0; j != lar; j++) {
			item[i][j] = sfSprite_create();
		}
	}
	return (item);
}
