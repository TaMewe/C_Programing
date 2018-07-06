##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

NAME    =       tetris

SRC	=	src/tetris.c	\
		src/interface.c	\
		src/put_form.c	\
		lib/my/my_putchar.c	\
                lib/my/my_strlen.c	\
                lib/my/my_putstr.c	\
                lib/my/my_getnbr.c	\
		lib/my/my_put_nbr.c	\
		lib/my/get_next_line.c	\
		lib/my/my_strcpy.c	\

OBJS	=	$(SRC:.c=.o)

UNIT	=	-lcriterion --coverage

all: $(NAME)

$(NAME): $(OBJS)
	cp lib/my/my.h .
	gcc -g3 $(OBJS) -o $(NAME) -lncurses
	rm -rf $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all compile clean fclean re
