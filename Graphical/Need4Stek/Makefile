##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME    =       ai

SRC	=	src/main.c	\
		src/str_to_word_array.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_strlen.c	\
		lib/my/my_strcpy.c	\
		lib/my/my_strcmp.c	\
		lib/my/my_puterr.c	\
		lib/my/my_revstr.c

OBJS	=	$(SRC:.c=.o)

FLAG	+=	-Iinclude -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf src/*~
	rm -rf src/*#

fclean:
	rm -rf $(NAME)
	rm -rf src/*~
	rm -rf src/*#

re: fclean all clean

.PHONY: all clean fclean re
