/*
** EPITECH PROJECT, 2018
** interface
** File description:
** interface
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>
#include <stdlib.h>
#include "../my.h"

char **create_interface()
{
	char **interface = malloc(sizeof(char *) * 23);

	interface[22] = NULL;
	interface[0] = my_strcpy("* * * * * * * * * * * * * * * * +---------------------+ /-next----\\");
	interface[1] = my_strcpy("  *   *       *   *   *   *     |                     | |         |");
	interface[2] = my_strcpy("  *   * *     *   * *   * * * * |                     | |         |");
	interface[3] = my_strcpy("  *   *       *   *   * *     * |                     | \\---------/");
	interface[4] = my_strcpy("  *   * * *   *   *   * * * * * |                     |            ");
	interface[5] = my_strcpy("                                |                     |             ");
	interface[6] = my_strcpy("                                |                     |             ");
	interface = interface_second_part(interface);
	return (interface);
}

char **interface_second_part(char **interface)
{
	interface[7] = my_strcpy("/---------------------------\\   |                     |             ");
	interface[8] = my_strcpy("|                           |   |                     |             ");
	interface[9] = my_strcpy("| High Score                |   |                     |             ");
	interface[10] = my_strcpy("| Score                     |   |                     |             ");
	interface[11] = my_strcpy("|                           |   |                     |             ");
	interface[12] = my_strcpy("| Lines                     |   |                     |             ");
	interface[13] = my_strcpy("| Level                     |   |                     |             ");
	interface[14] = my_strcpy("|                           |   |                     |             ");
	interface[15] = my_strcpy("| Timer                     |   |                     |             ");
	interface[16] = my_strcpy("|                           |   |                     |             ");
	interface[17] = my_strcpy("\\---------------------------/   |                     |             ");
	interface[18] = my_strcpy("                                |                     |             ");
	interface[19] = my_strcpy("                                |                     |             ");
	interface[20] = my_strcpy("                                |                     |             ");
	interface[21] = my_strcpy("                                +---------------------+             ");
	return (interface);
}
