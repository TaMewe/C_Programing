##
## EPITECH PROJECT, 2018
## my_rpg_2017
## File description:
## Makefile
##

NAME    =	lem_in

SRC	=	src/main.c	\
		lib/my/my_strcpy.c	\
		lib/my/my_strlen.c	\
		lib/my/my_strcmp.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_put_nbr.c	\
		lib/my/realloc.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_revstr.c	\
		lib/my/get_next_line.c

OBJS	=	$(SRC:.c=.o)

FLAG	+=	-Iinclude -Wall -Wextra -Werror -g3

all:		$(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME)
	rm -rf src/*~
	rm -rf src/*#

re: fclean all

.PHONY: all clean fclean re
