/*
** EPITECH PROJECT, 2018
** damage_string
** File description:
** damage_string
*/

#include "rpg.h"

int rand_attack(hero_t *hero, mob_t *mob)
{
	int ran = rand() % 3;
	int att = (hero->stat->atk_p - 1) + ran;
	int miss = rand() % 10;
	int crit = rand() % 10;
	(void) mob;

	if (miss == 0)
		att = 0;
	if (crit == 0)
		att += hero->stat->atk_p;
	return (att);
}

char *my_strcat(char *first, char *next)
{
	char *fin = malloc(sizeof(char) * (my_strlen(first) + my_strlen(next) + 1));
	int i = 0;

	for (int j = 0; first[j] != '\0'; j++, i++)
		fin[i] = first[j];
	for (int j = 0; next[j] != '\0'; j++, i++)
		fin[i] = next[j];
	fin[i] = '\0';
	return (fin);
}

char *damage_string(int att, hero_t *hero, mob_t *mob)
{
	char *str = my_strcpy("You dealt ");
	char *number = my_get_str_nbr(att);
	char *end = my_strcpy(" damages!");
	char *critical = my_strcpy("\nCRITICAL HIT!");
	char *fin;
	char *fight_end = my_strcpy("\nFight ended. Right click to continue");

	fin = my_strcat(str, number);
	fin = my_strcat(fin, end);
	if (att > (hero->stat->atk_p + 2))
		fin = my_strcat(fin, critical);
	if (mob->hp[0] == 0)
		fin = my_strcat(fin, fight_end);
	free(str);
	free(number);
	free(end);
	free(critical);
	free(fight_end);
	if (att == 0)
		fin = my_strcpy("You missed!");
	return (fin);
}

char *damage_mob(int att, hero_t *hero, mob_t *mob)
{
	char *str = my_strcpy("Enemy dealt ");
	char *number = my_get_str_nbr(att);
	char *end = my_strcpy(" damages!");
	char *critical = my_strcpy("\nCRITICAL HIT!");
	char *fin;
	char *fight_end = my_strcpy("\nGame Over! You Died.");

	fin = my_strcat(str, number);
	fin = my_strcat(fin, end);
	if (att > mob->stat->atk_p + 2)
		fin = my_strcat(fin, critical);
	if (hero->hp[0] == 0)
		fin = my_strcat(fin, fight_end);
	free(str);
	free(number);
	free(end);
	free(critical);
	free(fight_end);
	if (att == 0)
		fin = my_strcpy("Enemy missed!");
	return (fin);
}
