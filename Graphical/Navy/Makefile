##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

NAME    =       rpg

SRC	=	

OBJS	=	$(SRC:.c=.o)

FLAG	+=	-lcriterion --coverage -i Include -g3 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm src/*~
	rm src/*#

re: fclean all

.PHONY: all compile clean fclean re
